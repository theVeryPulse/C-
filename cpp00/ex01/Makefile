NAME := phone_book
FILES := main.cpp \
	Contact.cpp \
	PhoneBook_addContact.cpp \
	PhoneBook_search.cpp \
	PhoneBook.cpp
FLAGS := -Wall -Wextra -Werror -std=c++98
OFILES := $(patsubst %.cpp, build/%.o, $(FILES))

all: $(NAME)

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

.PHONE: all, clean, fclean, re
