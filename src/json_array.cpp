#include "element.h"
#include "flags.c"
#include <vector>

using namespace std;

class json_array : public json_element {
private:
    vector<json_element *> values = vector<json_element *>();

public:
    json_array() = default;
    ~json_array() {
        values.clear();
        free(&values);
    }

    int get_type() override {
        return g_json_array;
    }

    vector<json_element *> * vlist() {
        return &values;
    }
};
