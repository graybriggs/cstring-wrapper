
#ifndef DYNAMIC_STRING_H
#define DYNAMIC_STRING_H

typedef unsigned int str_size;

struct _string {
  char* str;
  str_size len;
  int capacity; // will be used later to avoid constant reallocation
};

typedef struct _string string;

extern string make_string(const char* cstr);
extern string new_string();
extern void delete_string(string* this);
extern str_size string_len(const string* this);

extern string substring(const string* this, const int begin, const int end); // returns a new string; deletion must be handled
extern string concat_cstr(string* this, const char* cstr);
extern string concat_string(string* this, const string* other);
extern char char_at(const string* this, const int pos);
extern int string_find(string* this, const char* cstr);

extern void print_string(const string* this);
extern void println_string(const string* this);

#endif
