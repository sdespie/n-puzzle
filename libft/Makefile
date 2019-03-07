# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nrouvroy <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/13 16:31:24 by nrouvroy          #+#    #+#              #
#    Updated: 2019/01/15 09:59:02 by nrouvroy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
FLAGS = -Werror -Wall -Wextra -O3
OBJ_DIR = ./obj
SRC_DIR = ./src

INC = ./includes/
SRC =	ft_memset.c \
		ft_bzero.c \
		ft_memcpy.c \
		ft_memccpy.c \
		ft_memmove.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_strlen.c \
		ft_strdup.c \
		ft_strcpy.c \
		ft_strncpy.c \
		ft_strcat.c \
		ft_strncat.c \
		ft_strlcat.c \
		ft_strchr.c \
		ft_strrchr.c \
		ft_strstr.c \
		ft_strnstr.c \
		ft_strcmp.c \
		ft_strncmp.c \
		ft_atoi.c \
		ft_isalpha.c \
		ft_isdigit.c \
		ft_isalnum.c \
		ft_isascii.c \
		ft_isprint.c \
		ft_toupper.c \
		ft_tolower.c

SRC2 =	ft_memalloc.c \
		ft_memdel.c \
		ft_strdel.c \
		ft_strnew.c \
		ft_strclr.c \
		ft_striter.c \
		ft_striteri.c \
		ft_strmap.c \
		ft_strmapi.c \
		ft_strequ.c \
		ft_strnequ.c \
		ft_strsub.c \
		ft_strjoin.c \
		ft_strtrim.c \
		ft_strsplit.c \
		ft_itoa.c \
		ft_putchar.c \
		ft_putstr.c \
		ft_putendl.c \
		ft_putnbr.c \
		ft_putchar_fd.c \
		ft_putstr_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c

BONUS =	ft_lstadd.c \
		ft_lstnew.c \
		ft_lstdel.c \
		ft_lstdelone.c \
		ft_lstiter.c \
		ft_lstmap.c

PERS =	ft_countwords.c \
		ft_lst_reverse.c \
		ft_islower.c \
		ft_isupper.c \
		ft_str_isalnum.c \
		ft_str_isalpha.c \
		ft_str_isascii.c \
		ft_str_isdigit.c \
		ft_str_islower.c \
		ft_str_isupper.c \
		ft_str_tolower.c \
		ft_str_toupper.c \
		ft_itoa_base.c \
		ft_abs.c \
		ft_pow.c \
		ft_sqrt.c \
		ft_max.c \
		ft_min.c \
		ft_mjoin.c \
		ft_putwchar.c \
		ft_putwchar_fd.c \
		ft_putwstr.c \
		ft_putwstr_fd.c \
		ft_putnwstr_fd.c \
		ft_strcut.c\
		ft_str_isnum.c\
		ft_err_check.c\
		ft_str_contains.c

PRINTF = ft_printf.c \
		 ft_type_1.c \
		 ft_type_c.c \
		 ft_type_d.c \
		 ft_type_gc.c \
		 ft_type_gd.c \
		 ft_type_gs.c \
		 ft_type_o.c \
		 ft_type_p.c \
		 ft_type_s.c \
		 ft_type_u.c \
		 ft_type_u_util.c \
		 ft_type_x.c \
		 helper.c \
		 mainhandler.c \
		 sechandler.c \
		 structinit.c

GNL		= get_next_line.c

SOURCES		:= $(addprefix $(SRC_DIR)/,$(SRC:.c))
SOURCES		+= $(addprefix $(SRC_DIR)/,$(SRC2:.c))
SOURCES		+= $(addprefix $(SRC_DIR)/,$(BONUS:.c))
SOURCES		+= $(addprefix $(SRC_DIR)/,$(PERS:.c))
SOURCES		+= $(addprefix $(SRC_DIR)/,$(PRINTF:.c))
SOURCES		+= $(addprefix $(SRC_DIR)/,$(GNL:.c))

OBJ	:= $(addprefix $(OBJ_DIR)/,$(SRC:.c=.o))
OBJ	+= $(addprefix $(OBJ_DIR)/,$(SRC2:.c=.o))
OBJ	+= $(addprefix $(OBJ_DIR)/,$(BONUS:.c=.o))
OBJ	+= $(addprefix $(OBJ_DIR)/,$(PERS:.c=.o))
OBJ	+= $(addprefix $(OBJ_DIR)/,$(PRINTF:.c=.o))
OBJ	+= $(addprefix $(OBJ_DIR)/,$(GNL:.c=.o))

CC = gcc
all: $(NAME)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o:$(SRC_DIR)/%.c
	@$(CC) $(FLAGS) -I $(INC) -o $@ -c $<

$(NAME): $(OBJ_DIR) $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

clean:
	@/bin/rm -rf $(OBJ_DIR)

fclean: clean
	@/bin/rm -rf $(NAME)

re: fclean all

.PHONY:all fclean clean re
