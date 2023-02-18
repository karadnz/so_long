NAME = so_long
BNAME = so_long_bonus

CC = gcc
CFLAGS = -Wall -Wextra -Werror
FRMS = -framework OpenGL -framework AppKit

SRCS = check.c enemy.c enemy2.c init2.c check_utils.c check_utils2.c free_exit.c draw_map.c hook.c hook2.c init.c libftutils.c main.c
OBJS = $(SRCS:.c=.o)

BSRCS = bonus/check_utils.c bonus/check_utils2.c \
		bonus/check.c bonus/draw_map.c \
		bonus/enemy.c bonus/enemy2.c \
		bonus/free_exit.c bonus/hook.c \
		bonus/hook2.c bonus/init.c \
		bonus/init2.c bonus/libftutils.c \
		bonus/main.c \

BOBJS = $(BSRCS:.c=.o)
ARCS = gnl/get_next_line.a mlx/libmlx.a

all: $(NAME) $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(ARCS) $(FRMS) -o $(NAME)
	@echo "So_long is compiled."

bonus: $(BNAME) 

$(BNAME): $(BOBJS)
	@$(CC) $(CFLAGS) $(BOBJS) $(ARCS) $(FRMS) -o $(BNAME)

$(NAME):
	@cd ./gnl && $(MAKE)
	@echo "Gnl is compiled."
	@cd ./mlx && $(MAKE)

clean:
	rm -f $(OBJS)
	rm -f $(BOBJS)
	@cd ./gnl && $(MAKE) clean
	@cd ./mlx && $(MAKE) clean
	@echo "Cleaned"

fclean: clean
	rm -f $(NAME)
	@cd ./gnl && $(MAKE) fclean

re: fclean all

.PHONY: all clean fclean re bonus