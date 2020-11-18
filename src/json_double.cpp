#include "json_element.cpp"
#include "json_type.c"

class json_double : json_element {
private:
    double value;

public:
    explicit json_double(double value) {
        this -> value = value;
    }

    int get_type() override {
        return JSON_DOUBLE;
    }

    [[nodiscard]] double get_value() const {
        return this -> value;
    }
};
