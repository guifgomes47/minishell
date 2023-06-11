# Target and Source Files
NAME = minishell

SRCS =	src/main.c \
		src/builtins/env.c \
		src/main_utils/init_loop.c \
		src/main_utils/main_utils.c \
		src/parsing/init_parsing.c \
		src/prompt/prompt.c \
		src/prompt/check_prompt.c \
		src/utils/create_list.c \
		src/utils/tokenize.c \
		src/lexer/lexer.c

# Source Directories
VPATH =	src: \
		src/builtins: \
		src/main_utils: \
		src/parsing: \
		src/prompt: \
		src/utils: \
		src/lexer

# Compiler and Flags
CC = cc
CFLAGS = -Wall -Wextra -Werror -I include -g3
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

leak:
	valgrind -q --leak-check=full --show-leak-kinds=all --trace-children=yes \
	./minishell

.PHONY: all clean fclean re libft