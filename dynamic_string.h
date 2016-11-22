
#ifndef DYNAMIC_STRING_H
#define DYNAMIC_STRING_H

#define STRING_DEFAULT_LENGTH

typedef unsigned int str_size;

struct _string {

  char* str;
  str_size len;
};

typedef struct _string string;

extern string make_string(const char* cstr);
extern string concat_string(string* this, const char* cstr);
extern str_size string_len(const string* this);
extern void delete_string(string* this);

extern void print_string(const string* this);
extern void println_string(const string* this);

#endif
