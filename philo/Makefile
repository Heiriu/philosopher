# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thbierne <thbierne@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/08 11:15:19 by thbierne          #+#    #+#              #
#    Updated: 2022/07/14 14:33:11 by thbierne         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

SRCS = srcs/main.c								\
		srcs/ft_check_arg.c						\
		srcs/utils0.c							\
		srcs/utils1.c							\
		srcs/print_add_delete_philo.c			\
		srcs/routine.c							\
		srcs/thread_management.c				\
		srcs/time.c								\

OBJS_O = srcs/objs/main.o						\
			srcs/objs/ft_check_arg.o			\
			srcs/objs/utils0.o					\
			srcs/objs/utils1.o					\
			srcs/objs/print_add_delete_philo.o	\
			srcs/objs/routine.o					\
			srcs/objs/thread_management.o		\
			srcs/objs/time.o					\

OBJS = $(SRCS:.c=.o)

D_OBJS = srcs/objs/

CC = clang

CFLAGS = -Wall -Wextra -Werror -pthread

RM = rm -f

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)
	mv $(OBJS) $(D_OBJS)

clean:
	$(RM) $(OBJS_O)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
