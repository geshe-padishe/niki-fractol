NAME			= so_long_mlx
EX_NAME			= so_long

CC				= gcc
CFLAGS			= -Wall -Wextra -Werror
GNL_FLAGS		= -D BUFFER_SIZE=42

FLAGS			= -L ${LIBFT_D} -lft
RM				= rm -f

SRC_D			= srcs
SRC_LIST		= ft_so_long.c get_next_line.c get_next_line_utils.c
SRC_C			= $(addprefix ${SRC_D}/, ${SRC_LIST})

INC_D			= includes
HEADER_LIST		= ft_so_long.h get_next_line.h
HEADER_H		= $(addprefix ${INC_D}/, ${HEADER_LIST})

LIBFT			= libft.a
LIBFT_D			= libft
LIBFT_A			= $(addprefix ${LIBFT_D}/, ${LIBFT})

OBJS			= ${SRC_C:.c=.o}

all:			${NAME}

$(NAME): $(OBJS)
	make -C ${LIBFT_D}
	cp ${LIBFT_D}/${LIBFT} .
	$(CC) $(CFLAGS) -I$(INC_D) $(OBJS) $(FLAGS) $(LIBFT) libmlx_Linux.a \
	-L. -Llib -Imlx -lXext -lX11 -lm -lz -Lmlx -lmlx -o $(EX_NAME)

%.o: %.c ${HEADER_H}
	$(CC) $(CFLAGS) $(FLAGS) $(LIBFT) -L. libmlx_Linux.a \
	-I/usr/bin -I${INC_D} -I${LIBFT_D} -Imlx -c $< -o $@

clean:
				$(MAKE) -C ${LIBFT_D} clean
				${RM} ${OBJS}

fclean: clean
				$(MAKE) -C ${LIBFT_D} fclean
				${RM} ${EX_NAME}

re: 			fclean all

.PHONY: all clean fclean re
