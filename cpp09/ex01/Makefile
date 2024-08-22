NAME   := RPN
FILES  :=  \
	main.cpp \
	RPN.cpp

FLAGS  := -Wall -Wextra -Werror -std=c++98
OFILES := $(patsubst %.cpp, build/%.o, $(FILES))

all: $(NAME)

debug: FLAGS = -std=c++98 -g -fstandalone-debug
debug: re

$(NAME): $(OFILES)
	@c++ $(OFILES) -o $@ $(FLAGS)
	@echo "\033[0;32m\n>>> ./$@\n\033[0m"

build/%.o: %.cpp
	@mkdir -p $(@D)
	@c++ $< -c -o $@ $(FLAGS)
	@echo "\033[0;32m* $^\033[0m"

clean:
	rm -rf build

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re
