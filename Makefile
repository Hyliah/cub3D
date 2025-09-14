OS = $(shell uname)
CPU = $(shell uname -m)

# nom de l'executable
NAME = cub3d

# Source and object diretories
SRCDIR = src
OBJDIR = obj

# Librairies
LIBFTDIR = ./attached/libft
LIBFT = $(LIBFTDIR)/libft.a
ifeq ($(OS), Darwin)
	ifeq ($(CPU), arm64)
		MLXDIR = ./attached/minilibx_macos_metal
		MLX_FRAMEWORK = -framework OpenGL -framework AppKit
	else
		MLXDIR = ./attached/minilibx_macos_opengl
		MLX_FRAMEWORK = -framework OpenGL -framework AppKit
	endif
else ifeq ($(OS), Linux)
	MLXDIR = ./attached/minilibx-linux 
	MLX_FRAMEWORK = -lXext -lX11 -lz
endif
MLX = -L $(MLXDIR) -lmlx
MATH_LIB = -lm

# Compiler and flags
CC = gcc
CFLAGS = -g3 -Wall -Wextra -Werror
INCLUDE = -I includes -I $(MLXDIR)

ifeq ($(DEBUG), 1)
	CFLAGS += -fsanitize=address
endif

RM = rm -f 

vpath %.c \
	$(SRCDIR) \
	$(SRCDIR)/parsing \
	$(SRCDIR)/screen \
	$(SRCDIR)/malloc_exit \

# Sources and object files
SRC = main.c \
clean_exit.c \
window_creation.c \

OBJS = $(addprefix $(OBJDIR)/, $(SRC:.c=.o))

all: $(LIBFT) $(MLX) $(NAME)

$(LIBFT):
	$(MAKE) all -C $(LIBFTDIR)

$(MLX):
	$(MAKE) all -C $(MLXDIR)
	
# Compile each .c file to .o		
$(OBJDIR)/%.o: %.c
		@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@
	
$(NAME): $(OBJS)
		$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MLX) $(MLX_FRAMEWORK) $(MATH_LIB) -o $(NAME)

# Rule to clean up object files	
clean:
		$(RM) $(OBJS)
		$(MAKE) clean -C $(LIBFTDIR)
		$(MAKE) clean -C $(MLXDIR)
		@rm -rf $(OBJDIR)

#Rule to clean  up object files and the library
fclean: clean
		$(RM) $(NAME)
		$(MAKE) fclean -C $(LIBFTDIR)

# Rule to recompile everything
re: fclean all

.PHONY: all clean fclean re
