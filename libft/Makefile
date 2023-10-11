# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: btoksoez <btoksoez@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/08 14:20:21 by btoksoez          #+#    #+#              #
#    Updated: 2023/10/08 14:46:34 by btoksoez         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = $(shell find . -name "ft_*.c")
OBJS = $(SRCS:.c=.o)

NAME = libft.a

CC = gcc

HEADER = libft.h

CC_FLAGS = -Wall -Werror -Wextra

%.o: %.c
	$(CC) $(CC_FLAGS) -c $< -o $@

$(NAME): $(OBJS) $(HEADER)
	ar rc $(NAME) $(OBJS)

all: $(NAME)

clean:
	rm -rf $(OBJS)

fclean:
	rm -f $(NAME)

re: fclean all
