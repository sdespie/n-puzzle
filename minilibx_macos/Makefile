NOM=libmlx.a
SRC= mlx_shaders.c mlx_new_window.m mlx_init_loop.m mlx_new_image.m mlx_xpm.c mlx_int_str_to_wordtab.c
OBJ1=$(SRC:.c=.o)
OBJ=$(OBJ1:.m=.o)
CFLAGS+=-O2

NO_COLOR     := \x1b[0m
OK_COLOR     := \x1b[32;01m
HEAD_COLOR   := \x1b[32;01m
SILENT_COLOR := \x1b[30;01m

HEADER_PRINTED := NO

all: $(NOM)

$(NOM):	$(OBJ)
#	@echo "\033[1;34mfdf\t\033[1;33mCompilation MLX\t\t\033[0;32m[ ? ]\033[0m"
	@ar rcs $(NOM) $(OBJ)
	@ranlib $(NOM)
	@echo "\033[1;34mfdf\t\033[1;33mCompilation MLX\t\t\033[0;32m[ ✔ ]\033[0m"

%.o: %.c
	@gcc $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJ) *~
	@rm -f mlx_app
	@echo "\033[1;34mfdf\t\033[1;33mCleaning MLX obj\t\033[0;32m[ ✔ ]\033[0m"

fclean: clean
	@rm -f $(NOM)
	@echo "\033[1;34mfdf\t\033[1;33mCleaning MLX lib\t\033[0;32m[ ✔ ]\033[0m"

re: fclean all
