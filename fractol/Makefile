# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: btoksoez <btoksoez@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/14 11:34:03 by btoksoez          #+#    #+#              #
#    Updated: 2024/03/14 11:59:20 by btoksoez         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Program name
NAME = fractol

# Compiler
CC = gcc

# Directories
LIBFTDIR = ./libft
LIBFT = $(LIBFTDIR)/libft.a

MLXDIR = ./minilibx-linux
MLX = $(MLXDIR)/libmlx.a

# Sources and Objects
SRCS = color.c events.c main.c init.c julia.c mandelbrot.c parse_args.c render.c mandelbox.c
OBJS = $(SRCS:.c=.o)

# Includes
INC = -I$(LIBFTDIR) -I$(MLXDIR)

# Compiler flags
CFLAGS = -g -Wall -Werror -Wextra

# Linker flags
LDFLAGS = -L$(MLXDIR) -lmlx_Linux -L$(LIBFTDIR) -lft -L/usr/X11/lib -lX11 -lXext -lm

all: $(NAME) $(LIBFT) $(MLX)

$(NAME): $(OBJS) $(LIBFT) $(MLX)
	@echo "Creating $(NAME)"
	@$(CC) $(CFLAGS) $(OBJS) $(LDFLAGS) $(INC) -o $(NAME)
	@echo "$(NAME) created."

$(LIBFT):
	@make -sC $(LIBFTDIR)

$(MLX):
	@make -sC $(MLXDIR)

clean:
	@$(MAKE) clean -C $(LIBFTDIR)
	@$(MAKE) clean -C $(MLXDIR)
	@rm -f $(OBJS)
	@echo "Object files cleaned."

fclean: clean
	@$(MAKE) fclean -C $(LIBFTDIR)
	@rm -f $(NAME)
	@echo "$(NAME) deleted."

re: fclean all

.PHONY: all clean fclean re
