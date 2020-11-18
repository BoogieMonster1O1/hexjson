#include "json_element.cpp"
#include "types.c"

class json_bool : public json_element {
private:
    bool value;

public:
    explicit json_bool(bool value) {
        this -> value = value;
    }

    int get_type() override {
        return JSON_BOOL;
    }

    [[nodiscard]] bool get_value() const {
        return this -> value;
    }
};
