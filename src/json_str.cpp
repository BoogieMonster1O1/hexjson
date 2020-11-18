#include "json_element.cpp"
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
};
