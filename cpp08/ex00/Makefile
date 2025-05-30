NAME = easyfind

SRCS = main.cpp

OBJS = $(SRCS:.cpp=.o)

CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
GREEN = \033[32m
BLUE = \033[34m
RESET = \033[0m

all: $(NAME)

$(NAME): $(OBJS)
	@printf "$(BLUE)[💭] $(NAME) compiling$(RESET)\n"
	@$(CC) $(CFLAGS) -o $@ $^
	@printf "$(GREEN)[✅] $(NAME) compiled$(RESET)\n"

clean:
	@printf "$(GREEN)[🧹] cleaning$(RESET)\n"
	@rm -f $(OBJS)
	@printf "$(GREEN)[✨] cleaned$(RESET)\n"

fclean: clean
	@rm -f $(NAME)
	@printf "$(GREEN)[✨] fully cleaned$(RESET)\n"

.cpp.o:
	@$(CC) $(CFLAGS) -c $< -o $@

re: fclean all

.PHONY: all clean fclean re
