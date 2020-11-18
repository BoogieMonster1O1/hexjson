#include "json_element.cpp"
#include "types.c"

class json_null : public json_element {

public:
    int get_type() override {
        return JSON_NULL;
    }

    json_null() = default;
};

static const json_null json_null_instance = json_null();
