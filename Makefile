CC := gcc
CFLAGS = -std=c11 -Wall -Werror -Wextra
FLAG_TEST = -lcheck -g
CFLAGS_COVERAGE := $(CFLAGS) --coverage

ifeq ($(shell uname), Linux)
	FLAG_TEST +=-lsubunit -lm
endif

SRCS := $(wildcard src/*.c)
OBJS := $(SRCS:.c=.o)

TESTS := $(wildcard ./tests/test*.c)
TESTS += $(SRCS)
DOXYGEN := doxygen

TESTS_DIR := tests
SRC_DIR := src
REPORT_DIR := report
DOC_DIR := doc

all: static

static: lquadratic.a

lquadratic.a: $(OBJS)
	ar rc $@ $^
	ranlib $@
	-rm -rf $(SRC_DIR)/*.o

check: lquadratic.a
	$(CC) $(CFLAGS) $(TESTS) lquadratic.a $(FLAG_TEST) -o  $(TESTS_DIR)/test -g
	./$(TESTS_DIR)/test

doc: $(SRCS) $(TESTS)
	$(DOXYGEN) Doxyfile

gcov_report:
	$(CC) $(CFLAGS_COVERAGE) $(TESTS) -o $(TESTS_DIR)/test $(FLAG_TEST)
	./$(TESTS_DIR)/test
	mkdir -p $(REPORT_DIR)/coverage
	mv $(TESTS_DIR)/test-* $(REPORT_DIR)/coverage
	mv $(TESTS_DIR)/test $(REPORT_DIR)/coverage
	lcov -t "test" -o $(REPORT_DIR)/quadtratic_eq.info -c -d .
	genhtml -o $(REPORT_DIR) $(REPORT_DIR)/quadtratic_eq.info
	open $(REPORT_DIR)/index.html

clean:
	-rm -rf *.o *.gcno *.gcda *.info test lquadratic.a gcov_report report greport
	-rm -rf $(TESTS_DIR)/test
	-rm -rf $(REPORT_DIR)
	-rm -rf $(DOC_DIR)

clang_check:
	clang-format -style=Google -n $$(find . -name '*.c' -o -name '*.h')

clang_format:
	clang-format -style=Google -i $$(find . -name '*.c' -o -name '*.h')
