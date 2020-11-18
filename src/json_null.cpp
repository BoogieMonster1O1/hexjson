#include "element.h"
#include "flags.c"

class json_null : public json_element {

public:
    int get_type() override {
        return g_json_null;
    }

    json_null() = default;
};

static const json_null json_null_instance = json_null();
