
#include <stdio.h>

#include "dynamic_string.h"

int main() {

  string mystr = str_make("hello");
  str_println(&mystr);
  printf("%d\n", str_len(&mystr));
  mystr = str_cstr_concat(&mystr, ", world!");
  str_println(&mystr);
  printf("%d\n", str_len(&mystr));

  string test = str_make("I am a pirate!");
  mystr = str_concat(&mystr, &test);

  str_println(&mystr);

  printf("%c\n",str_char_at(&test,11));  // p

  string empty = str_make_empty(); // empty but allocated 1 char for null.

  string ss = str_sub(&test, 11, str_len(&test)); // careful - returns a live dynamically allocated object
  str_println(&ss);
  str_delete(&ss);

  string hi = str_make_empty();
  hi = str_cstr_concat(&hi, "hi");
  str_println(&hi);
  str_delete(&hi);

  str_delete(&mystr);
  str_delete(&test);
  str_delete(&empty);
  return 0;
}
