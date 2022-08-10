/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oal-tena <oal-tena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 12:49:23 by oal-tena          #+#    #+#             */
/*   Updated: 2022/08/10 05:02:14 by oal-tena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/mlx_example.h"

#define WIDTH 800
#define HEIGHT 600

//** start: headre **//
typedef struct s_line
{
	int		x0;
	int		y0;
	int		x1;
	int		y1;
	int		x2;
	int		y2;
}			t_line;

typedef struct s_windows
{
	void	*mlx;
	void	*win;
	void	*img;
	int		*data;
	int		bpp;
	int		size_line;
	int		endian;
}			t_windows;

typedef struct s_map
{
	int map_high;
	int map_wide;
	int img_high;
	int img_wide;
}			t_map;

//** end: headre **//

//** start: exmaple **//
void	init_window(t_windows *window, t_map *map_info)
{
	window->mlx = mlx_init();
	window->win = mlx_new_window(window->mlx, WIDTH, HEIGHT, "mlx_ex01"); // window size is 800x600
	window->img = mlx_new_image(window->mlx, map_info->img_wide, map_info->img_high); // image size is 300x300
	window->data = (int *)mlx_get_data_addr(window->img, &window->bpp,
			&window->size_line, &window->endian); // bpp is 300*300*4, size_line is 300*4, endian is 0
}

void	init_line(t_line *line)
{
	line->x0 = 600;
	line->y0 = 0;
	line->x1 = 0;
	line->y1 = 0;
	line->x2 = 300;
	line->y2 = 300;
}

void init_map(t_map *map)
{
	map->map_high = 10;
	map->map_wide = 10;
	map->img_high = 300;
	map->img_wide = 300;
}

int	main(void)
{
	t_windows	*window;
	t_line		*line;
	t_map		*map_info;
	char		*map[10];

	//** start: map**//
	map[0] = "1 1 1 1 1 1 1 1 1 1";
	map[1] = "1 0 0 0 0 0 0 0 0 1";
	map[2] = "1 0 0 0 0 0 0 0 0 1";
	map[3] = "1 0 0 0 0 0 0 0 0 1";
	map[4] = "1 0 0 0 0 0 0 0 0 1";
	map[5] = "1 0 0 0 0 0 0 0 0 1";
	map[6] = "1 0 0 0 0 0 0 0 0 1";
	map[7] = "1 0 0 0 0 0 0 0 0 1";
	map[8] = "1 0 0 0 0 0 0 0 0 1";
	map[9] = "1 1 1 1 1 1 1 1 1 1";
	map[10] = NULL;
	//** end: map**//
	window = (t_windows *)malloc(sizeof(t_windows));
	line = (t_line *)malloc(sizeof(t_line));
	init_map(map_info); // init map_info
	init_window(window, map_info); // init window
	init_line(line); // init line
	mlx_put_image_to_window(window->mlx, window->win, window->img, 0, 0);
	mlx_loop(window->mlx);
}
//** end: exmaple **//