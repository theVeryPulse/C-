SORT_TEST=sort_test

c++ sort_test.cpp ../PmergeMe.cpp -o $SORT_TEST -Wall -Wextra -Werror \
&& "./$SORT_TEST" | echo "Checking..."\
&& rm "./$SORT_TEST" \
&& echo "Sort OK"


