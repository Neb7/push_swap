LIBFT		= libft/

SRC			= test.c \
			  main.c \
			  push_swap_error.c \
			  push_swap_init.c \
			  push_swap_is.c \
			  push_swap_op.c \
			  push_swap_op2.c \
			  push_swap_resolve.c \
			  push_swap_utils.c

SRCS_DIR 	= srcs/
SRCS		= $(addprefix ${SRCS_DIR}, ${SRC})

OBJS_DIR	= objects/
OBJS		= $(addprefix ${OBJS_DIR}, ${SRC:.c=.o})

INCLUDES	= includes
NAME		= push_swap
RM			= rm -f
CFLAGS		= -Wall -Wextra -Werror -I ${INCLUDES} -g

#Colors
GRAY		= \033[0;90m
RED			= \033[0;91m
GREEN		= \033[0;92m
YELLOW		= \033[0;93m
BLUE		= \033[0;94m
MAGENTA		= \033[0;95m
CYAN		= \033[0;96m
WHITE		= \033[0;97m
RESET		= \033[0m

all:			${NAME}

${OBJS_DIR}%.o: ${SRCS_DIR}%.c | ${OBJS_DIR}
				@cc ${CFLAGS} -c $< -o $@

${NAME}:		${OBJS}
				@make -C ${LIBFT}
				@cp ${LIBFT}libft.a .
				@${CC} ${CFLAGS} ${OBJS} -L${LIBFT} -lft -o $@ 
				@echo "${YELLOW}'${NAME}' is compiled !${RESET}"

${OBJS_DIR}:
				@mkdir -p ${OBJS_DIR}

clean:
				@${RM} ${OBJS}
				@${RM} -r ${OBJS_DIR}
				@make clean -C ${LIBFT}
				@echo "${RED}'${NAME}' objects are deleted !${RESET}"

fclean:			clean
				@${RM} ${NAME}
				@${RM} ${LIBFT}libft.a
				@echo "${RED}'libft.a' is deleted !${RESET}"
				@echo "${RED}'${NAME}' is deleted !${RESET}"

re:				fclean all

.PHONY:			all clean fclean re
