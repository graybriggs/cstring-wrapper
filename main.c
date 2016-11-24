
#include <stdio.h>

#include "dynamic_string.h"

int main() {

  string myString = make_string("hello");
  println_string(&myString);
  printf("%d\n", string_len(&myString));
  myString = concat_cstr(&myString, ", world!");
  println_string(&myString);
  printf("%d\n", string_len(&myString));

  string test = make_string("hrr I am a pirate!");
  myString = concat_string(&myString, &test);

  println_string(&myString);

  printf("%c\n",char_at(&test,11));  // p

  string empty = new_string(); // empty but allocated 1 char for null.

  string ss = substring(&test, 11, string_len(&test)); // careful - returns a live dynamically allocated object
  println_string(&ss);
  delete_string(&ss);

  delete_string(&myString);
  delete_string(&test);
  delete_string(&empty);
  return 0;
}
