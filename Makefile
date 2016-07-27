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

MAIN = src/main.c
MAIN_O = $(MAIN:.c=.o)

SRCS = src/errors.c src/hashes.c
OBJS = $(SRCS:.c=.o)

src/%.o: src/%.c
	$(CC) $(CFLAGS) -c -I include $< -o $@

all: $(TARGET_LIB) $(TARGET_BIN)

$(TARGET_LIB): $(OBJS)
	ar rcs $@ $^

$(TARGET_BIN): $(MAIN_O) $(TARGET_LIB)
	$(CC) $(LDFLAGS) $^ -o $@

# Tests

TEST_SRCS = $(wildcard tests/c/test_*.c)
TEST_OBJS = $(TEST_SRCS:.c=.o)
TEST_BINS = $(TEST_OBJS:.o=)

PHONY += test
test: $(TEST_BINS)
	@for t in $^; do                                   \
	  echo;                                            \
	  echo '***' "$$t.c" '***';                        \
	  "./$$t" || ERROR=1;                              \
	done;                                              \
	echo;                                              \
	[ "$${ERROR-0}" -eq "1" ] && exit 1

tests/c/test_%.o: tests/c/test_%.c tests/c/minunit.h
	$(CC) $(CFLAGS) -c -I include $< -o $@

tests/c/test_%: tests/c/test_%.o $(TARGET_LIB)
	$(CC) $(LDFLAGS) $^ -o $@

# Utils

PHONY += clean dist-clean

clean:
	$(RM) $(OBJS)
	$(RM) $(TEST_BINS)
	$(RM) $(TARGET_LIB)
	$(RM) $(TARGET_BIN)
	$(RM) $(MAIN_O)

dist-clean: clean

PHONY += build
build: all

.PHONY: $(PHONY)
