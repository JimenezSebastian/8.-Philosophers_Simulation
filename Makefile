NAME = philo
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = src/L1.c src/L2_A.c src/L2_B.c src/L3_A.c src/L3_B.c\
	src/L4.c src/LCE.c src/LGU.c src/main.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
