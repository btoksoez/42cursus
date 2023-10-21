# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: btoksoez <btoksoez@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/08 14:20:21 by btoksoez          #+#    #+#              #
#    Updated: 2023/10/18 16:28:49 by btoksoez         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = $(shell find . -name 'ft_*.c' ! -name 'ft_lst*.c')
OBJS = $(SRCS:.c=.o)

SRCSBNS = $(shell find . -name 'ft_*.c')
OBJSBNS = $(SRCSBNS:.c=.o)

NAME = libft.a

CC = cc

HEADER = libft.h

CC_FLAGS = -Wall -Werror -Wextra

%.o: %.c
	@$(CC) $(CC_FLAGS) -c $< -o $@

$(NAME): $(OBJS)
	@ar rc $(NAME) $(OBJS)
	@echo "$(NAME) created."

all: $(NAME)

clean:
	@rm -rf $(OBJS) $(OBJSBNS)
	@echo "$(OBJS) deleted."

fclean: clean
	rm -f $(NAME)

re: fclean all

bonus: $(OBJSBNS)
	@ar rc $(NAME) $(OBJSBNS)
	@echo "$(NAME) Bonus created."


.PHONY: clean fclean re all bonus
