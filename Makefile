CC = gcc
RM = rm -f
CFLAGS = -fPIC -g -O2 -std=c99 \
	-Wall -Wextra -pedantic -Werror \
	-Wdeclaration-after-statement \
	-Wno-format-zero-length \
	-Wold-style-definition \
	-Woverflow \
	-Wpointer-arith \
	-Wunused \
	-Wvla

LDFLAGS = -g
LDLIBS =

TARGET_LIB = mulithash.a
TARGET_BIN = multihash

SRCS = errors.c
OBJS = $(SRCS:.c=.o)

all: $(TARGET_LIB) $(TARGET_BIN)

$(TARGET_LIB): $(OBJS)
	ar rcs $@ $^

$(TARGET_BIN): main.o $(TARGET_LIB)
	$(CC) $(LDFLAGS) $^ -o $@

# Tests

TEST_SRCS = $(wildcard tests/c/test_*.c)
TEST_OBJS = $(TEST_SRCS:.c=.o)
TEST_BINS = $(TEST_OBJS:.o=)

PHONY += tests
tests: $(TEST_BINS)
	@for t in $^; do               \
	  echo;                        \
	  echo '***' "$$t.c" '***';    \
	  "./$$t";                     \
	done

tests/c/test_%.o: tests/c/test_%.c
	$(CC) -c -I. $^ -o $@

tests/c/test_%: tests/c/test_%.o $(TARGET_LIB)
	$(CC) $(LDFLAGS) $^ -o $@

# Utils

PHONY += clean dist-clean

clean:
	$(RM) $(OBJS)
	$(RM) $(TEST_BINS)
	$(RM) $(TARGET_LIB)
	$(RM) $(TARGET_BIN)

dist-clean: clean

.PHONY: $(PHONY)
