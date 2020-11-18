#include "element.h"
#include "flags.c"
#include <map>

using namespace std;

class json_object : public json_element {
private:
    map<string, json_element*> map = ::map<string, json_element*>();

public:
    json_object() = default;
    ~json_object() {
        map.clear();
        free(&map);
    }

    int get_type() override {
        return g_json_object;
    }

    ::map<string, json_element*> kvmap() {
        return this -> map;
    }
};
