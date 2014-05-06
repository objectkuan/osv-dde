//#include <algorithm>
#include "elf.hh"
#include <jni.h>
#include <stdlib.h>
#include <string.h>

extern elf::program* prog;

bool run_elf(int argc, char** argv, int *return_code)
{
    if (argc <= 0) {
        return (false);
    }

    auto obj = prog->add_object(argv[0]);
    if (!obj) {
        return (false);
    }

    auto main = obj->lookup<int (int, char**)>("main");
    if (!main) {
       return (false);
    }

    int rc = main(argc, argv);

    /* cleanups */
    prog->remove_object(argv[0]);

    /* set the return code */
    if (return_code) {
        *return_code = rc;
    }

    return (true);
}

static jint throwIOException(JNIEnv *env, const char *message)
{
    jclass cls = env->FindClass("java/io/IOException");
    // TODO: do something if !cls ?
    return env->ThrowNew(cls, message);
}

extern "C" JNIEXPORT jint JNICALL Java_com_cloudius_util_Exec_run
  (JNIEnv *env, jclass self, jobjectArray jargv)
{
    int argc = env->GetArrayLength(jargv);
    if (argc <= 0) {
        throwIOException(env, "no command given");
    }

    char **argv = (char**) malloc(argc * sizeof(char*));

    for (int i=0; i<argc; i++) {
        jstring string = (jstring)env->GetObjectArrayElement(jargv, i);
        const char *c_utf = env->GetStringUTFChars(string, 0);
        argv[i] = strdup(c_utf);
        env->ReleaseStringUTFChars(string, c_utf);
    }

    int rc;
    bool success = run_elf(argc, argv, &rc);

    // free argv
    for (int i=0; i<argc; i++) {
        free(argv[i]);
    }
    free(argv);

    if (!success) {
        throwIOException(env, "couldn't run command");
    }

    return rc;
}
