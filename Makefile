LIBFT		= libft/

SRC			= push_swap_short_sort.c \
			  push_swap_error.c \
			  push_swap_init.c \
			  push_swap_is.c \
			  push_swap_op.c \
			  push_swap_op2.c \
			  push_swap_resolve.c \
			  push_swap_utils.c \
			  push_swap_calcul.c \
			  push_swap_calcul_utils.c
MAIN		= srcs/main.c

SRCS_DIR 	= srcs/
SRCS		= $(addprefix ${SRCS_DIR}, ${SRC})

OBJS_DIR	= objects/
OBJS		= $(addprefix ${OBJS_DIR}, ${SRC:.c=.o})


SRC_BONUS	= checker.c \
			  checker_error.c

SRCS_BONUS	= $(addprefix ${SRCS_DIR}, ${SRC_BONUS})
OBJS_BONUS	= $(addprefix ${OBJS_DIR}, ${SRC_BONUS:.c=.o})
BONUS		= checker

INCLUDES	= includes
NAME		= push_swap
RM			= rm -f
CFLAGS		= -Wall -Wextra -Werror -I ${INCLUDES}

#Colors
LIGHT_GRAY	= \033[2m
ORANGE		= \033[1;33m
DARK_GRAY	= \033[0;90m
RED			= \033[0;91m
GREEN		= \033[0;92m
YELLOW		= \033[0;93m
BLUE		= \033[0;94m
MAGENTA		= \033[0;95m
CYAN		= \033[0;96m
WHITE		= \033[0;97m
RESET		= \033[0m

#Forme
BOLD		= \033[1m
ITALIC		= \033[3m
UNDERLINE	= \033[4m
CROSS		= \033[9m
FLASH		= \033[5m
NEGATIF		= \033[7m

all:			${NAME}

${OBJS_DIR}%.o: ${SRCS_DIR}%.c | ${OBJS_DIR}
				@cc ${CFLAGS} -c $< -o $@

${NAME}:		${OBJS}
				@echo "${BLUE}'libft.a' is compiling... 🔥 ${ITALIC}(if needed)${RESET}"
				@make -sC ${LIBFT}
				@${CC} ${CFLAGS} ${OBJS} -L${LIBFT} ${MAIN} -lft -o $@ 
				@echo "${YELLOW}$@ is compiled ! ✅${RESET}"

${OBJS_DIR}:
				@mkdir -p ${OBJS_DIR}

bonus:			${BONUS}

${BONUS}:		${OBJS_BONUS} ${OBJS}
				@echo "${BLUE}'libft.a' is compiling... 🔥 ${ITALIC}(if needed)${RESET}"
				@make -sC ${LIBFT}
				@${CC} ${CFLAGS} ${OBJS_BONUS} ${OBJS} -L${LIBFT} -lft -o $@ 
				@echo "${CYAN}'$@' is compiled ! ✅${RESET}"

clean:
				@${RM} ${OBJS} ${OBJS_BONUS}
				@${RM} -r ${OBJS_DIR}
				@make clean -sC ${LIBFT}
				@echo "${RED}'${NAME}' and '${BONUS}' objects are deleted ! 👍${RESET}"

fclean:			clean
				@${RM} ${NAME} ${LIBFT}libft.a ${BONUS}
				@echo "${RED}'${NAME}', '${BONUS}' and 'libft.a' are deleted ! 👍${RESET}"

re:				fclean all

.PHONY:			all clean fclean re bonus
