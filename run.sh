#!/bin/bash

gcc -g -Wall -Wextra -Werror -D BUFFER_SIZE=9 get_next_line_bonus.c get_next_line_utils_bonus.c  gnl_main.c
#gcc -g -Wall -Wextra -Werror -D BUFFER_SIZE=9 get_next_line.c get_next_line_utils.c  gnl_main.c
./a.out
