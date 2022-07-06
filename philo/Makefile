# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thbierne <thbierne@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/08 11:15:19 by thbierne          #+#    #+#              #
#    Updated: 2022/06/17 14:42:37 by thbierne         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

SRCS = srcs/main.c					\
		srcs/utils0.c				\
		srcs/utils1.c				\
		srcs/init_list.c			\
		srcs/routine.c				\
		srcs/alloc_philo.c			\
		srcs/time.c					\

OBJS = $(SRCS:.c=.o)

CC = clang

CFLAGS = -Wall -Wextra -Werror -pthread

RM = rm -f

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

clean:
	$(RM) srcs/*.o

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
