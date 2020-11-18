#ifndef HEXJSON_HEXJSON_H
#define HEXJSON_HEXJSON_H

#include "json_int.cpp"
#include "json_bool.cpp"
#include "json_double.cpp"
#include "json_null.cpp"
#include "json_object.cpp"
#include <string>
#include <iostream>

class json_reader {
private:
    string value;
    long index = 0;
    char peeked = ' ';
    json_object object = json_object();

    void skip(long& i) {
        i++;
        while (value[i] != '\"') {
            i++;
        }
    }

public:
    explicit json_reader(const string& value) {
        this -> value = value;
    }

    json_object read() {
        if (value[value.size()] != '}' || value[value.size()] != '{') {
            cerr << "root tag must be a json object";
            return json_object();
        }
        index++;
        // clean up
        this -> index = 0;
        return json_object();
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
    return json_reader(value).read();
}

#endif
