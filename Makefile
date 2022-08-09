# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oal-tena <oal-tena@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/09 09:48:24 by oal-tena          #+#    #+#              #
#    Updated: 2022/08/09 12:51:56 by oal-tena         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=exmaple

MINILIBX_PATH=lib/minilibx-linux
MINILIBX_MACOS=lib/macos

MLX=./lib/minilibx-linux/libmlx_linux.a
MACOS=./lib/macos/libmlx.a

OBJ_DIR=package/
OBJ=$(SRC:.c=.o)
OBJ_PREFX=$(addprefix $(OBJ_DIR),$(OBJ))

CC_FLAG = -Wall -Wextra -Werror
CC=gcc -g -O0



OS = $(shell uname)
ifeq (${OS},Darwin)
	OP = mac
	OBJ_L = -I/usr/include -I$(MINILIBX_MACOS)
	NAME_L = $(MACOS) -framework OpenGL -framework AppKit
	H_L = ${MACOS}
else
	OP = linux
	OBJ_L= -I/usr/include -I$(MINILIBX_MACOS)
	NAME_L = -L/usr/lib $(MLX) $(LIBFT) -lXext -lX11 -lm -lz
	H_L = ${MACOS}
	MOUSE = -D MOUSE_FLAG=1
endif

SRC = src/main.c

# all: $(NAME)


# $(OBJ_DIR)%.o:%.c include/mlx_example.h
# 	@echo "Compiling $(<)"
# 	@mkdir -p $(OBJ_DIR)/src
# 	@echo "Compiling: $<"
# 	@$(CC) $(CC_FLAGS) ${OBJ_L} -c $< -o $@

$(NAME):$(OBJ_PREFX) $(H_L)
	$(CC)  $(OBJ_PREFX) ${NAME_L} -o $(NAME)
	@echo "make done !"
# exmaple 01: create window by mlx 
all:
	$(CC)  ./src/window/main.c ${NAME_L} -o window
	@echo "make done !"

clean:
	@rm -rf $(OBJ_DIR)


fclean: 
	rm -f $(NAME)
	
	

re: fclean clean all