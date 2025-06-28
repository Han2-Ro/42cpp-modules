NAME = PmergeMe
SRCS = main.cpp PmergeMe.cpp SortNode.cpp SortValue.cpp

include ../common.mk

tests: tests.o PmergeMe.o SortNode.o SortValue.o
	$(CXX) tests.o PmergeMe.o SortNode.o SortValue.o -o tests