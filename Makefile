# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oal-tena <oal-tena@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/09 09:48:24 by oal-tena          #+#    #+#              #
#    Updated: 2022/08/09 12:51:25 by oal-tena         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=exmaple

MINILIBX_LINUX=lib/minilibx-linux
MINILIBX_MACOS=lib/macos

MLX_LINUX=./lib/minilibx-linux/libmlx_linux.a
MLX_MAC=./lib/macos/libmlx.a


OBJ_DIR=package/
OBJ=$(SRC:.c=.o)
OBJ_PREFX=$(addprefix $(OBJ_DIR),$(OBJ))

CC_FLAG = -Wall -Wextra -Werror
CC=gcc -g -O0


OS = $(shell uname)
ifeq (${OS},Darwin)
	OP = mac
	OBJ_L = -I/usr/include -I$(MINILIBX_MACOS)
	NAME_L = $(MLX_MAC) -framework OpenGL -framework AppKit
	MLX_A = ${MLX_MAC}
	MLX_L = $(MINILIBX_MACOS)
else
	OP = linux
	OBJ_L= -I/usr/include -I$(MINILIBX_LINUX) -O3
	NAME_L = -L/usr/lib $(MLX_LINUX) -lXext -lX11 -lm -lz
	MLX_A = ${MLX_LINUX}
	MLX_L = $(MINILIBX_LINUX)
endif

# exmaple 01: create window by mlx 
all:
	@ $(MAKE) -C $(MLX_L)
	$(CC)  ./src/window/main.c ${NAME_L} -o ex_window
	$(CC)  ./src/bresenham/main.c ${NAME_L} -o ex_bresenham
	@echo "make done !"

clean:
	@rm -rf $(OBJ_DIR)
	@rm -f ex_window
	@rm -f ex_bresenham


fclean: 
	rm -f $(NAME)
	
	

re: fclean clean all