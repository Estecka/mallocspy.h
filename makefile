HDRS = mallocspy.h mallocspy_internals.h
SRCS = \
	mallocspy.c \
	mallocspy_internals.c \
	lvl_overloads.c \

OBJS = ${SRCS:.c=.o}

TEST_SRCS = .test/main.c

LIBS = \
	../libft/libft.a \
	../ft_printf/libftprintf.a \

NAME	= libmallocspy.a
TEST	= mallocspytest.out

CC		= clang
CFLAGS	= -Wall -Wextra -Werror -I ../ft_printf/
LIBFLAGS = \
	-L ./ -lmallocspy \
	-L ../ft_printf/ -lftprintf \
	-L ../libft/ -lft \


${NAME}: ${OBJS}
	ar rcs ${NAME} ${OBJS}

test: ${TEST}
${TEST}: ${NAME} ${TEST_SRCS} ${LIBS}
	${CC} ${TEST_SRCS} -o ${TEST} ${LIBFLAGS} -Wall -Wextra


${OBJS}: ${HDRS}

%.a: ext_makefile
	make $(@F) -C $(@D)


all: ${NAME} ${TEST}

clean:
	rm -f *.o
	rm -f *.gch

fclean: clean
	rm -f ${NAME}
	rm -f ${TEST}

re: fclean all

.PHONY: \
	all clean fclean re \
	ext_makefile \
	test \
