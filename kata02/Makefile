# Compiler configuration
CC      ?= /usr/bin/gcc
CFLAGS  += -Wall -Wextra -g -DVERSION=\"$(VERSION)\"
LDFLAGS = -lm

HAS_CHECK=$(shell pkg-config --exists check; echo $$?)
ifeq ($(HAS_CHECK), 0)
	CFLAGS  += $(shell pkg-config --cflags check)
	LDFLAGS += $(shell pkg-config --libs check)
endif

FILES = chop_test.c

# generate object file list
OBJS = $(patsubst %.c,%.o,$(FILES))

TESTS = chop1.t chop2.t chop3.t

all: tests clean

tests: $(TESTS)
	for f in $^; do ./$$f; done

%.t: %.o $(OBJS)
	$(CC) $(CFLAGS) -o $@ $< $(OBJS) $(LDFLAGS)
	./$@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean: 
	rm -f *.o

cleanall: clean
	rm -f *.t
	
.PHONY: clean cleanall all
