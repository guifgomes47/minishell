NAME = libft.a

INC_PATH = include/
SRC_PATH = src/
OBJ_PATH = obj/
OBJ_DIRS = obj/ obj/ft_printf/

CC = cc
CFLAGS = -Wall -Werror -Wextra
CFLAGS += -g -I $(INC_PATH)
AR = ar -rcs
RM = rm -rf

FILES = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c \
	ft_isprint.c ft_strlen.c ft_bzero.c ft_memset.c \
	ft_memcpy.c ft_memmove.c ft_strlcpy.c ft_strlcat.c \
	ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c \
	ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c \
	ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c \
	ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c \
	ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c \
	ft_putendl_fd.c ft_putnbr_fd.c ft_putchar.c ft_strcmp.c \
	ft_strncjoin.c ft_split_cmd.c ft_ulitoa_base.c ft_isspace.c \
	ft_atol.c get_next_line.c ft_printf/ft_printf.c \
	ft_printf/ft_print_digits.c ft_printf/ft_print_c_str.c \
	ft_lstnew.c ft_lstadd_back.c ft_lstrevsplit.c ft_lstclear.c

SRC = $(addprefix $(SRC_PATH), $(FILES))
OBJ = $(addprefix $(OBJ_PATH), $(FILES:.c=.o))

COLOR_RED = \e[0;31m
COLOR_GREEN = \e[0;32m
COLOR_YELLOW = \e[0;33m
COLOR_BLUE = \e[0;34m
COLOR_PURPLE = \e[0;35m
COLOR_CYAN = \e[0;36m
COLOR_WHITE = \e[0;37m

all: $(NAME)

$(OBJ_DIRS):
	mkdir -p $@

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ_DIRS) $(OBJ)
	@$(AR) $(NAME) $(OBJ)
	@printf "$(COLOR_PURPLE)$(NAME)$(COLOR_GREEN) compiled successfully!\n$(COLOR_WHITE)"

clean:
	@$(RM) $(OBJ_DIRS)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

norm:
	@clear
	@norminette $(INC_PATH) $(SRC_PATH) | grep Error || true

.PHONY: all clean fclean re norm