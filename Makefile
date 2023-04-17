NAME = so_long
BONUS = so_long_bonus

CC = cc -g -fsanitize=address
CFLAGS = -Wall -Wextra -Werror
MFLAGS = -lX11 -lXext
RM = rm -rf

LIBFT = ./libft/libft.a
MINILIBX = ./minilibx-linux/libmlx.a

SRCS = 		main.c \
		check.c\
		check_path.c\
		free.c\
		get.c\
		map_utils.c\
		move.c\
		utils.c\

OBJS = $(SRCS:%.c=%.o)

all: $(NAME)

$(LIBFT):
	@echo "\033[0;33m\COMPILING libft\n"
	@$(MAKE) -C ./libft
	@echo "\033[1;32mLIBFT created\n"

$(MINILIBX):
	@echo "\033[0;33m\nCOMPILING mlx\n"
	@$(MAKE) -C ./minilibx-linux
	@echo "\033[1;32mMLX created\n"

$(NAME): $(OBJS) $(LIBFT) $(MINILIBX)
	@echo "\033[0;33m\nCOMPILING SO_LONG.....\n"
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MINILIBX) $(MFLAGS) -o $(NAME)
	@echo "\033[1;32m./so_long created\n"

clean:
	@echo "\033[0;31mDELETING MLX files\nLIBFT files\nSO_long object...\n"
	@$(MAKE) clean -C ./libft
	@$(MAKE) clean -C ./minilibx-linux
	@$(RM) $(OBJS)
	@echo "033[1;32mDONE\n"

fclean: clean
	@echo "\033[0;31mDELETING SO_LONG EXECUTABLE...."
	@$(MAKE) fclean -C ./libft
	@$(MAKE) clean -C ./minilibx-linux
	@$(RM) $(NAME)
	@echo "\033[1;32mDONE\n"

re: fclean all
