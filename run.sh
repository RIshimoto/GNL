#!/bin/bash

gcc -g -Wall -Wextra -Werror -D BUFFER_SIZE=9999 get_next_line_bonus.c get_next_line_utils_bonus.c *.h gnl_main.c
./a.out
