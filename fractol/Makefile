# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: btoksoez <btoksoez@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/08 14:20:21 by btoksoez          #+#    #+#              #
#    Updated: 2024/03/13 14:06:21 by btoksoez         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Program name
NAME = fractol

# Compiler
CC		= gcc
CFLAGS	= -g -Wall -Werror -Wextra

# Libft
LIBFT_PATH = libft/
LIBFT_NAME = libft.a
LIBFT = $(LIBFT_PATH)$(LIBFT_NAME)

# Minilibx
MLX_PATH	= minilibx-linux/
MLX_NAME	= libmlx.a
MLX 		= $(MLX_PATH)$(MLX_NAME)

# Additional libraries
ADDITIONAL_LIBS = -lm -lX11 -lXext

# Includes
INC	=	-I ./includes/\
		-I ./libft/\
		-I ./minilibx-linux/

# Sources
SRC_PATH	=	src/
SRC 		=	color.c	\
				events.c	\
				init.c	\
				julia.c	\
				main.c	\
				mandelbrot.c	\
				parse_args.c	\
				render.c
SRCS		= $(addprefix $(SRC_PATH), $(SRC))

# Objects
OBJ_PATH	= obj/
OBJ			= $(SRC:.c=.o)
Objects		= $(addprefix $(OBJ_PATH), $(OBJ))

all: $(MLX) $(LIBFT) $(NAME)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@$(CC) $(CFLAGS) -c $< -o $@ $(INC)

$(OBJS): $(OBJ_PATH)

$(OBJ_PATH):
	@mkdir $(OBJ_PATH)

$(MLX):
	@echo "Making MiniLibX..."
	@make -sC $(MLX_PATH)

$(LIBFT):
	@echo "Making Libft..."
	@make -sC $(LIBFT_PATH)

$(NAME): $(OBJS)
	@echo "Compiling fractol..."
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(MLX) $(LIBFT) $(INC) $(ADDITIONAL_LIBS)
	@echo "Fractol ready."

bonus: all

clean:
	@echo "Removing .o object files..."
	@rm -rf $(OBJ_PATH)
	@make clean -C $(MLX_PATH)
	@make clean -C $(LIBFT_PATH)

fclean: clean
	@echo "Removing fractol..."
	@rm -f $(NAME)
	@rm -f $(LIBFT_PATH)$(LIBFT_NAME)

re: fclean all

.PHONY: clean fclean re all
