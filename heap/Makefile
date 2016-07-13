CC=gcc
RELEASE=-O3 -ffast-math -fstrict-aliasing -march=native
DEBUG=-O0 -g
CFLAGS=-std=c99 -Wall -Werror $(RELEASE) #$(DEBUG)
TARGET=unittest
OBJS=main.o max_heap.o
TIMING=timing
TIMING_OBJS=timing.o max_heap.o
TARGETS=$(TARGET) $(TIMING)

all: $(TARGETS)

$(TIMING): $(TIMING_OBJS)
	$(CC) -o $@ $(CFLAGS) $(TIMING_OBJS) -lrt
timing.o: timing.c
	$(CC) -o $@ $(CFLAGS) -c $<
$(TARGET): $(OBJS)
	$(CC) -o $(TARGET) $(CFLAGS) $(OBJS)
%.o: %.c %.h
	$(CC) -o $@ $(CFLAGS) -c $<
main.o: main.c
	$(CC) -o $@ $(CFLAGS) -c $<
.PHONY: clean
clean:
	rm -rf $(TARGETS) $(OBJS) $(TIMING_OBJS)
