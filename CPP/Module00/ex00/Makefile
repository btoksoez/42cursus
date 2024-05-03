NAME = megaphone
CXX = g++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = megaphone.cpp
OBJS = $(SRCS:.cpp=.o)

# Colours
GREEN = \033[1;32m
ORANGE = \033[1;33m
RED = \033[1;31m
CYAN = \033[1;36m
WHITE = \033[1;37m
GREY = \033[1;90m
RESET = \033[0m

all: $(NAME)

%.o: %.cpp
	@echo "$(GREY)Compiling...	$(WHITE)$<"
	@$(CXX) $(CXXFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	@$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)
	@echo "$(CYAN)make$(RESET)   $@ $(GREEN)[OK]$(RESET)"

clean:
	@$(RM) $(OBJS)
	@echo "$(ORANGE)$@$(RESET)  $(NAME) $(GREEN)[OK]$(RESET)"

fclean: clean
	@$(RM) $(NAME)
	@echo "$(RED)$@$(RESET) $(NAME) $(GREEN)[OK]$(RESET)"

re: fclean all

.PHONY: all clean fclean re
