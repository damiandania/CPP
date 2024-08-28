# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: damian <damian@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/21 10:58:01 by ddania-c          #+#    #+#              #
#    Updated: 2024/03/30 00:00:38 by damian           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	Form2

#FLAGS_________________________________________________________________________

CC		=	c++
CFLAGS	=	-Werror -Wextra -Wall -std=c++98

OBJ_PATH	=	./objects/
INC_PATH	=	./includes/

#SOURCES_______________________________________________________________________

SRC_PATH	=	./sources/
SRC		=	main.cpp					\
			Bureaucrat.cpp				\
			AForm.cpp					\
			ShrubberyCreationForm.cpp	\
			PresidentialPardonForm.cpp	\
			RobotomyRequestForm.cpp


SRCS	= $(addprefix $(SRC_PATH), $(SRC))

OBJ		= $(SRC:.cpp=.o)
OBJS	= $(addprefix $(OBJ_PATH), $(OBJ))
INC		= -I $(INC_PATH)

#COLORS________________________________________________________________________

GREEN	=	\033[0;32m
RED		=	\033[0;31m
WHITE	=	\033[0;97m
RESET	=	\033[0m
YELLOW 	=	\033[0;93m

#MAIN_RULE_____________________________________________________________________

all: $(OBJ_PATH) $(NAME)

$(NAME): $(OBJS)
	@echo -n "$(YELLOW)Compiling	${WHITE}→	$(YELLOW)$(NAME) with c++98$(RESET) "
	@$(CC) $(CFLAGS) $(OBJS) -o $@ $(INC)
	@echo "$(GREEN)[ok]✓$(RESET)"

#OBJECT_RULE___________________________________________________________________

$(OBJ_PATH):
	@mkdir -p $(OBJ_PATH)

$(OBJ_PATH)%.o: $(SRC_PATH)%.cpp
	@$(CC) $(CFLAGS) -c $< -o $@ $(INC)

#CLEAN_RULE____________________________________________________________________

clean:
	@echo -n "$(RED)Deleting	${WHITE}→	$(RED)$(NAME) objects$(RESET) "
	@rm -rf $(OBJ_PATH)
	@echo "$(GREEN)[ok]$(RED)✗$(RESET)"

fclean: clean
	@echo -n "$(RED)Deleting	${WHITE}→	$(RED)$(NAME) executable$(RESET) "
	@rm -f $(NAME)
	@echo "$(GREEN)[ok]$(RED)✗$(RESET)"

re: fclean all

#SPEC__________________________________________________________________________

.PHONY: all re clean fclean
