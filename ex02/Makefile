NAME = PmergeMe

CC = c++

FLAGS = -Wall -Wextra -Werror -std=c++98 -g

SRC = PmergeMe.cpp main.cpp

OBJ = $(SRC:.cpp=.o)

all : $(NAME)

$(NAME) : $(OBJ) PmergeMe.hpp
	$(CC) $(FLAGS) $(OBJ) -o $@

%.o : %.cpp PmergeMe.hpp
	$(CC) $(FLAGS) -c $< -o $@

clean :
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.phony : all clean fclean re
