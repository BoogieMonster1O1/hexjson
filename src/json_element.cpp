#include <iostream>

class json_element {
public:
    virtual int get_type() {
        throw std::runtime_error("not implemented");
    }
};
