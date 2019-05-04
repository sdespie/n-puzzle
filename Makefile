# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sde-spie <sde-spie@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/22 14:23:31 by sde-spie          #+#    #+#              #
#    Updated: 2019/05/03 17:05:12 by adefonta         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = n-puzzle

CC = gcc

FLAGS = -O3
# FLAGS += -Wall -Wextra -Werro
# FLAGS += -fsanitize=address

IN =	n-puzzle.c\
		board.c\
		parse_cmd.c\
		move.c\
		check.c\
		error.c\
		ft_atoi_long.c\
		utils.c\
		heuristic.c\
		free.c\
		ft_strjoin_free.c \
		print.c \
		state.c \
		hashing.c \
		hashmap.c \
		sorttable.c \
		solve.c \
		cost_functions.c

IN_VISU = 	visu.c mlx.c colors.c event.c del.c image.c extra.c \
			display_1.c display_tools.c

LIBFT = ./libft

SRCS_DIR = src

SRCS_DIR_VISU = visu/srcs

OUT_DIR = tmp

INC =	-Iincludes -I$(LIBFT)/includes/ -I$(LIBFT)/libft/includes \
		-Ivisu/includes -Ivisu/minilibx/

INC_LIB =  -lmlx -L ./visu/minilibx  -L $(LIBFT) -lft

SRCS = $(addprefix $(SRCS_DIR)/,$(IN))

SRCS_VISU = $(addprefix $(SRCS_DIR_VISU)/,$(IN_VISU))

OBJS = $(addprefix $(OUT_DIR)/,$(IN:.c=.o))

OBJS_VISU = $(addprefix $(OUT_DIR)/,$(IN_VISU:.c=.o))

all: $(NAME)


$(NAME): $(OBJS) $(OBJS_VISU) #lib
	@$(CC) $(OBJS) $(OBJS_VISU) $(INC_LIB) $(FLAGS) -framework OpenGL -framework AppKit -o $(NAME)
	@echo "\033[1;34mN-Puzzle\t\033[1;33mExecutable\t\033[0;32m[OK]\033[0m"

$(OUT_DIR)/%.o: $(SRCS_DIR)/%.c
	@mkdir -p $(OUT_DIR)
	@$(CC) $(FLAGS) $(INC) -o $@ -c $<

$(OUT_DIR)/%.o: $(SRCS_DIR_VISU)/%.c
	@mkdir -p $(OUT_DIR)
	@$(CC) $(FLAGS) $(INC) -o $@ -c $<

$(OUT_DIR)/%.o: $(OP_DIR)/%.c
	@mkdir -p $(OUT_DIR)
	@$(CC) $(FLAGS) $(INC) -o $@ -c $<

lib:
	@make -C $(LIBFT)
	@make -C visu/minilibx/

norme:
	norminette ./$(LIBFT)/ ./$(INC)/ ./$(SRCS_DIR)/
	@echo

clean:
	@rm -f $(OBJS)
	@rm -rf $(OUT_DIR)
	# @make clean -C $(LIBFT)
	# @make -C visu/minilibx/ clean
	@echo "\033[1;34mN-Puzzle\t\033[1;33mCleaning\t\033[0;32m[OK]\033[0m"

fclean: clean
	@rm -f $(NAME)
	# @make fclean -C $(LIBFT)
	# @make -C visu/minilibx/ fclean
	@echo "\033[1;34mN-Puzzle\t\033[1;33mFull Cleaning\t\033[0;32m[OK]\033[0m"

re: fclean all

f: fclean
r: re
c: clean
