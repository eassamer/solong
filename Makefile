NAME = so_long

SRCS = maps.c \
			gnl.c \
			index.c \
			utils.c

CFLAGS = -Wall -Wextra -Werror

FlAGS = -lmlx -framework OpenGL -framework AppKit

all : $(NAME)

$(NAME):
		$(CC) $(SRCS) -lmlx -framework OpenGL -framework AppKit -o $(NAME)