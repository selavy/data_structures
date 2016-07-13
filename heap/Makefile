CC=gcc
RELEASE=-O3 -ffast-math -fstrict-aliasing
DEBUG=-O0 -g
CFLAGS=-std=c99 -Wall -Werror $(DEBUG)
TARGET=a.out
OBJS=main.o heap.o

$(TARGET): $(OBJS)
	$(CC) -o $(TARGET) $(CFLAGS) $(OBJS)
%.o: %.c %.h
	$(CC) -o $@ $(CFLAGS) -c $<
main.o: main.c
	$(CC) -o $@ $(CFLAGS) -c $<
.PHONY: clean
clean:
	rm -rf $(TARGET) $(OBJS)
