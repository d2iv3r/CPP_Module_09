NAME = RPN

CC = c++

FLAGS = -Wall -Wextra -Werror -std=c++98 -g

SRC = RPN.cpp main.cpp

OBJ = $(SRC:.cpp=.o)

all : $(NAME)

$(NAME) : $(OBJ) RPN.hpp
	$(CC) $(FLAGS) $(OBJ) -o $@

%.o : %.cpp RPN.hpp
	$(CC) $(FLAGS) -c $< -o $@

clean :
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.phony : all clean fclean re
