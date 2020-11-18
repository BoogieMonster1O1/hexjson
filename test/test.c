#include "../src/hexjson.h"

int main() {
    json_str jsonStr = str_value_of("hello");
    printf("%s%s", jsonStr.str_value().c_str(), "\n");
    return 0;
}
