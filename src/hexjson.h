#ifndef HEXJSON_HEXJSON_H
#define HEXJSON_HEXJSON_H

#include "json_str.cpp"
#include "json_bool.cpp"
#include "json_number.cpp"
#include "json_null.cpp"
#include "json_object.cpp"
#include "sutils.cpp"
#include "deserializer.cpp"
#include <string>
#include <iostream>
#include <list>

using namespace std;

json_str value_of(string& str) {
    return json_str(str);
}

json_bool value_of(bool b) {
    return json_bool(b);
}

json_number value_of(double d) {
    return json_number(d);
}

json_null null() {
    return json_null_instance;
}

json_object read(const string& value) {
    return json_reader(value);
}

#endif
