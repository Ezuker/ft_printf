_BOLD=$'\033[1m
_UNDER=$'\033[4m
_REV=$'\033[7m
_END=$'\033[0m

# Colors
_GREY=$'\033[30m
_RED=$'\033[31m
_GREEN=$'\033[32m
_YELLOW=$'\033[33m
_BLUE=$'\033[34m
_PURPLE=$'\033[35m
_CYAN=$'\033[36m
_WHITE=$'\033[37m

# Inverted, i.e. colored backgrounds
_IGREY=$'\033[40m
_IRED=$'\033[41m
_IGREEN=$'\033[42m
_IYELLOW=$'\033[43m
_IBLUE=$'\033[44m
_IPURPLE=$'\033[45m
_ICYAN=$'\033[46m
_IWHITE=$'\033[47m

SRC = \
	src/main.c \
	src/parsing/parse.c \
	src/parsing/flags.c \
	src/parsing/width.c \
	src/parsing/precision.c \
	src/parsing/length.c \
	src/parsing/type.c \
	src/utils/struct_init.c \
	src/utils/ft_atoi.c \
	src/utils/ft_strlen.c \
	src/utils/ft_itoa.c \
	src/utils/ft_strdup.c \
	src/utils/ft_wcstombs.c \
	src/utils/ft_ftoa.c \
	src/utils/ft_strjoin.c \
	src/utils/ft_roundf.c \
	src/utils/ft_recalloc.c \
	src/utils/ft_pow.c \
	src/utils/ft_nb_floating_digit.c \
	src/utils/ft_toupper.c \
	src/utils/ft_remove_zero.c \
	src/converter/converting.c \
	src/converter/decimal.c \
	src/converter/octal.c \
	src/converter/unsigned.c \
	src/converter/hexadecimal.c \
	src/converter/char.c \
	src/converter/string.c \
	src/converter/pointer.c \
	src/converter/float.c \
	src/converter/scientific.c \
	src/converter/shortest_float.c \
	src/converter/hexa_floating_point.c \


INCLUDES = \
	-I./include/ \

OBJ = $(SRC:%.c=$(BUILD_DIR)%.o)
BUILD_DIR = ./build/
CC = cc
CFLAGS = -Wall -Wextra -Werror -g
NAME = ft_printf
NORME_ERROR = $(shell norminette $(SRC) include/ | grep "Error" | wc -l)
BOOL_EXEC = 0
EXEC = ./$(NAME)
IS_COMPILING = 0

all: $(NAME)

$(NAME): $(OBJ)
	@echo
	@echo "$(_BOLD)$(_CYAN)Compiling ($(_RED)$@$(_CYAN))$(_END)"
	@echo
	@echo " $(_BOLD)$(_RED)$(NAME) : $(_END)$(_GREY) $(CC) $(OBJ) $(_END)"
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ)
	@echo
	@echo "$(_BOLD)$(_CYAN)Other ($(_RED)$@$(_CYAN))$(_END)"
	$(norme)
	@echo
	@ \
	if [ $(BOOL_EXEC) -eq 1 ]; then \
		@echo "$(_BOLD)$(_CYAN)Executing...$(_END)"; \
		@echo; \
		$(EXEC); \
	fi

$(BUILD_DIR)%.o: %.c
	@ \
	if [ $(IS_COMPILING) -eq 0 ]; then \
		echo; \
		echo "$(_BOLD)$(_CYAN)Entering ($(_RED)./src$(_CYAN))$(_END)"; \
		echo; \
	fi
	@$(eval IS_COMPILING = 1)
	@mkdir -p $(dir $@)
	@echo "$(_BOLD)$(_RED) $< : $(_END) $(_GREY) $(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@ $(_END)"
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

define norme =
	@echo
	@ \
	if [ $(NORME_ERROR) -eq 0 ]; then \
		echo "$(_BOLD)$(_GREEN) Norminette passed$(_END)"; \
	else \
		echo "$(_BOLD)$(_RED) Norminette error : $(NORME_ERROR)$(_END)"; \
	fi
endef

clean:
	@echo "$(_BOLD)$(_CYAN)Cleaning...$(_END)"
	@rm -rf $(BUILD_DIR)
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re valgrind
