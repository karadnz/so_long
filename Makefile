NAME = so_long

CC = gcc
CFLAGS = -Wall
FRMS = -framework OpenGL -framework AppKit

SRCS = check.c check_utils.c draw_map.c hook.c init.c libftutils.c main.c
OBJS = $(SRCS:.c=.o)
ARCS = gnl/get_next_line.a mlx/libmlx.a

all: $(NAME) $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(ARCS) $(FRMS) -o $(NAME)
	@echo "So_long is compiled."

$(NAME):
	@cd ./gnl && $(MAKE)
	@echo "Gnl is compiled."
	@cd ./mlx && $(MAKE)

clean:
	rm -f $(OBJS)
	@cd ./gnl && $(MAKE) clean
	@cd ./mlx && $(MAKE) clean
	@echo "Cleaned"

fclean: clean
	rm -f $(NAME)
	@cd ./gnl && $(MAKE) fclean

re: fclean all

.PHONY: all clean fclean re