
#ifndef DYNAMIC_STRING_H
#define DYNAMIC_STRING_H

typedef unsigned int str_size;

struct _string {
  char* str;
  str_size len;
  int capacity; // will be used later to avoid constant reallocation
};

typedef struct _string string;

extern string str_make(const char* cstr);
extern string str_make_empty();
extern void str_delete(string* this);
extern str_size str_len(const string* this);

extern string str_sub(const string* this, const int begin, const int end); // returns a new string; deletion must be handled
extern string str_cstr_concat(string* this, const char* cstr);
extern string str_concat(string* this, const string* other);
extern char str_char_at(const string* this, const int pos);
extern int str_find(string* this, const char* cstr);

extern void str_print(const string* this);
extern void str_println(const string* this);

extern int str_stoi(const string* this);

extern void str_strip_front(const string* this);
extern void str_strip_rear(const string* this);


#endif
