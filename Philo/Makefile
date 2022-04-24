NAME = philo
CC = gcc
CFLAGS = -pthread -Wall -Wextra -Werror
INCLUDES = -I./includes -I.

SRC	=	srcs/main.c
SRC_DIRS = ${dir ${SRC}}
OBJ_DIR = ./obj
BIN_DIRS = ${addprefix ${OBJ_DIR}/, ${SRC_DIRS}}
OBJS = ${addprefix ${OBJ_DIR}/, ${SRC:.c=.o}}

all:	${NAME}

${NAME}:	${OBJS}
	${CC} -g ${CFLAGS} $^ ${INCLUDES} -o $@

${OBJ_DIR}/%.o: %.c
	@mkdir -p ${BIN_DIRS}
	${CC} -g ${CFLAGS} ${INCLUDES} -o $@ -c $<

clean:
	${RM} -r ${OBJ_DIR}

fclean:clean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re