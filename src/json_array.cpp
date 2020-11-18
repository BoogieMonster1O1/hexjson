#include "json_element.cpp"
#include "flags.c"
#include <vector>

using namespace std;

class json_array : public json_element {
private:
    vector<unique_ptr<json_element>> values = vector<unique_ptr<json_element>>();

public:
    json_array() = default;
    ~json_array() {
        values.clear();
        free(&values);
    }

    int get_type() override {
        return g_json_array;
    }

    vector<unique_ptr<json_element>>* vlist() {
        return &values;
    }
};
