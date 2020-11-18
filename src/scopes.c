const int g_array_empty = 1;
const int g_array_non_empty = 2;
const int g_object_empty = 3;
const int g_dangling_name = 4;
const int g_object_non_empty = 5;
const int g_document_empty = 6;
const int g_document_non_empty = 7;
const int g_closed = 8;

const int g_peeked_none = 0;
const int g_peeked_begin_object = 1;
const int g_peeked_end_object = 2;
const int g_peeked_begin_array = 3;
const int g_peeked_end_array = 4;
const int g_peeked_true = 5;
const int g_peeked_false = 6;
const int g_peeked_null = 7;
const int g_peeked_single_quoted = 8;
const int g_peeked_double_quoted = 9;
const int g_peeked_unquoted = 10;
const int g_peeked_buffered = 11;
const int g_peeked_single_quoted_name = 12;
const int g_peeked_double_quoted_name = 13;
const int g_peeked_unquoted_name = 14;
const int g_peeked_long = 15;
const int g_peeked_number = 16;
const int g_peeked_eof = 17;

const int g_number_char_none = 0;
const int g_number_char_sign = 1;
const int g_number_char_digit = 2;
const int g_number_char_decimal = 3;
const int g_number_char_fraction_digit = 4;
const int g_number_char_exp_e = 5;
const int g_number_char_exp_sign = 6;
const int g_number_char_exp_digit = 7;
