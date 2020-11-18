#include "../src/hexjson.h"

using namespace std;

int main() {
    json_str jsonStr = str_value_of("hello");
    cout << jsonStr.str_value() << endl;
    free(&jsonStr);
}
