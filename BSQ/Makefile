NAME	=	BSQ

SRCS	=	main.c					\
			create_map.c			\
			create_points_data.c	\
			find_bsq.c				\
			add_sqare_map_parsed.c	\
			check_map1.c			\
			check_map2.c			\
			free.c					\
			ft_strlen.c				\
			ft_putstr_fd.c			\
			ft_strcpy.c				\
			ft_strcat.c				\
			ft_atoi.c				\
			ft_strdup.c				\
			ft_split.c				\
			ft_create_elem.c		\
			ft_list_push_back.c

OBJS	=	${SRCS:.c=.o}

CC		=	gcc
CFLAGS	=	-Wall -Werror -Wextra -O3

RM		=	rm -f

.c.o:
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			${CC} -o ${NAME} ${OBJS}

all:		${NAME}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re
