
#include <stdio.h>

#include "dynamic_string.h"

int main() {

  string myString = make_string("hello");
  println_string(&myString);
  printf("%d\n", string_len(&myString));
  myString = concat_string(&myString, ", world!");
  println_string(&myString);
  printf("%d\n", string_len(&myString));
  delete_string(&myString);
  return 0;
}
