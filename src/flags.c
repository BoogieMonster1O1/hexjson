#ifndef HEXJSON_FLAGS_C
#define HEXJSON_FLAGS_C

const unsigned int g_json_null = 1;
const unsigned int g_json_str = 2;
const unsigned int g_json_number = 4;
const unsigned int g_json_bool = 8;
const unsigned int g_json_array = 16;
const unsigned int g_json_object = 32;

const unsigned int g_json_true = 64;
const unsigned int g_json_false = 128;

#endif
