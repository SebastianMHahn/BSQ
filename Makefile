# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: nloomans <nloomans@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2019/02/18 13:13:48 by nloomans       #+#    #+#                 #
#    Updated: 2019/02/27 13:15:01 by nloomans      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

CC=gcc
CFLAGS=-Wall -Wextra -Werror

NAME=bsq
SRCS=	src/ft.c \
		src/free2d.c \
		src/read.c \
		src/parse.c \
		src/print_solution.c \
		src/partial_sum_grid.c \
		src/find_max_square.c \
		src/main.c
OBJS=	$(patsubst src/%.c,obj/%.o,$(SRCS))
HEADERS=includes/ft.h \
		includes/free2d.h \
		includes/structs.h \
		includes/parse.h \
		includes/read.h \
		includes/find_max_square.h \
		includes/partial_sum_grid.h \
		includes/print_solution.h

all: $(NAME)

obj/%.o: src/%.c $(HEADERS)
	mkdir -p obj
	$(CC) $(CFLAGS) -I includes -o $@ -c $<

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -f $(OBJS)
	rm -rf obj

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
