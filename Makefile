NAME    = fdf
SRC_DIR = sources/
INC_DIR = includes/

SRC_FILES = main.c \
            fill_matrix.c fill_matrix_help.c \
            utils/ft_putstr_fd.c utils/ft_split.c utils/ft_strlen.c utils/ft_substr.c \
            utils/ft_atoi.c \
            gnl/get_next_line.c gnl/get_next_line_utils.c \
            free_map.c \
            ft_error.c \
            draw_map.c \
            colors.c \
            set_coord.c rotation.c \
            keyboard.c keyboard_utils.c\
            ft_mlx_put_pxl.c \
            init_params.c \
            menu.c

SRC = $(addprefix $(SRC_DIR), $(SRC_FILES))
OBJ = $(SRC:.c=.o)
DEP = $(SRC:.c=.d)

CC      = gcc
CFLAGS  = -Wall -Wextra -Werror -g -O3 -I$(INC_DIR)
LDFLAGS = -lmlx -framework OpenGL -framework AppKit

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LDFLAGS) -o $@
	@echo "\033[0;35m""Executable file created""\033[0m"

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ -MMD -MF $(@:.o=.d)

clean:
	rm -f $(OBJ) $(DEP)
	@echo "\033[0;33m""All .o and .d files deleted""\033[0m"

fclean: clean
	rm -f $(NAME)
	@echo "\033[0;33m""Executable files deleted""\033[0m"

re: fclean all

-include $(DEP)
