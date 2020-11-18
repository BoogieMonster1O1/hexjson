#include "json_element.cpp"
#include "json_type.c"

class json_int : json_element {
private:
    int value;

public:
    explicit json_int(int value) {
        this -> value = value;
    }

    int get_type() override {
        return JSON_INT;
    }

    [[nodiscard]] int get_value() const {
        return this -> value;
    }
};
