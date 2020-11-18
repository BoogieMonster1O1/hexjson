#include <string>
#include <algorithm>
#include "json_object.cpp"
#include "json_array.cpp"
#include "json_number.cpp"
#include "json_bool.cpp"
#include "json_null.cpp"
#include "json_str.cpp"
#include "token_c.c"
#include "token_o.c"
#include "sutils.cpp"

using namespace std;

class json_deserializer {
private:
    class json_reader {
    private:
        int index = 0;

    public:
        string cbuf;

        explicit json_reader(const string& value) {
            cbuf = trim(value);
        }

        char read() {
            char res = ' ';
            if (cbuf.length() != 0) {
                res = cbuf[index];
            }
            if ((index + 1) < cbuf.length()) {
                index++;
            } else {
                index = 0;
            }
            return res;
        }

        char back() {
            if ((index - 1) >= 0) {
                index--;
            } else {
                index = 0;
            }
            return current();
        }

        char current() {
            return cbuf[index];
        }

        bool next() {
            if ((index + 1) >= cbuf.length()) {
                return false;
            } else {
                index++;
                return true;
            }
        }

        char read_prev() {
            if ((index - 1) >= 0 && index < cbuf.length()) {
                return cbuf[index - 1];
            }
            return ' ';
        }
    };

    json_reader reader;

    int current_deserialization_type() {
        char current = reader.current();
        if (current == opening_object) {
            return g_json_object;
        } else if (current == opening_array) {
            return g_json_array;
        } else if (current == opening_str) {
            return g_json_str;
        } else if (isdigit(current) || current == opening_plus || current == opening_minus || current == opening_dot) {
            return g_json_number;
        } else if (current == opening_null_lower || current == opening_null_upper) {
            return g_json_null;
        } else if (current == opening_true_lower || current == opening_true_upper) {
            return g_json_bool | g_json_true;
        } else if (current == opening_false_lower || current == opening_false_upper) {
            return g_json_bool | g_json_false;
        }
        return -1;
    }

    bool is_opener(char ch) {
        if (reader.read_prev() == '\\') {
            return false;
        } else if (ch == opening_object || ch == opening_array || ch == opening_str || ch == opening_plus || ch == opening_minus || ch == opening_dot || ch == opening_null_lower || ch == opening_null_upper || ch == opening_true_lower || ch == opening_true_upper || ch == opening_false_lower || ch == opening_false_upper) {
            return true;
        }
        return false;
    }

    bool is_closer(char ch) {
        if (reader.read_prev() == '\\') {
            return false;
        } else if (ch == closing_object || ch == closing_array || ch == closing_str) {
            return true;
        }
        return false;
    }

    json_bool deserialize_bool_true() {
        string str;
        str += reader.current();
        int i = 1;
        while (i < 4) {
            reader.next();
            str += reader.current();
            i++;
        }
        transform(str.begin(), str.end(), str.begin(), ::tolower);
        if (str != "true") {
            cerr << "Expected 'true', found " << str << endl;
        }
        return json_bool(true);
    }

    json_bool deserialize_bool_false() {
        string str;
        str += reader.current();
        int i = 1;
        while (i < 5) {
            reader.next();
            str += reader.current();
            i++;
        }
        transform(str.begin(), str.end(), str.begin(), ::tolower);
        if (str != "false") {
            cerr << "Expected 'false', found " << str << endl;
        }
        return json_bool(false);
    }

    json_null deserialize_null() {
        string str;
        str += reader.current();
        int i = 1;
        while (i < 4) {
            reader.next();
            str += reader.current();
            i++;
        }
        transform(str.begin(), str.end(), str.begin(), ::tolower);
        if (str != "null") {
            cerr << "Expected 'null', found " << str << endl;
        }
        return json_null_instance;
    }

    json_number deserialize_number() {
        string str;
        if (reader.current() != opening_plus) {
            str += reader.current();
        }

        while (reader.next()) {
            char current = reader.current();
            if (is_closer(current) || current == ',') {
                break;
            } else {
                str += current;
            }
        }

        reader.back();

        return json_number(stod(str));
    }

    json_str deserialize_str() {
        string str;
        while(reader.current() == ' ') {
            reader.next();
        }
        if (reader.current() == opening_str) {
            while (reader.next()) {
                char current = reader.current();
                if (current == closing_str && reader.read_prev() != '\\') {
                    break;
                }
                str += current;
            }
        }
        return json_str(str);
    }

    json_array deserialize_array() {
        json_array array = json_array();

        bool hasNext = true;
        while (hasNext) {
            reader.next();

            if (reader.current() == closing_array) {
                return array;
            }

            if ((current_deserialization_type() & g_json_str) != 0) {
                json_str jsonStr = deserialize_str();
                array.vlist() -> emplace_back(&jsonStr);
            } else if ((current_deserialization_type() & g_json_null) != 0) {
                json_null jsonNull = deserialize_null();
                array.vlist() -> emplace_back(&jsonNull);
            } else if ((current_deserialization_type() & g_json_number) != 0) {
                json_number jsonNumber = deserialize_number();
                array.vlist() -> emplace_back(&jsonNumber);
            } else if ((current_deserialization_type() & g_json_array) != 0) {
                json_array jsonArray = deserialize_array();
                array.vlist() -> emplace_back(&jsonArray);
            } else if ((current_deserialization_type() & g_json_bool) != 0) {
                if ((current_deserialization_type() & g_json_true) != 0) {
                    json_bool jsonBool = deserialize_bool_true();
                    array.vlist() -> emplace_back(&jsonBool);
                } else if ((current_deserialization_type() & g_json_false) != 0) {
                    json_bool jsonBool = deserialize_bool_false();
                    array.vlist() -> emplace_back(&jsonBool);
                }
            } else if ((current_deserialization_type() & g_json_object) != 0) {
                json_object jsonObject = deserialize_json_object();
                array.vlist() -> emplace_back(&jsonObject);
            } else {
                // eat it up
            }

            if (reader.current() == closing_array) {
                hasNext = false;
            }
            reader.next();
            if (reader.current() == closing_array) {
                hasNext = false;
            }
        }

        return array;
    }

    json_object deserialize_json_object() {
        json_object obj;

        while(true) {
            reader.next();

            if (reader.current() == closing_object) {
                return obj;
            }

            json_str key = deserialize_str();

            while (reader.next()) {
                char current = reader.current();
                if (current == ':') {
                    reader.next();
                    break;
                }
            }

            if ((current_deserialization_type() & g_json_str) != 0) {
                json_str jsonStr = deserialize_str();
                obj.kvmap().insert(make_pair(key.str_value(), &jsonStr));
            } else if ((current_deserialization_type() & g_json_null) != 0) {
                json_null jsonNull = deserialize_null();
                obj.kvmap().insert(make_pair(key.str_value(), &jsonNull));
            } else if ((current_deserialization_type() & g_json_number) != 0) {
                json_number jsonNumber = deserialize_number();
                obj.kvmap().insert(make_pair(key.str_value(), &jsonNumber));
            } else if ((current_deserialization_type() & g_json_array) != 0) {
                json_array jsonArray = deserialize_array();
                obj.kvmap().insert(make_pair(key.str_value(), &jsonArray));
            } else if ((current_deserialization_type() & g_json_bool) != 0) {
                if ((current_deserialization_type() & g_json_true) != 0) {
                    json_bool jsonBool = deserialize_bool_true();
                    obj.kvmap().insert(make_pair(key.str_value(), &jsonBool));
                } else if ((current_deserialization_type() & g_json_false) != 0) {
                    json_bool jsonBool = deserialize_bool_false();
                    obj.kvmap().insert(make_pair(key.str_value(), &jsonBool));
                }
            } else if ((current_deserialization_type() & g_json_object) != 0) {
                json_object jsonObject = deserialize_json_object();
                obj.kvmap().insert(make_pair(key.str_value(), &jsonObject));
            }

            reader.next();

            if (reader.current() == closing_object) {
                break;
            }
        }

        return obj;
    }

public:
    explicit json_deserializer(const string &value): reader(json_reader(value)) {
    }

    json_object deserialize() {
        char current = reader.current();
        if (is_opener(current) && current == opening_object) {
            return deserialize_json_object();
        }
        cerr << "Root tag was not a compound tag" << endl << reader.cbuf << endl;
        return json_object();
    }
};
