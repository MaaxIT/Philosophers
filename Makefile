# Philosophers - A philosophy project (not really but you get the idea)
# Use this makefile to compile the project

# Colors constants
NC				= \033[m
RED				= \033[0;31m
GREEN			= \033[1;32m
YELLOW			= \033[1;33m
BLUE			= \033[0;34m
PURPLE			= \033[1;35m
CYAN			= \033[1;36m

# Directories
INC_DIR			= inc
SRC_DIR			= src
OBJ_DIR			= obj
LIB_DIR			= lib
PRINTF_DIR		= ft_printf
LIBFT_DIR		= libft

# Files
PROJECT			= Philosophers
NAME			= philo
SRC				= $(shell ls $(SRC_DIR))
OBJ				= $(SRC:.c=.o)
INC				= $(shell ls $(INC_DIR))

# Libft files
LIBFT_INC_DIR	= $(LIBFT_DIR)/$(INC_DIR)
LIBFT_INC		= $(shell ls $(LIBFT_INC_DIR))
LIBFT_LIB		= $(LIBFT_DIR)/libft.a

# Printf files
PRINTF_INC_DIR	= $(PRINTF_DIR)/$(INC_DIR)
PRINTF_INC		= $(shell ls $(PRINTF_INC_DIR))
PRINTF_LIB		= $(PRINTF_DIR)/libftprintf.a

# Compiler options
CC				= cc
CFLAGS			= -Wall -Wextra -Werror -pthread
INCFLAGS		= -I $(INC_DIR) -I $(LIBFT_INC_DIR) -I $(PRINTF_INC_DIR)

# Bash commands
RM				= rm -rf
MKDIR			= mkdir -p

# Dependencies
OBJ_DEP			= $(addprefix $(OBJ_DIR)/, $(OBJ))
LIB_DEP			= $(LIBFT_LIB) $(PRINTF_LIB)
LIBFT_DEP		= $(addprefix $(LIBFT_INC_DIR)/, $(LIBFT_INC))
PRINTF_DEP		= $(addprefix $(PRINTF_INC_DIR)/, $(PRINTF_INC))
INC_DEP			= $(addprefix $(INC_DIR)/, $(INC)) $(LIBFT_DEP) $(PRINTF_DEP)

# Rules
all: $(NAME)

$(NAME): $(OBJ_DEP) $(INC_DEP)
	@echo "$(BLUE)Building	$(PURPLE)$(NAME)$(NC)"
	@make -C $(LIBFT_DIR)
	@make -C $(PRINTF_DIR)
	@$(CC) $(CFLAGS) $(LIBFLAGS) $(LIB_DEP) $(OBJ_DEP) -o $(NAME)
	@echo "$(GREEN)Program $(PURPLE)($(NAME))$(GREEN) has been successfully generated!$(NC)"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(INC_DEP)
	@$(MKDIR) $(OBJ_DIR)
	@echo "$(GREEN)Compiling	$(YELLOW)$(shell basename $<)$(NC)"
	@$(CC) $(CFLAGS) $(INCFLAGS) -c -o $@ $<

clean:
	@echo "$(RED)Removing	$(PURPLE)$(PROJECT) $(YELLOW)*.o$(NC)"
	@make clean -C $(LIBFT_DIR)
	@make clean -C $(PRINTF_DIR)
	@$(RM) $(OBJ_DIR)

fclean: clean
	@echo "$(RED)Removing	$(PURPLE)$(NAME)$(NC)"
	@make fclean -C $(LIBFT_DIR)
	@make fclean -C $(PRINTF_DIR)
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re