SORT_TEST=list_sort_test

g++ list_sort_test.cpp ../PmergeMe*.cpp -o $SORT_TEST -Wall -Wextra -Werror -g \
&& "./$SORT_TEST" \
&& rm "./$SORT_TEST" \
&& echo "Sort OK"


