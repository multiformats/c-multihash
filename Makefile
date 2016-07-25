CC = gcc
RM = rm -f
CFLAGS = -fPIC -g -O2 -std=c99 \
	-Wall -Wextra -pedantic -Werror \
	-Wdeclaration-after-statement \
	-Wno-format-zero-length \
	-Wold-style-definition \
	-Woverflow \
	-Wpointer-arith \
	-Wstrict-prototypes \
	-Wunused \
	-Wvla

LDFLAGS = -g -shared
LDLIBS =

TARGET_LIB = mulithash.so

SRCS = errors.c
OBJS = $(subst .c,.o,$(SRCS))

all: ${TARGET_LIB} 

$(TARGET_LIB): $(OBJS)
	$(CC) ${LDFLAGS} -o $@ $^

test: test.o pid.o
	$(C) $(LDFLAGS) -o test test.o pid.o $(LDLIBS) 

depend: .depend

.depend: $(SRCS)
	rm -f ./.depend
	$(CC) $(CFLAGS) -MM $^>>./.depend;

clean:
	$(RM) $(OBJS)
	$(RM) $(TARGET_LIB)

dist-clean: clean
	$(RM) *~ .depend

.PHONY: all depend clean dist-clean

include .depend
