CC = gcc

NAME = libft.a

CFLAGS = -Wall -Wextra -Werror

SRC_C = ft_memcpy.c ft_memset.c \
		dynarray.c dynarray2.c

INC_H = dynarray.h

OBJS = $(SRC_C:.c=.o)
	
all: $(NAME)

$(NAME): $(OBJS) ${INC_H}
	ar rc $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

%.o: %.c $(INC_H)
	$(CC) $(CFLAGS) -c $< -o $@
