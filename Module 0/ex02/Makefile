# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ddania-c <ddania-c@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/21 14:28:08 by ddania-c          #+#    #+#              #
#    Updated: 2024/02/21 14:34:56 by ddania-c         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	Account-test

#SOURCES_______________________________________________________________________

SRC		=	tests.cpp	\
			Account.cpp

#OBJECT________________________________________________________________________

OBJ		=	$(SRC:.cpp=.o)
CC		=	g++

#FLAGS_________________________________________________________________________

CFLAGS	=	-Werror -Wextra -Wall -std=c++98

#COLORS________________________________________________________________________

GREEN	=	\033[0;32m
RED		=	\033[0;31m
WHITE	=	\033[0;97m
RESET	=	\033[0m
YELLOW 	=	\033[0;93m

#MAIN_RULE_____________________________________________________________________

all: $(NAME)

$(NAME): $(OBJ)
	@echo -n "$(YELLOW)Compiling	${WHITE}→	$(YELLOW)$(NAME) with c++98$(RESET) "
	@$(CC) $(CFLAGS) $(OBJ) -o $@ -I .
	@echo "$(GREEN)[ok]✓$(RESET)"

#OBJECT_RULE___________________________________________________________________

%.o: %.cpp
	@$(CC) $(CFLAGS) -c $< -o $@ -I .

#CLEAN_RULE____________________________________________________________________

clean:
	@echo -n "$(RED)Deleting	${WHITE}→	$(RED)$(NAME) objects$(RESET) "
	@rm -rf *.o
	@echo "$(GREEN)[ok]$(RED)✗$(RESET)"

fclean: clean
	@echo -n "$(RED)Deleting	${WHITE}→	$(RED)$(NAME) executable$(RESET) "
	@rm -f $(NAME)
	@echo "$(GREEN)[ok]$(RED)✗$(RESET)"

re: fclean all

.PHONY: all re clean fclean
