NAME = philo
CC = gcc
CFLAGS = -pthread -Wall -Wextra -Werror
CFLAGS += -g -fsanitize=address
INCLUDES = -I./includes -I.

SRC	=	srcs/main.c \
		srcs/ft_atoi.c \
		srcs/ft_put.c \
		srcs/ft_strutils.c \
		srcs/ft_isutils.c \
		srcs/ft_lstutils.c \
		srcs/ft_time.c \
		srcs/ft_free.c \
		srcs/init.c
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