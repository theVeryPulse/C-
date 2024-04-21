NAME := megaphone
FLAGS := -Wall -Wextra -Werror -std=c++98
all : $(NAME)

$(NAME) : megaphone.cpp
	c++ $^ -o $@ $(FLAGS)

clean :
	rm -f megaphone

fclean :
	rm -f megaphone

re : clean all

.PHONY: all, clean, re
