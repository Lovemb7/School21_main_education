CC = gcc
CFLAGS=-Wall -Werror -Wextra
CCOV = -fprofile-arcs -ftest-coverage
SOURSE_FILE = *.c SmartCalc.h
COVFLAGS = --coverage
LDFLAGS = -lgcov
TFLAGS = -lcheck -lm -lsubunit
#ASAN = -g -fsanitize=address

all: clean install run	

install:
	sh install_script.sh

uninstall:
	rm -rf build

dvi:
	open readme.html

dist:
	sh dist_script.sh

run:
	./build/SmartCalc_1_0

test: 
	$(CC) $(CFLAGS) $(ASAN) $(CCOV) $(SOURSE_FILE) -o test $(TFLAGS)
	./test

gcov_report:
	$(CC) $(ASAN) $(GFLAGS) $(CCOV) $(SOURSE_FILE) $(TFLAGS) -o ./htmlreport.out
	./htmlreport.out
	lcov -t "htmlreport" -o test.info -c -d .
	genhtml -o report test.info
	open report/index.html

check:
	cppcheck --enable=all --force *.c SmartCalc.h

leakscheck: test
	leaks --atExit -- ./test
#	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./test


clean:
	rm -rf *.o *.a *.css index.html *.gcno *.gcda *.out *.info test report *.dSYM *.gcov build *.gch SmartCalc_dist SmartCalc_arch.tar.gz

rebuild: clean all

.PHONY : dvi clean run test gcov_report install uninstall
