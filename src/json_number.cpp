#include "element.h"
#include "flags.c"

class json_number : public json_element {
private:
    double value;

public:
    explicit json_number(double value) {
        this -> value = value;
    }

    int get_type() override {
        return g_json_number;
    }

    [[nodiscard]] double double_value() const {
        return this -> value;
    }

    [[nodiscard]] int int_value() const {
        return (int) (this -> value);
    }
};
