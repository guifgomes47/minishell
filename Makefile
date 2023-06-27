# Target and Source Files
NAME = minishell

SRCS =	src/main.c \
		src/utils/pwd_utils.c \
		src/utils/init_data.c \
		src/utils/free_memory.c \
		src/utils/fd_utils.c \
		src/utils/export_utils.c \
		src/utils/exec_utils.c \
		src/utils/env_utils.c \
		src/parsing/split_input.c \
		src/parsing/process_input.c \
		src/parsing/parser.c \
		src/parsing/parser_var.c \
		src/parsing/parser_utils.c \
		src/parsing/parser_redirect.c \
		src/parsing/parser_input.c \
		src/parsing/parser_error.c \
		src/parsing/handle_redirect.c \
		src/builtins/unset.c \
		src/builtins/signal.c \
		src/builtins/pwd.c \
		src/builtins/pipe.c \
		src/builtins/export.c \
		src/builtins/exit.c \
		src/builtins/exec.c \
		src/builtins/env.c \
		src/builtins/echo.c \
		src/builtins/cd.c \

# Source Directories
VPATH =	src: \
		src/builtins: \
		src/parsing: \
		src/utils \


# Compiler and Flags
CC = cc
CFLAGS =  -Wall -Wextra -Werror -I include -g3
LDFLAGS = -L lib/libft -lft -lreadline

OBJ_DIR = obj
OBJS = $(addprefix $(OBJ_DIR)/,$(notdir $(SRCS:.c=.o)))

# Clean
RM = rm -rf

# Colors for Terminal Output
COLOR_RED = \e[0;31m
COLOR_GREEN = \e[0;32m
COLOR_PURPLE = \e[0;35m
COLOR_WHITE = \e[0;37m

# Default Target
all: $(OBJ_DIR) $(NAME)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS) | libft
	$(CC) $(CFLAGS) $(OBJS) $(LDFLAGS) -o $(NAME)

# Libft Target
libft:
	@printf "$(COLOR_RED)Making $(COLOR_PURPLE)Libft$(COLOR_WHITE) ...\n"
	$(MAKE) -C lib/libft

# Clean Targets
clean:
	@printf "$(COLOR_RED)Cleaning $(COLOR_PURPLE)Libft$(COLOR_WHITE) objects...\n"
	$(MAKE) -C lib/libft clean
	@printf "$(COLOR_GREEN)Done!\n$(COLOR_WHITE)"

	@printf "$(COLOR_RED)Cleaning $(COLOR_PURPLE)$(NAME)$(COLOR_WHITE) objects...\n"
	$(RM) $(OBJ_DIR)
	@printf "$(COLOR_GREEN)Done!\n$(COLOR_WHITE)"

fclean: clean
	@printf "$(COLOR_RED)Cleaning $(COLOR_PURPLE)Libft\n$(COLOR_WHITE)"
	$(MAKE) -C lib/libft fclean
	@printf "$(COLOR_GREEN)Done!\n$(COLOR_WHITE)"

	@printf "$(COLOR_RED)Cleaning $(COLOR_PURPLE)$(NAME)\n$(COLOR_WHITE)"
	$(RM) $(NAME)
	@printf "$(COLOR_GREEN)Done!\n$(COLOR_WHITE)"

# Rebuild Target
re: fclean all

# Additional Targets
norma:
	@clear
	@norminette $(INC_PATH) $(SRC_PATH) | grep Error || true

valg:
	valgrind -q --leak-check=full --show-leak-kinds=all --trace-children=yes \
	./minishell

.PHONY: all clean fclean re libft