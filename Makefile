NAME = fdf

SRC =  main.c read_file.c get_next_line.c ft_split.c get_next_line_utils.c drawing.c

FLAGS = -Wall -Wextra -Werror

INCLUDE = . libft minilibx_macos

CPPFLAGS = $(addprefix -I,$(INCLUDE))

CFLAGS = -Wall -Wextra -Werror

export DEBUG_MODE

ifdef DEBUG_MODE
	CFLAGS += -g
endif

СС = gcc

OBJ = $(SRC:.c=.o)

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	$(MAKE) -C minilibx_macos
	$(MAKE) -C libft
	$(CC) -Llibft -L minilibx_macos $^ -lmlx -lft -framework OpenGL -framework AppKit -o $(NAME)

clean:
	$(MAKE) fclean -C libft
	$(MAKE) clean -C minilibx_macos
	rm -rf *.o

fclean: clean
	rm -rf $(NAME)

re: fclean all
