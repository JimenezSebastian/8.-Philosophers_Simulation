NAME = philo
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = src/L1_Memory.c src/L2A_Pthreads.c src/L2B_Pthreads.c src/L3_Routine.c src/L3_Utils.c \
		src/L4_Monitor.c src/L5_CleanExit.c src/L6_GeneralUtils.c src/main.c
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
