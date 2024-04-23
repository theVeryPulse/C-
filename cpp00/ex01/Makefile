NAME := phone_book
FILES := main.cpp \
	PhoneBook_search.cpp \
	PhoneBook.cpp
FLAGS := -Wall -Wextra -Werror -std=c++98
OFILES := $(patsubst %.cpp, build/%.o, $(FILES))

all: $(NAME)

$(NAME): $(OFILES)
	c++ $(OFILES) -o $@ $(FLAGS)

build/%.o: %.cpp
	@mkdir -p $(@D)
	c++ $< -c -o $@ $(FLAGS)

clean:
	rm -rf build

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONE: all, clean, fclean, re
