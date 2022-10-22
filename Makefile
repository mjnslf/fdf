NAME = fdf

SRC = main.c \
	drawing.c \
	vec3d.c \
	get_next_line.c \
	tl_func.c \
	tl_func1.c \
	utils1.c \
	utils2.c \
	get_next_line_utils.c \
	
INCLUDE = . minilibx_macos

OBJ = $(SRC:.c=.o)

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	$(MAKE) -C minilibx_macos
	$(CC) -L minilibx_macos $^ -lmlx -framework OpenGL -framework AppKit -o $(NAME)

%.o: %.c
	clang $(CFLAGS)  -c -o $@ $<

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
