/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oal-tena <oal-tena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 12:54:17 by oal-tena          #+#    #+#             */
/*   Updated: 2022/08/21 13:11:21 by oal-tena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/mlx_example.h"

#define WIDTH 800
#define HEIGHT 800

typedef struct s_game{
	char **maps;
	int map_size;
	int map_height;
	int map_width;
	int player_x;
	int player_y;
	int player_dir;
	int player_plane;
	int player_pos;
	int player_move;
	void *mlx;
	void *win;
	void *img;
	int *img_data;
	int img_bpp;
	int img_size_line;
	int img_endian;
	int ray_dir;
	int ray_pos;
	int ray_step;
} t_game;

void init_game(t_game *game)
{
	game->map_size = 0;
	game->map_height = 0;
	game->map_width = 0;
	game->player_x = 0;
	game->player_y = 0;
	game->player_dir = 0;
	game->player_plane = 0;
	game->player_pos = 0;
	game->player_move = 0;
}

void init_window(t_game *game)
{
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, WIDTH, HEIGHT, "Raycasting");
	game->img = mlx_new_image(game->mlx, WIDTH, HEIGHT);
	game->img_data = (int *)mlx_get_data_addr(game->img, &game->img_bpp, &game->img_size_line, &game->img_endian);
}


int	main(void)
{
	t_game game;
	init_game(&game);
	init_window(&game);
	mlx_loop(game.mlx);
	return (0);
}
