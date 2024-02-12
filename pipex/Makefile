# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: btoksoez <btoksoez@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/08 14:20:21 by btoksoez          #+#    #+#              #
#    Updated: 2024/02/12 16:55:11 by btoksoez         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = main.c	\
		shell_return.c	\
		error_handling.c	\
		check_cmds.c	\


NAME = pipex

CC = cc

LIBFTDIR = ./libft
LIBFT = $(LIBFTDIR)/libft.a

CFLAGS = -g -Wall -Werror -Wextra

$(NAME): $(SRCS) $(LIBFT)
	@echo "Creating $(NAME)"
	@$(CC) $(CFLAGS) $(SRCS) $(LIBFT) -o $(NAME)
	@echo "$(NAME) created."

all: $(NAME)

$(LIBFT):
	@$(MAKE) -sC $(LIBFTDIR)

clean:
	make -C $(LIBFTDIR) clean
	@echo "$(LIBFT) deleted."

fclean: clean
	make -C $(LIBFTDIR) fclean
	rm -rf $(NAME)
	@echo "$(LIBFT) & $(NAME) deleted."

re: fclean all

.PHONY: clean fclean re all libft
