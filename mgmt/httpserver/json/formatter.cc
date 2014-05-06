/*
 * Copyright (C) 2014 Cloudius Systems, Ltd.
 *
 * This work is open source software, licensed under the terms of the
 * BSD license as described in the LICENSE file in the top-level directory.
 */

#include "formatter.hh"

using namespace std;

namespace httpserver {

namespace json {

string formatter::to_json(const string& str)
{
    return '"' + str + '"';
}

string formatter::to_json(const char* str)
{
    string res = "\"";
    res += str;
    return res + '"';
}

string formatter::to_json(int n)
{
    return to_string(n);
}

string formatter::to_json(long n)
{
    return to_string(n);
}

string formatter::to_json(bool b)
{
    return (b) ? "True" : "False";
}

string formatter::to_json(const date_time& d)
{
    char buff[50];
    string res = "\"";
    strftime(buff, 50, TIME_FORMAT, &d);
    res += buff;
    return res + "\"";
}

}
}
