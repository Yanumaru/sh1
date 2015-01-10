#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ykichena <ykichena@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/16 21:23:08 by ykichena          #+#    #+#              #
#    Updated: 2014/11/16 21:23:11 by ykichena         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = Minishell3

C =	main.c \
	get_next_line.c \
	ft_command.c \
	ft_catch.c \
	ft_built_cd.c \
	ft_echo.c \
	redright.c \
	search_cmd.c \
	tools.c

FLAG = -Wall -Wextra -Werror

MKLIB = make -C libft/
LIBFT= -L./libft/ -lft

RM = /bin/rm -f

all: $(NAME)

$(NAME):
	@$(MKLIB)
	@echo "Makefile: $(NAME): creating..."
	@cc -o $(NAME) $(FLAG) $(C) $(LIBFT) -I libft/includes
	@echo "Makefile: $(NAME): created."

clean:
	@$(MKLIB) clean
	@echo "Makefile: $(NAME): clean"

fclean: clean
	@$(MKLIB) fclean
	@$(RM) $(NAME)
	@echo "Makefile: $(NAME): fclean"

re: fclean all

.PHONY: all clean fclean re
