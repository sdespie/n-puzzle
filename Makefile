# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sde-spie <sde-spie@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/22 14:23:31 by sde-spie          #+#    #+#              #
#    Updated: 2019/04/11 20:42:27 by adefonta         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_DIR		:=	./src
INC_DIR		:=	./includes
OBJ_DIR		:=	./obj
LIBFT_DIR	:=	./libft

INC			:=	-I $(INC_DIR)/
LIB_LNK		:=	-L $(LIBFT_DIR) -lft
LIB_INC		:=	-I $(LIBFT_DIR)/includes
LIB_INC		+=	$(INC)

SRC			:=	n-puzzle.c\
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
				solve.c



OBJ			:=	$(addprefix $(OBJ_DIR)/,$(SRC:.c=.o))

CC			:=	gcc -g
CFG			:=	-O3
CFG			+=	#-Wall -Wextra
CFG			+=	-fsanitize=address
NAME		:=	n-puzzle

# rules

all: $(NAME)

lib:
	@$(MAKE) -C $(LIBFT_DIR) re
	@echo "\033[1;34mN-Puzzle\t\033[1;33mLIB\t\t\033[0;32m[OK]\033[0m"

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o:$(SRC_DIR)/%.c
	@$(CC) $(CFG) $(LIB_INC) -o $@ -c $<

$(NAME): $(OBJ_DIR) $(OBJ)
	@make -C $(LIBFT_DIR)
	@$(CC) -o $(NAME) $(CFG) $(OBJ) $(LIB_LNK)
	@echo "\033[1;34mN-Puzzle\t\033[1;33mExecutable\t\033[0;32m[OK]\033[0m"

clean:
	@/bin/rm -rf $(OBJ_DIR)
	@$(MAKE) -C $(LIBFT_DIR) clean
	@echo "\033[1;34mN-Puzzle\t\033[1;33mCleaning\t\033[0;32m[OK]\033[0m"

fclean: clean
	@/bin/rm -f $(NAME)
	@make -C $(LIBFT_DIR) fclean
	@echo "\033[1;34mN-Puzzle\t\033[1;33mFull Cleaning\t\033[0;32m[OK]\033[0m"

f: fclean
re: fclean all

.PHONY: all clean fclean re lib
