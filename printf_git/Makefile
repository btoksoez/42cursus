# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: btoksoez <btoksoez@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/08 14:20:21 by btoksoez          #+#    #+#              #
#    Updated: 2023/10/25 11:29:25 by btoksoez         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ft_printf.c ft_putnbr_base.c ft_print_hex.c

OBJS = $(SRCS:.c=.o)

NAME = libftprintf.a

CC = cc

LIBFTPATH = ./libft
LIBFT = $(LIBFTPATH)/libft.a

CFLAGS = -Wall -Werror -Wextra

%.o: %.c
	@$(CC) $(CC_FLAGS) -c $< -o $@

$(NAME): $(LIBFT) $(OBJS)
	cp $(LIBFT) $(NAME)
	@ar rc $(NAME) $(OBJS)
	@echo "$(NAME) created."

all: $(NAME)

$(LIBFT):
	make -C $(LIBFTPATH) all

clean:
	make -C $(LIBFTPATH) clean
	@rm -rf $(OBJS)
	@echo "$(OBJS) & $(LIBFT) deleted."

fclean: clean
	make -C $(LIBFTPATH) fclean
	rm -rf $(NAME)

re: fclean all

.PHONY: clean fclean re all libft
