#include "json_element.cpp"
#include "types.c"

class json_int : public json_element {
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
