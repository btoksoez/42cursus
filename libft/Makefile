# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: btoksoez <btoksoez@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/08 14:20:21 by btoksoez          #+#    #+#              #
#    Updated: 2023/10/14 14:45:54 by btoksoez         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = $(shell find . -name "ft_*.c")
OBJS = $(SRCS:.c=.o)

NAME = libft.a

CC = gcc

HEADER = libft.h

CC_FLAGS = -Wall -Werror -Wextra

%.o: %.c
	@$(CC) $(CC_FLAGS) -c $< -o $@

$(NAME): $(OBJS)
	@ar rc $(NAME) $(OBJS)
	@echo "$(NAME) created."

all: $(NAME)

clean:
	@rm -rf $(OBJS)
	@echo "$(OBJS) deleted."

fclean:
	@rm -f $(NAME)
	@echo "$(NAME) deleted."

re: fclean all

.PHONY: clean fclean re all
