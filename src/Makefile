CC=gcc
CFLAGS=-Wall -Wextra -Werror -std=c11 -g
LDFLAGS=$(shell pkg-config --cflags --libs check)
GCOVFLAGS=-fprofile-arcs -ftest-coverage

all: my_matrix.a

my_matrix.a:
	$(CC) $(CFLAGS) -c lib/*.c help_func/*.c
	ar rc my_matrix.a *.o
	ranlib my_matrix.a

test:
	$(CC) $(CFLAGS) $(LDFLAGS)  lib/*.c help_func/*.c tests/*.c -lm `pkg-config --cflags --libs check`
	./a.out
	rm a.out

gcov_report:
	$(CC) $(CFLAGS) $(LDFLAGS) $(GCOVFLAGS) lib/*.c help_func/*.c tests/*.c -o gcov_main -lm `pkg-config --cflags --libs check`
	./gcov_main
	lcov --capture --directory . --output-file coverage.info
	genhtml coverage.info --output-directory gcov_report
	open gcov_report/index.html

clean:
	-rm -rf *.o *.html *.gcda *.gcno *.css *.a *.gcov *.info *.out *.cfg *.txt gcov*

style_check:
	clang-format -style=Google -n *.h
	clang-format -style=Google -n */*.c

cpk:
	cppcheck *.[h]
	cppcheck */*.[c]

rebuild: clean all
