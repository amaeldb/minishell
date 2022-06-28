SRCS =	src/minishell.c src/env.c src/env2.c

OBJS =	${SRCS:.c=.o}

#DEPS =	${SRCS:.o=.d}

FLAGS =	-Wall -Wextra -Werror

NAME =	minishell

%.o: 	%.c
	@ gcc ${FLAGS} -c $< -o $@

all:		${NAME}

${NAME}:	${OBJS}
	@ make -C libft --silent
	@ gcc ${FLAGS} ${OBJS} libft/libft.a -lreadline -o ${NAME}

clean:		${OBJS}
	@ make clean -C libft --silent
	@ rm -rf ${OBJS} ${DEPS}

fclean:		clean
	@ make fclean -C libft --silent
	@ rm -rf ${NAME}

re:			fclean
	@ make all

#-include ${DEPS}