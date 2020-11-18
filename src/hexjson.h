#ifndef HEXJSON_HEXJSON_H
#define HEXJSON_HEXJSON_H

#include "sutils.h"
#include "deserializer.cpp"
#include <string>
#include <iostream>

using namespace std;

json_str str_value_of(string str) {
    return json_str(str);
}

json_bool bool_value_of(bool b) {
    return json_bool(b);
}

json_number double_value_of(double d) {
    return json_number(d);
}

json_null null() {
    return json_null_instance;
}

json_object read(string value) {
    return json_deserializer(value).deserialize();
}

#endif
