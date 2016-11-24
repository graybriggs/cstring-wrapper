CC = gcc
CFLAGS = -Wall -pedantic
DEPS = dynamic_string.h



%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

libds : $(obj)
	gcc -shared $@ $^
