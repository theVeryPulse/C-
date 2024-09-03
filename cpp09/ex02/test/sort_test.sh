SORT_TEST=sort_test

g++ sort_test.cpp ../PmergeMe*.cpp -o $SORT_TEST -Wall -Wextra -Werror -g \
&& "./$SORT_TEST" \
&& rm "./$SORT_TEST" \
&& echo "Sort OK"


