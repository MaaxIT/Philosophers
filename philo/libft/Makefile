# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mpeharpr <mpeharpr@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/09 17:51:18 by mpeharpr          #+#    #+#              #
#    Updated: 2022/05/19 11:40:29 by mpeharpr         ###   ########.fr        #
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

NAME = libft.a
INC = libft.h

SRCS_MENDA = 	ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
				ft_strlen.c ft_memset.c ft_memchr.c ft_memcmp.c ft_bzero.c ft_memcpy.c ft_memmove.c \
				ft_strlcpy.c ft_strlcat.c ft_strrchr.c ft_toupper.c ft_tolower.c ft_strchr.c \
				ft_strncmp.c ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c \
				ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c \
				ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c \
				ft_putnbr_fd.c

SRCS_BONUS = 	ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c \
				ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c

OBJS_MENDA = $(SRCS_MENDA:.c=.o)
OBJS_BONUS = $(SRCS_BONUS:.c=.o)

all: $(NAME)

$(NAME):
	@echo "$(BLUE)Building	$(PURPLE)$(NAME)$(NC)"
	@gcc -Wall -Wextra -Werror -Iinc/ -c $(SRCS_MENDA)
	@ar rcs $(NAME) $(OBJS_MENDA)
	@ranlib $(NAME)
	@echo "$(CYAN)Built		$(PURPLE)$(NAME)$(NC)"

bonus: $(OBJS_MENDA) $(OBJS_BONUS)
	@ar rcs $(NAME) $(OBJS_MENDA) $(OBJS_BONUS)

clean:
	@echo "$(RED)Removing	$(PURPLE)Libft $(YELLOW)*.o$(NC)"
	@rm -rf $(OBJS_MENDA) $(OBJS_BONUS)

fclean: clean
	@echo "$(RED)Removing	$(PURPLE)$(NAME)$(NC)"
	@rm -f $(NAME)

re: fclean all
