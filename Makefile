OS = $(shell uname)
CPU = $(shell uname -m)

# nom de l'executable
NAME = cub3d

# Source and object diretories
SRCDIR = src
OBJDIR = obj

# Librairies
LIBFTDIR = ./libft
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
CFLAGS = -g3 -Wall -Wextra -Werror -MP -MMD
INCLUDE = -I includes -I $(MLXDIR)

ifeq ($(DEBUG), 1)
	CFLAGS += -fsanitize=address
endif

RM = rm -f 

vpath %.c \
	$(SRCDIR) \
	$(SRCDIR)/utils \
	$(SRCDIR)/parsing \
	$(SRCDIR)/screen \
	$(SRCDIR)/screen/minimap \
	$(SRCDIR)/malloc_exit \
	$(SRCDIR)/custom_mlx \

# Sources and object files
SRC = main.c \
clean_exit.c free.c \
get_pixel.c set_pixel.c merge_screen.c \
key_handle.c move_player.c window_creation.c screen_utils.c \
minimap.c mm_player.c\
init.c \

OBJS = $(addprefix $(OBJDIR)/, $(SRC:.c=.o))

all: $(LIBFT) $(MLX) $(NAME)
# 	@echo "\033[0;32m\
#    __  _  _  ___  ___  ___      \n\
#   / _)( )( )(  ,)(__ )(   \\     \n\
#  ( (_  )()(  ) ,\\ (_ \\ ) ) )    \n\
#   \\__) \\__/ (___/(___/(___/     \n\
# \033[0;36mCub3D build completed successfully! ✅\033[0m"

# 	@echo "\033[0;35m  LES CODEUSES DU DIMANCHE PRESENT YOU \033[0m"; sleep 1
# 	@echo ""
# 	@echo "            🥁 🥁 🥁 🥁 🥁"; sleep 1
# 	@echo ""
# 	@echo "\033[0;31m       __  _  _  ___  ___  ___      \033[0m"; #sleep 0.1
# 	@echo "\033[0;33m      / _)( )( )(  ,)(__ )(   \\     \033[0m"; sleep 0.1
# 	@echo "\033[0;32m     ( (_  )()(  ) ,\\ (_ \\ ) ) )    \033[0m"; sleep 0.1
# 	@echo "\033[0;34m      \\__) \\__/ (___/(___/(___/     \033[0m"; sleep 0.1
# 	@echo ""
# 	@echo ""
# 	@echo "\033[0;36m Cub3D build completed successfully! ✅\033[0m"
# 	@echo ""

	@echo "\033[0;35m  LES CODEUSES DU DIMANCHE PRESENT YOU \033[0m";
	@echo ""
	@echo "            🥁 🥁 🥁 🥁 🥁"; sleep 1
	@echo ""
	@echo "\033[0;31m       __  _  _  ___  ___  ___      \033[0m";
	@echo "\033[0;33m      / _)( )( )(  ,)(__ )(   \\     \033[0m";
	@echo "\033[0;32m     ( (_  )()(  ) ,\\ (_ \\ ) ) )    \033[0m"; 
	@echo "\033[0;34m      \\__) \\__/ (___/(___/(___/     \033[0m";
	@echo ""
	@echo ""
	@echo "\033[0;36m Cub3D build completed successfully! ✅\033[0m"
	@echo ""

$(LIBFT):
	@$(MAKE) -s -C $(LIBFTDIR) > /dev/null 2>&1

$(MLX):
	@$(MAKE) -s -C $(MLXDIR) > /dev/null 2>&1
	
# Compile each .c file to .o		
$(OBJDIR)/%.o: %.c
		@mkdir -p $(OBJDIR)
	@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@
	
$(NAME): $(OBJS)
		@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MLX) $(MLX_FRAMEWORK) $(MATH_LIB) -o $(NAME)

# Rule to clean up object files	
clean:
	@$(RM) $(OBJS)
	@$(MAKE) -s -C $(LIBFTDIR) clean > /dev/null 2>&1
	@$(MAKE) -s -C $(MLXDIR) clean > /dev/null 2>&1
	@rm -rf $(OBJDIR)

#Rule to clean  up object files and the library
fclean: clean
	@$(RM) $(NAME)
	@$(MAKE) -s -C $(LIBFTDIR) fclean > /dev/null 2>&1

# Rule to recompile everything
re: fclean all

.PHONY: all clean fclean re
