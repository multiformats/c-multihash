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

TARGET_LIB = mulithash.so

SRCS = errors.c
OBJS = $(SRCS:.c=.o)

all: ${TARGET_LIB} 

$(TARGET_LIB): $(OBJS)
	$(CC) -g -shared -o $@ $^

# Tests

TEST_SRCS = $(wildcard test/test_*.c)
TEST_OBJS = $(TEST_SRCS:.c=.o)
TEST_BINS = $(TEST_OBJS:.o=.out)

PHONY += tests
tests: $(TEST_BINS)
	@for t in $^; do               \
	  echo;                        \
	  echo '***' "$$t" '***';      \
	  LD_LIBRARY_PATH=. "./$$t";   \
	  echo;                        \
	done


test/test_%.out: test/test_%.o $(TARGET_LIB)
	$(CC) $(LDFLAGS) $(TARGET_LIB) $^ -o $@

# Utils

PHONY += clean dist-clean

clean:
	$(RM) $(OBJS)
	$(RM) $(TEST_OBJS)
	$(RM) $(TEST_BINS)
	$(RM) $(TARGET_LIB)

dist-clean: clean

.PHONY: $(PHONY)
