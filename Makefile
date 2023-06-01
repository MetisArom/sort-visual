# Makefile

# Compiler
CXX ?= g++

# Compiler flags
CXXFLAGS = -Wall -Werror -pedantic -g --std=c++11 -Wno-sign-compare -Wno-comment -fsanitize=address -fsanitize=undefined -D_GLIBCXX_DEBUG

driver.exe: driver.cpp Sorter.h
	$(CXX) $(CXXFLAGS) driver.cpp -o $@

# disable built-in rules
.SUFFIXES:

# these targets do not create any files
.PHONY: clean
clean:
	rm -vrf *.o *.exe *.gch *.dSYM *.stackdump *.out