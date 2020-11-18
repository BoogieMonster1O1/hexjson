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
        return g_json_double;
    }

    [[nodiscard]] double get_value() const {
        return this -> value;
    }
};
