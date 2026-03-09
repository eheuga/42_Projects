NAME	= push_swap

CC		= cc
CFLAGS	= -Wall -Wextra -Werror

SRC	= sources
INCLUDE	= include

SRCS	= $(SRC)/operations.c \
		  $(SRC)/chek.c \
		  $(SRC)/ft_atoi.c \
		  $(SRC)/indexer.c \
		  $(SRC)/is_sorted.c \
		  $(SRC)/little_sorter.c \
		  $(SRC)/big_sorter.c \
		  $(SRC)/main.c

OBJS	= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -I$(INCLUDE) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re