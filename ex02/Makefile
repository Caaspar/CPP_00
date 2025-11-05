# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cgerner <cgerner@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/09 16:41:23 by cgerner           #+#    #+#              #
#    Updated: 2025/07/11 15:38:14 by cgerner          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = account

SRCS = Account.cpp Tests.cpp

CC = c++

CFLAGS = -Wall -Wextra -Werror -std=c++98

MY_OBJECTS = $(SRCS:.cpp=.o)

GREEN = \033[1;32m
PINK = \033[1;35m
RED = \033[1;31m
RESET = \033[0m

.cpp.o:
	@echo "$(PINK)Linking... 💭​​$(RESET) $(GREEN)$<$(RESET)"
	@$(CC) $(CFLAGS) -c -o $@ $<

$(NAME): $(MY_OBJECTS)
	@echo "$(PINK)Compiled ✅​🥇​​$(RESET) $(GREEN)$(NAME)$(RESET)"
	@$(CC) $(CFLAGS) -o $(NAME) $(MY_OBJECTS)

all: $(NAME)

clean:
	@echo "$(RED)Cleaning object files... 🚸​​$(RESET)"
	@rm -f $(MY_OBJECTS)

fclean: clean
	@echo "$(RED)Removing executable... 🚸​​$(RESET)"
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re