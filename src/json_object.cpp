#include "json_element.cpp"
#include "types.c"
#include <map>

using namespace std;

class json_object : public json_element {
private:
    map<string, json_element> map = ::map<string, json_element>();

public:
    json_object() = default;
    ~json_object() {
        map.clear();
    }

    int get_type() override {
        return JSON_OBJECT;
    }

    ::map<string, json_element> get_map() {
        return this -> map;
    }
};
