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
	src/ft_printf.c \
	src/ft_puthexa.c \
	src/ft_printf_utils.c \
	src/ft_printf_unsigned.c \
	src/ft_ppercent.c \
	src/ft_utils.c \
	src/ft_utilslibft.c \

SRC_BONUS = \
	src_bonus/main.c \
	src_bonus/parsing/parse.c \
	src_bonus/parsing/flags.c \
	src_bonus/parsing/width.c \
	src_bonus/parsing/precision.c \
	src_bonus/parsing/length.c \
	src_bonus/parsing/type.c \
	src_bonus/utils/struct_init.c \
	src_bonus/utils/ft_atoi.c \
	src_bonus/utils/ft_strlen.c \
	src_bonus/utils/ft_itoa.c \
	src_bonus/utils/ft_strdup.c \
	src_bonus/utils/ft_wcstombs.c \
	src_bonus/utils/ft_ftoa.c \
	src_bonus/utils/ft_strjoin.c \
	src_bonus/utils/ft_roundf.c \
	src_bonus/utils/ft_pow.c \
	src_bonus/utils/ft_nb_floating_digit.c \
	src_bonus/utils/ft_toupper.c \
	src_bonus/utils/ft_remove_zero.c \
	src_bonus/utils/ft_substr.c \
	src_bonus/utils/ft_zeroflag.c \
	src_bonus/converter/converting.c \
	src_bonus/converter/decimal.c \
	src_bonus/converter/octal.c \
	src_bonus/converter/unsigned.c \
	src_bonus/converter/hexadecimal.c \
	src_bonus/converter/char.c \
	src_bonus/converter/string.c \
	src_bonus/converter/pointer.c \
	src_bonus/converter/float.c \
	src_bonus/converter/scientific.c \
	src_bonus/converter/shortest_float.c \
	src_bonus/converter/hexa_floating_point.c \
	src_bonus/converter/flag_g_to_char.c \
	src_bonus/writer/writing.c \
	src_bonus/writer/precision_write.c \
	src_bonus/writer/flags.c \


INCLUDES = \
	-I./include/ \

INCLUDES_BONUS = \
	-I./include_bonus/ \

OBJ = $(SRC:%.c=$(BUILD_DIR)%.o)
OBJ_BONUS = $(SRC_BONUS:%.c=$(BUILD_DIR_BONUS)%.o)
BUILD_DIR = ./build/
BUILD_DIR_BONUS = ./build_bonus/
CC = cc
CFLAGS = -g -Wall -Werror -Wextra
NAME = libftprintf.a
NAME_BONUS = libftprintf.a
NORME_ERROR = $(shell norminette $(SRC) include/ | grep "Error" | wc -l)
BOOL_EXEC = 0
EXEC = ./$(NAME)
IS_COMPILING = 0

all: $(NAME)

$(NAME): $(OBJ)
	@echo
	@echo "$(_BOLD)$(_CYAN)Compiling ($(_RED)$@$(_CYAN))$(_END)"
	@echo
	@echo "$(_BOLD)$(_CYAN)ar rcs $(_RED)$(NAME) $(_END)$(_GREY)$(OBJ)$(_END)"
	@ar rcs $@ $^
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

bonus: $(OBJ_BONUS)
	@echo
	@echo "$(_BOLD)$(_CYAN)Compiling Bonus($(_RED)$@$(_CYAN))$(_END)"
	@echo
	@echo "$(_BOLD)$(_CYAN)ar rcs $(_RED)$(NAME) $(_END)$(_GREY)$(OBJ_BONUS)$(_END)"
	@ar rcs $(NAME) $^
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

$(BUILD_DIR_BONUS)%.o: %.c
	@ \
	if [ $(IS_COMPILING) -eq 0 ]; then \
		echo; \
		echo "$(_BOLD)$(_CYAN)Entering ($(_RED)./src$(_CYAN))$(_END)"; \
		echo; \
	fi
	@$(eval IS_COMPILING = 1)
	@mkdir -p $(dir $@)
	@echo "$(_BOLD)$(_RED) $< : $(_END) $(_GREY) $(CC) $(CFLAGS) $(INCLUDES_BONUS) -c $< -o $@ $(_END)"
	@$(CC) $(CFLAGS) $(INCLUDES_BONUS) -c $< -o $@

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
	@rm -rf $(BUILD_DIR_BONUS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re valgrind bonus
