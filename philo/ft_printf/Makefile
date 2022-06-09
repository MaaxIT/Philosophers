# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mpeharpr <mpeharpr@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/17 11:19:27 by mpeharpr          #+#    #+#              #
#    Updated: 2022/05/19 10:51:48 by mpeharpr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Colors constants
NC				= \033[m
RED				= \033[0;31m
GREEN			= \033[1;32m
YELLOW			= \033[1;33m
BLUE			= \033[0;34m
PURPLE			= \033[1;35m
CYAN			= \033[1;36m

NAME = libftprintf.a

HEADER = ft_printf.h
SRCS = ft_printf.c ft_putnbr_base.c ft_types.c ft_utils.c
OBJS = $(SRCS:.c=.o)

$(NAME):
	@echo "$(BLUE)Building	$(PURPLE)$(NAME)$(NC)"
	@gcc -Wall -Wextra -Werror -Iinc/ -c $(SRCS)
	@ar rcs $(NAME) $(OBJS)
	@ranlib $(NAME)
	@echo "$(CYAN)Built		$(PURPLE)$(NAME)$(NC)"

all: $(NAME)

clean:
	@echo "$(RED)Removing	$(PURPLE)Printf $(YELLOW)*.o$(NC)"
	@rm -rf $(OBJS)

fclean: clean
	@echo "$(RED)Removing	$(PURPLE)$(NAME)$(NC)"
	@rm -f $(NAME)

re: fclean all
