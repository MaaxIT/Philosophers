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

# Files
PROJECT			= Philosophers
NAME			= philo
SRC				= $(shell ls $(SRC_DIR))
OBJ				= $(SRC:.c=.o)
INC				= $(shell ls $(INC_DIR))

# Compiler options
CC				= gcc
CFLAGS			= -Wall -Wextra -Werror -pthread
INCFLAGS		= -I$(INC_DIR)/

# Bash commands
RM				= rm -rf
MKDIR			= mkdir -p

# Dependencies
OBJ_DEP			= $(addprefix $(OBJ_DIR)/, $(OBJ))
INC_DEP			= $(addprefix $(INC_DIR)/, $(INC))

# Rules
all: $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(INC_DEP)
	@$(MKDIR) $(OBJ_DIR)
	@echo "$(GREEN)Compiling	$(YELLOW)$(shell basename $<)$(NC)"
	@$(CC) $(CFLAGS) $(INCFLAGS) -c $< -o $@

$(NAME): $(OBJ_DEP) $(INC_DEP)
	@echo "$(BLUE)Building	$(PURPLE)$(NAME)$(NC)"
	@$(CC) $(CFLAGS) $(OBJ_DEP) -o $(NAME)
	@echo "$(GREEN)Program $(PURPLE)($(NAME))$(GREEN) has been successfully generated!$(NC)"

clean:
	@echo "$(RED)Removing	$(PURPLE)$(PROJECT) $(YELLOW)*.o$(NC)"
	@$(RM) $(OBJ_DIR)

fclean: clean
	@echo "$(RED)Removing	$(PURPLE)$(NAME)$(NC)"
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re