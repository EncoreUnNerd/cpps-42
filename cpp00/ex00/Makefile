NAME = megaphone

SRCS = megaphone.cpp

OBJS = $(SRCS:.c=.o)

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

fclean:
	@rm -f $(NAME)
	@printf "$(GREEN)[✨] fully cleaned$(RESET)\n"

.c.o:
	@$(CC) $(CFLAGS) -c $< -o $@

re: fclean all

.PHONY: all fclean re