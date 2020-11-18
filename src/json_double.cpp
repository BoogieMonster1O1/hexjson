#include "json_element.cpp"
#include "types.c"

class json_double : public json_element {
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
