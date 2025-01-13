NAME = btc

CC = c++

FLAGS = -Wall -Wextra -Werror -std=c++98 -g

SRC = BitcoinExchange.cpp main.cpp

OBJ = $(SRC:.cpp=.o)

all : $(NAME)

$(NAME) : $(OBJ) BitcoinExchange.hpp
	$(CC) $(FLAGS) $(OBJ) -o $@

%.o : %.cpp BitcoinExchange.hpp
	$(CC) $(FLAGS) -c $< -o $@

clean :
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.phony : all clean fclean re
