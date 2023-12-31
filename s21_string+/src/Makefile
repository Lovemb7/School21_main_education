CC=gcc
CFLAGS=-Wall -Werror -Wextra -std=c11 -c -fsanitize=address -g
#CFLAGS=-std=c11 -c
CFLAGS_GCOV=-fprofile-arcs -ftest-coverage
#Убрать fsanitize, arcs, coverage. Переместить сборку тестов в другую папку
LIBS=-lcheck -lgcov
LFLAGS=$(LIBS) $(CFLAGS_GCOV) -fsanitize=address

#SOURCE_DIRECTORIES=s21_common/s21_is_found s21_common/s21_memcpy_forward_backward s21_common/s21_filter_from_beginning s21_memchr s21_memcmp s21_memcpy s21_memmove s21_memset s21_strcat s21_strchr s21_strcmp s21_strcpy s21_strcspn s21_strerror s21_strlen s21_strncat s21_strncmp s21_strncpy s21_strpbrk s21_strrchr s21_strspn s21_strstr s21_strtok s21_to_lower s21_to_upper s21_trim s21_insert
SOURCE_DIRECTORIES=

OBJECT_DIRECTORIES_TO_CLEAN=$(subst ../,,$(filter ../%, $(SOURCE_DIRECTORIES)))


REPORT_DIRECTORY=report
BUILD_DIRECTORY=build
STATIC_BUILD_DIRECTORY=static
DEPENDENCY_DIRECTORY=$(BUILD_DIRECTORY)/dependencies


# ALL_TESTS_IN_ONE_FILE=$(BUILD_DIRECTORY)/s21_string_test.check
ALL_TESTS_IN_ONE_FILE=s21_string_test.check
# ALL_TESTS_IN_ONE_FILE_GENERATED=$(BUILD_DIRECTORY)/s21_string_test.c
# ALL_TESTS_IN_ONE_FILE_GENERATED=s21_string_test.c
#SOURCE_FILES_TESTS=$(foreach directory_as_variable, $(SOURCE_DIRECTORIES),$(wildcard $(directory_as_variable)/*.check))
# TEST_FILES=$(foreach directory_as_variable, $(SOURCE_DIRECTORIES),$(wildcard $(directory_as_variable)/*.check))
TEST_FILES=$(wildcard *.check)

STATIC_LIBRARY=s21_string.a

TEST_FILE=$(ALL_TESTS_IN_ONE_FILE)
# TEST_FILE_GENERATED=$(patsubst %.check,%.c,$(TEST_FILE))
TEST_FILE_GENERATED=$(BUILD_DIRECTORY)/$(patsubst %.check,%.c,$(TEST_FILE))

OBJECT_TEST_FILE_GENERATED=$(BUILD_DIRECTORY)/$(notdir $(patsubst %.c,%.o,$(TEST_FILE_GENERATED)))
TARGET_TEST=$(BUILD_DIRECTORY)/$(notdir $(patsubst %.o,%.out,$(OBJECT_TEST_FILE_GENERATED)))

SOURCE_FILES_ALL=$(wildcard *.c)
SOURCE_FILES_ALL+=$(foreach directory_as_variable, $(SOURCE_DIRECTORIES),$(wildcard $(directory_as_variable)/*.c))
SOURCE_FILES=$(filter-out %_test.c, $(SOURCE_FILES_ALL))

OBJECT_FILES_IN_SOURCE_DIRECTORIES=$(patsubst %.c,%.o,$(SOURCE_FILES))
OBJECT_FILES_IN_BUILD_DIRECTORIES=$(addprefix $(BUILD_DIRECTORY)/,$(OBJECT_FILES_IN_SOURCE_DIRECTORIES))
OBJECT_FILES_IN_BUILD_DIRECTORIES_FOR_LIBRARY=$(addprefix $(STATIC_BUILD_DIRECTORY)/,$(OBJECT_FILES_IN_SOURCE_DIRECTORIES))

# OBJECT_FILES_IN_BUILD_DIRECTORIES+=$(OBJECT_TEST_FILE_GENERATED)

DEPENDENCY_FILES_ALL_IN_SOURCE_DIRECTORIES=$(patsubst %.c,%.d,$(SOURCE_FILES))
DEPENDENCY_FILES_ALL_IN_DEPENDENCY_DIRECTORIES=$(addprefix $(DEPENDENCY_DIRECTORY)/,$(DEPENDENCY_FILES_ALL_IN_SOURCE_DIRECTORIES))

TEST_FILE_GENERATED_DEPENDENCY=$(DEPENDENCY_DIRECTORY)/$(subst .c,.d,$(notdir $(TEST_FILE_GENERATED)))
DEPENDENCY_FILES_ALL_IN_DEPENDENCY_DIRECTORIES+=$(TEST_FILE_GENERATED_DEPENDENCY)
DEPENDENCY_DIRECTORIES=$(dir $(DEPENDENCY_FILES_ALL_IN_DEPENDENCY_DIRECTORIES))

DEPFLAGS=-MT $@ -MMD -MP -MF $(DEPENDENCY_DIRECTORY)/$*.d

all: test gcov_report s21_string.a

test: build_test
		-$(TARGET_TEST)

build_test: $(TARGET_TEST)




all_tests: 



gather_all_tests: $(ALL_TESTS_IN_ONE_FILE)

insert_line_to_make_leaks_work_fast:
		sed -i.bak -r 's/srunner_run_all\(sr, CK_ENV\);/srunner_set_fork_status\(sr, CK_NOFORK\); srunner_run_all\(sr, CK_ENV\);/g' $(TEST_FILE_GENERATED)


$(ALL_TESTS_IN_ONE_FILE): $(TEST_FILES)
		mkdir -p $(dir $@)
		rm -f $(ALL_TESTS_IN_ONE_FILE)
		touch $(ALL_TESTS_IN_ONE_FILE)
		cat $^ >> $@

	

gcov_report: test
		mkdir -p $(REPORT_DIRECTORY)
		gcovr . --html --html-details -o $(REPORT_DIRECTORY)/coverage_report.html

leaks: test
		leaks -atExit -- $(TARGET_TEST)

leaks_short: test
		leaks -atExit -- $(TARGET_TEST) | grep LEAK

valgrind: build_test
		mkdir -p $(REPORT_DIRECTORY)
		valgrind --trace-children=yes --leak-check=full --show-leak-kinds=all --track-origins=yes $(TARGET_TEST) > $(REPORT_DIRECTORY)/valgrind_report.txt

s21_string.a: $(OBJECT_FILES_IN_BUILD_DIRECTORIES_FOR_LIBRARY)
		ar rcs $(STATIC_LIBRARY) $^

$(TEST_FILE_GENERATED): $(TEST_FILE)
		checkmk $< > $@


$(TARGET_TEST): $(OBJECT_FILES_IN_BUILD_DIRECTORIES) $(OBJECT_TEST_FILE_GENERATED)
		$(CC) -o $@ $^ $(LFLAGS)


$(OBJECT_TEST_FILE_GENERATED): $(TEST_FILE_GENERATED) insert_line_to_make_leaks_work_fast $(DEPENDENCY_FILE_TEST_FILE_GENERATED_IN_DEPENDENCY_DIRECTORY) | $(DEPENDENCY_DIRECTORY)
		mkdir -p $(dir $@)
		mkdir -p $(DEPENDENCY_DIRECTORY)/$(dir $*)
		$(CC) $(CFLAGS) $< -o $@ $(DEPFLAGS)


$(OBJECT_FILES_IN_BUILD_DIRECTORIES): $(BUILD_DIRECTORY)/%.o: %.c $(DEPENDENCY_DIRECTORY)/%.d | $(DEPENDENCY_DIRECTORY)
		mkdir -p $(dir $@)
		mkdir -p $(DEPENDENCY_DIRECTORY)/$(dir $*)
		$(CC) $(CFLAGS) $(CFLAGS_GCOV) $< -o $@ $(DEPFLAGS)


$(OBJECT_FILES_IN_BUILD_DIRECTORIES_FOR_LIBRARY): $(STATIC_BUILD_DIRECTORY)/%.o: %.c $(DEPENDENCY_DIRECTORY)/%.d | $(DEPENDENCY_DIRECTORY)
		mkdir -p $(dir $@)
		mkdir -p $(DEPENDENCY_DIRECTORY)/$(dir $*)
		$(CC) -c $< -o $@ $(DEPFLAGS)


$(DEPENDENCY_DIRECTORY):
		mkdir -p $(DEPENDENCY_DIRECTORY)


$(DEPENDENCY_FILES_ALL_IN_DEPENDENCY_DIRECTORIES):


clean: 
		rm -rf $(BUILD_DIRECTORY) $(STATIC_BUILD_DIRECTORY) $(DEPENDENCY_DIRECTORY)  $(BUILD_DIRECTORY)/$(DEPENDENCY_DIRECTORY) $(OBJECT_DIRECTORIES_TO_CLEAN) $(TEST_FILE_GENERATED) *.gcov *.html *.css $(REPORT_DIRECTORY) $(STATIC_LIBRARY) $(ALL_TESTS_IN_ONE_FILE)


clean_report:
		rm -rf $(REPORT_DIRECTORY)


print:
		echo $(TEST_FILES)
		

include $(wildcard $(DEPENDENCY_FILES_ALL_IN_DEPENDENCY_DIRECTORIES))
