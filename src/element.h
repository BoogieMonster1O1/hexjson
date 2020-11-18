#ifndef HEXJSON_ELEMENT_H
#define HEXJSON_ELEMENT_H

#include <iostream>

class json_element {
public:
    virtual int get_type() = 0;
};

#endif
