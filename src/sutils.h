#ifndef HEXJSON_SUTILS_CPP
#define HEXJSON_SUTILS_CPP

#include <string>
#include <regex>

using namespace std;

string ltrim(const string& str) {
    return regex_replace(str, regex("^\\s+"), string(""));
}

string rtrim(const string& str) {
    return regex_replace(str, regex("\\s+$"), string(""));
}

string trim(const string& str) {
    return ltrim(rtrim(str));
}

#endif
