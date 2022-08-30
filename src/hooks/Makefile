# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aaljaber <aaljaber@student.42abudhabi.a    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/18 13:42:43 by aaljaber          #+#    #+#              #
#    Updated: 2022/08/26 01:22:00 by aaljaber         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


## this is a very simple makefile, and it's not recommended to use .. Has been created just to explain these examples##

KEY_HOOK = ./key_hook/main.c

LOOP_HOOK = ./loop_hook/main.c

MLX_HOOK = ./mlx_hook/main.c

CC = gcc

FLAGS = -Wall -Wextra -Werror

LINKS = -L MLX -l MLX -framework OpenGl -framework Appkit -lz

RM = rm -rf

k :
	${MAKE} -C ./MLX
	${CC} ${FLAGS} ${LINKS} ${KEY_HOOK} -o key
	
l :
	${MAKE} -C ./MLX
	${CC} ${FLAGS} ${LINKS} ${LOOP_HOOK} -o loop

h :
	${MAKE} -C ./MLX
	${CC} ${FLAGS} ${LINKS} ${MLX_HOOK} -o hook

clean: 
	${RM} key loop hook
	${MAKE} clean -C ./MLX
