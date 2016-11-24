#include "dynamic_string.h"

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <string.h>

string make_string(const char* cstr) {

  assert(cstr != NULL);

  size_t length = strlen(cstr);

  string my_string;
  my_string.str = malloc(length * sizeof(char));
  strcpy(my_string.str, cstr);
  my_string.len = length;
  my_string.capacity = length;
  return my_string;
}

string new_string() {

  string my_string;
  my_string.str = malloc(sizeof(char));
  my_string.str[0] = '\0'; // empty string

  my_string.len = 0;
  my_string.capacity = 0;
  return my_string;
}

str_size string_len(const string* str) {
  return str->len;
}

string concat_cstr(string* this, const char* cstr) {

  assert(this != NULL);
  assert(cstr != NULL);

  size_t length = strlen(cstr);

  char* new_str = realloc(this->str, length + this->len * sizeof(char));

  this->str = new_str;
  strcat(this->str, cstr);
  this->len += length;

  return *this;
}

string concat_string(string* this, const string* other) {
  //assert(this != NULL);
  //assert(other != NULL);

  size_t length = string_len(other);

  char* new_str = realloc(this->str, length + this->len * sizeof(char));

  this->str = new_str;
  strcat(this->str, other->str);
  this->len += length;

  return *this;
}

string substring(const string* this, const int begin, const int end) {
  assert(this != NULL);

  char* sub_str = malloc((end - begin) * sizeof(char));

  string new_str;

  for (int i = 0; i < end - begin; ++i) {
    sub_str[i] = this->str[begin + i];
  }
  sub_str[end] = '\0';
  new_str.str = sub_str;
  new_str.len = end - begin;
  new_str.capacity = end - begin;
  return new_str;
}

char char_at(const string* this, const int pos) {

  assert(this != NULL);

  return this->str[pos];
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
