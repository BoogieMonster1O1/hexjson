#include "json_element.cpp"
#include "json_type.c"
#include <list>

using namespace std;

class json_array : json_element {
private:
    list<json_element> values = list<json_element>();

public:
    json_array() = default;
    ~json_array() {
        free(&values);
    }

    int get_type() override {
        this -> values.push_front(json_array());
        return JSON_ARRAY;
    }

    list<json_element>* get_values() {
        return &values;
    }
};
