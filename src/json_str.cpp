#include "element.h"
#include "flags.c"
#include <string>

using namespace std;

class json_str : public json_element {
private:
    string value;

public:
    explicit json_str(string& value) {
        this -> value = value;
    }

    int get_type() override {
        return g_json_str;
    }

    string str_value() {
        return this -> value;
    }

    json_str operator+ (json_str& other) {
        string newStr = this -> str_value() + other.str_value();
        return json_str(newStr);
    }

    char operator[] (int index) {
        return this -> str_value()[index];
    }
};
