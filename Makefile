NAME			= so_long
EX_NAME			= so_long

CC				= gcc
CFLAGS			= -Wall -Wextra -Werror #-g3 -fsanitize=address
GNL_FLAGS		= -D BUFFER_SIZE=42

FLAGS			= -L ${LIBFT_D} -lft
RM				= rm -f

SRC_D			= srcs
SRC_LIST		= ft_so_long.c get_next_line.c get_next_line_utils.c \
				  ft_so_long2.c ft_so_long3.c ft_so_long_hooks.c \
				  ft_events.c ft_moves.c ft_so_long4.c
SRC_C			= $(addprefix ${SRC_D}/, ${SRC_LIST})

INC_D			= includes
HEADER_LIST		= ft_so_long.h get_next_line.h
HEADER_H		= $(addprefix ${INC_D}/, ${HEADER_LIST})

LIBFT			= libft.a
LIBFT_D			= libft
LIBFT_A			= $(addprefix ${LIBFT_D}/, ${LIBFT})

LIBMLX			= libmlx_Linux.a
OBJS			= ${SRC_C:.c=.o}

all:			${NAME}

${NAME}:		${OBJS}
				make -C ${LIBFT_D}
				cp ${LIBFT_D}/${LIBFT} .
				make -C libmlx
				cp libmlx/libmlx_Linux.a .
				${CC} $(CFLAGS) -I$(INC_D) $(OBJS) $(FLAGS) $(LIBFT) libmlx_Linux.a \
				-L. -Llibmlx -Ilibmlx -lXext -lX11 -lm -lz -lmlx -o ${NAME}

#so_long:		${HEADER_H} $(SRC_C)
#	$(CC) $(CFLAGS) -I$(INC_D) $(OBJS) $(FLAGS) $(LIBFT) libmlx_Linux.a \
#	-L. -Llibmlx -Ilibmlx -lXext -lX11 -lm -lz -lmlx -o $(EX_NAME)

%.o: %.c ${HEADER_H}
	$(CC) $(CFLAGS) -L. -Llib -lXext -lmlx -lm -lz -lX11 \
	-I/usr/bin -I${INC_D} -I${LIBFT_D} -Ilibmlx -c $< -o $@

clean:
				$(MAKE) -C ${LIBFT_D} clean
				${RM} ${OBJS}

fclean: clean
				$(MAKE) -C ${LIBFT_D} fclean
				$(MAKE) -C libmlx clean
				${RM} ${EX_NAME} ${LIBFT} libmlx_Linux.a

re: 			fclean all

.PHONY: all clean fclean re
