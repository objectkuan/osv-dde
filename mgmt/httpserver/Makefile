# compiler flags:
#  -g    adds debugging information to the executable file
#  -Wall turns on most, but not all, compiler warnings
CXXFLAGS  = -g -Wall -std=c++11 -fPIC -I../../include -I.

# the build target executable:
TARGET = httpserver
CPP_FILES := $(wildcard *.cc) $(wildcard json/*.cc) $(wildcard api/*.cc)
STUB_CPP_FILES := $(wildcard stub/*.cc)
OBJ_FILES := $(addprefix obj/,$(CPP_FILES:.cc=.o))
STUB_FILES := $(addprefix obj/,$(STUB_CPP_FILES:.cc=.o))

LIBS = -lpthread -lboost_system -lboost_filesystem -lboost_program_options

quiet = $(if $V, $1, @echo " $2"; $1)
very-quiet = $(if $V, $1, @$1)

all: init $(TARGET) $(TARGET).so

init:
	$(call very-quiet, mkdir -p obj)
	$(call very-quiet, mkdir -p obj/stub)
	$(call very-quiet, mkdir -p obj/json)
	$(call very-quiet, mkdir -p obj/api)

$(TARGET): $(OBJ_FILES) $(STUB_FILES)
	$(call quiet, $(CXX) $(CXXFLAGS) -o $(TARGET) $^ $(LIBS), LINK $@)

$(TARGET).so: $(OBJ_FILES)
	$(call quiet, $(CXX) $(CXXFLAGS) -shared -o $(TARGET).so $^ $(LIBS), LINK $@)

obj/%.o: %.cc
	$(call quiet, $(CXX) $(CXXFLAGS) -c -o $@ $<, CXX $@)

clean:
	$(call quiet, $(RM) $(TARGET), CLEAN)
	$(call very-quiet, $(RM) $(TARGET).so)
	$(call very-quiet, $(RM) -rf obj/*)
