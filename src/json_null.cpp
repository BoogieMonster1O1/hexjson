#include "json_element.cpp"
#include "json_type.c"

class json_null : json_element {

public:
    int get_type() override {
        return JSON_NULL;
    }

    json_null() = default;
};

static const json_null json_null_instance = json_null();
