NAME = PmergeMe
COMMEN_SRCS = PmergeMe.cpp SortNode.cpp SortValue.cpp SortElem.cpp
SRCS = main.cpp $(COMMEN_SRCS)
TEST_SRCS = tests.cpp $(COMMEN_SRCS)
HEADERS = PmergeMe.hpp PmergeMe.tpp SortNode.hpp SortValue.hpp SortElem.hpp
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
OBJS = $(SRCS:.cpp=.o)
TEST_OBJS = $(TEST_SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

tests.o: tests.cpp $(HEADERS)
	$(CXX) -c $< -o $@

%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME) tests tests.o

re: fclean all


tests: $(TEST_OBJS)
	$(CXX) $(TEST_OBJS) -o tests

.PHONY: all clean fclean re tests
