# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: btoksoez <btoksoez@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/04 11:34:08 by btoksoez          #+#    #+#              #
#    Updated: 2024/05/10 11:28:25 by btoksoez         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = harlFilter
CXX = g++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = main.cpp Harl.cpp
OBJS = $(addprefix obj/, $(SRCS:.cpp=.o))
OBJDIR = obj

# Colours
GREEN = \033[1;32m
ORANGE = \033[1;33m
RED = \033[1;31m
CYAN = \033[1;36m
WHITE = \033[1;37m
GREY = \033[1;90m
RESET = \033[0m

all: $(NAME)

$(OBJDIR)/%.o: %.cpp
	@mkdir -p $(OBJDIR)
	@echo "$(GREY)Compiling...	$(WHITE)$<"
	@$(CXX) $(CXXFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	@$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)
	@echo "$(CYAN)make$(RESET)   $@ $(GREEN)[OK]$(RESET)"

clean:
	@$(RM) -r $(OBJDIR)
	@echo "$(ORANGE)$@$(RESET)  $(NAME) $(GREEN)[OK]$(RESET)"

fclean: clean
	@$(RM) $(NAME)
	@echo "$(RED)$@$(RESET) $(NAME) $(GREEN)[OK]$(RESET)"

re: fclean all

.PHONY: all clean fclean re
