#include "element.h"
#include "flags.c"

class json_bool : public json_element {
private:
    bool value;

public:
    explicit json_bool(bool value) {
        this -> value = value;
    }

    int get_type() override {
        return g_json_bool;
    }

    [[nodiscard]] bool get_value() const {
        return this -> value;
    }
};
