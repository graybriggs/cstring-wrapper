
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <string.h>

#include "dynamic_string.h"



string make_string(const char* cstr) {

  assert(cstr != NULL);

  size_t length = strlen(cstr);

  string my_string;
  my_string.str = malloc(length * sizeof(char));
  strcpy(my_string.str, cstr);
  my_string.len = length;
  return my_string;
}

str_size string_len(const string* str) {
  return str->len;
}

string concat_string(string* this, const char* cstr) {

  assert(this != NULL);
  assert(cstr != NULL);

  size_t length = strlen(cstr);

  char* new_str = realloc(this->str, length + this->len * sizeof(char));

  this->str = new_str;
  strcat(this->str, cstr);
  this->len += length;

  return *this;
}

void delete_string(string* this) {
  assert (this != NULL);

  free(this->str);
  this->str = NULL;
}

void print_string(const string* this) {
  printf("%s", this->str);
}

void println_string(const string* this) {
  printf("%s\n", this->str);
}
