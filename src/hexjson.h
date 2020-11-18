#ifndef HEXJSON_HEXJSON_H
#define HEXJSON_HEXJSON_H

#include "json_int.cpp"
#include "json_bool.cpp"
#include "json_double.cpp"
#include "json_null.cpp"
#include "json_object.cpp"
#include <string>
#include <iostream>
#include "scopes.c"
#include <list>

using namespace std;

class json_reader {
private:
    string input;

public:
    explicit json_reader(const string& value) { // NOLINT(cppcoreguidelines-pro-type-member-init)
        this -> input = value;
    }
};

json_int value_of(int i) {
    return json_int(i);
}

json_bool value_of(bool b) {
    return json_bool(b);
}

json_double value_of(double d) {
    return json_double(d);
}

json_null null() {
    return json_null_instance;
}

json_object read(const string& value) {
    return json_reader(value);
}

#endif
