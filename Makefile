NAME	=	so_long
CC		=	cc
CFLAGS	=	-Wall -Wextra -Werror -g3

SRC_DIR	=	./
OBJ_DIR	=	objs/

SRC_FILES	=	main.c	\
				parse.c	\
				images.c	\
				move.c	\
				checker.c	\
				checker_2.c	\
				getter.c	\
				flood_fill.c	\
				free.c

OBJS = $(addprefix $(OBJ_DIR), $(SRC_FILES:.c=.o))

MLX_DIR			=	mlx_linux/
MLX_MAKE		=	make --no-print-directory -C $(MLX_DIR)

LIBFT_DIR		=	libft/
LIBFT_MAKE		=	make --no-print-directory -C $(LIBFT_DIR)

LIBS = -lm -L $(MLX_DIR) -l mlx -lXext -lX11

all: $(NAME)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c ./so_long.h libft/libft.h | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS) Makefile $(DIR_INCS)
	$(LIBFT_MAKE)
	$(MLX_MAKE)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBS) libft/libft.a

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

clean:
	rm -rf $(OBJ_DIR)
	@$(MLX_MAKE) clean
	@$(LIBFT_MAKE) clean

fclean: clean
	rm -f $(NAME)
	rm -f libft/libft.a
	rm - f *.gch

re: fclean all

.PHONY: all clean fclean re make
