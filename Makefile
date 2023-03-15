NAME = libftprintf.a

SRCS = ft_printf.c utils.c

FLAGS = -Wextra -Werror -Wall

CC = gcc ${FLAGS}

RM = rm -f

OBJS = ${SRCS:.c=.o}

.c.o:
	${CC} -g  -c $< -o ${<:.c=.o}

${NAME} : ${OBJS}
	ar rcs ${NAME} ${OBJS}
	ranlib ${NAME}

all: ${NAME}

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME} 
re: fclean all