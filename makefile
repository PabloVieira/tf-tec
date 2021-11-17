# ==========================================
#   Unity Project - A Test Framework for C
#   Copyright (c) 2007 Mike Karlesky, Mark VanderVoord, Greg Williams
#   [Released under MIT License. Please refer to license.txt for details]
# ==========================================

#We try to detect the OS we are running on, and adjust commands as needed
ifeq ($(OS),Windows_NT)
  ifeq ($(shell uname -s),) # not in a bash-like shell
	CLEANUP = del /F /Q
	MKDIR = mkdir
  else # in a bash-like shell, like msys
	CLEANUP = rm -fr
	MKDIR = mkdir -p
  endif
	TARGET_EXTENSION=.exe
else
	CLEANUP = rm -fr
	MKDIR = mkdir -p
	TARGET_EXTENSION=.out
endif

C_COMPILER=gcc
ifeq ($(shell uname -s), Darwin)
C_COMPILER=clang
endif

UNITY_ROOT=Unity/

CFLAGS=-std=c99
CFLAGS += -Wall
CFLAGS += -Wextra
CFLAGS += -Wpointer-arith
CFLAGS += -Wcast-align
CFLAGS += -Wwrite-strings
CFLAGS += -Wswitch-default
CFLAGS += -Wunreachable-code
CFLAGS += -Winit-self
CFLAGS += -Wmissing-field-initializers
CFLAGS += -Wno-unknown-pragmas
CFLAGS += -Wstrict-prototypes
CFLAGS += -Wundef
CFLAGS += -Wold-style-definition

ALL_LDFLAGS :=
ALL_LDFLAGS += $(ALL_CCFLAGS)
ALL_LDFLAGS += $(addprefix -Xlinker ,$(LDFLAGS))
ALL_LDFLAGS += $(addprefix -Xlinker ,$(EXTRA_LDFLAGS))

TARGET_BASE1=all_tests
TARGET1 = $(TARGET_BASE1)$(TARGET_EXTENSION)
FILE_NAME = src/sort
SRC_FILES1=\
  $(UNITY_ROOT)/src/unity.c \
  $(UNITY_ROOT)/extras/fixture/src/unity_fixture.c \
  src/array.c \
  $(FILE_NAME).c \
  test/TestSortArray.c \
  test/test_runners/TestSortArray_Runner.c \
  test/test_runners/all_tests.c
INC_DIRS=-Isrc -I$(UNITY_ROOT)/src -I$(UNITY_ROOT)/extras/fixture/src

all: clean compile run

compile: clean
	$(C_COMPILER) $(CFLAGS) $(INC_DIRS) $(SYMBOLS) $(SRC_FILES1) -o $(TARGET1)

cov: clean
	$(C_COMPILER) -fprofile-arcs -ftest-coverage $(CFLAGS) $(INC_DIRS) $(SRC_FILES1) -o gcov/$@
	mv *.gcno gcov/

run_cov: cov
	- ./gcov/cov -v
	mv *.gcda gcov/

gcov: run_cov
	gcov -b gcov/sort

cppcheck: $(FILE_NAME).c
	cppcheck --enable=all --suppress=missingIncludeSystem $(FILE_NAME).c

valgrind: clean $(FILE_NAME).c
	$(C_COMPILER) -g -Wall -Wfatal-errors $(FILE_NAME).c -o $(FILE_NAME)
	valgrind --leak-check=full --show-leak-kinds=all ./$(FILE_NAME)

sanitizer: clean main.c
	#$(GCC) $(GCCFLAGS) -fsanitize=address main.c -o $(FILE_NAME)
	gcc main.c -o teste -fsanitize=address -static-libasan -g

array.o:src/array.c
	gcc -o $@ -c $<

sort.o:src/sort.c
	gcc -o $@ -c $<

get_opt.o:src/get_opt.c
	gcc -o $@ -c $<

main.o:src/main.c
	gcc -o $@ -c $<

app: clean array.o sort.o get_opt.o main.o
	gcc $(ALL_LDFLAGS) -o $@ $+ $(LIBRARIES)

run_app: app
	- ./app -a quick -n 8 -s random -P

run:
	- ./$(TARGET1) -v

clean:
	$(CLEANUP) $(TARGET1) src/*.o *.o *.dSYM *.gcda *.gcov gcov/* app

ci: CFLAGS += -Werror
ci: compile