# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thbierne <thbierne@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/29 15:39:57 by thbierne          #+#    #+#              #
#    Updated: 2022/09/02 13:12:07 by thbierne         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

SRCS = srcs/philo.c							\
		srcs/philo_utils.c					\
		srcs/time.c							\
		srcs/ft_sleep.c						\
		srcs/free.c							\
		srcs/management_thread.c			\
		srcs/alloc_philo.c					\
		srcs/routine.c						\
		srcs/display.c						\
		srcs/alloc_arg.c					\

OBJS = $(SRCS:.c=.o)

CC = cc

CFLAGS = -Wall -Wextra -Werror -pthread

RM = rm -f

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
