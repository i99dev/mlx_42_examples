/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oal-tena <oal-tena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 12:49:23 by oal-tena          #+#    #+#             */
/*   Updated: 2022/08/12 04:20:20 by oal-tena         ###   ########.fr       */
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
	int		map_high;
	int		map_wide;
	int		img_high;
	int		img_wide;
	int		dx;
	int		dy;
}			t_map;

//** end: headre **//

//** start: exmaple **//
void	init_window(t_windows *window, t_map *map_info)
{
	window->mlx = mlx_init();
	window->win = mlx_new_window(window->mlx, WIDTH, HEIGHT, "mlx_ex01");
	window->img = mlx_new_image(window->mlx, map_info->img_wide,
			map_info->img_high);
	window->data = (int *)mlx_get_data_addr(window->img, &window->bpp,
			&window->size_line, &window->endian);
}

void	init_line(t_line *line)
{
	line->x0 = 600;
	line->y0 = 0;
	line->x1 = 0;
	line->y1 = 0;
}

void	init_map(t_map *map)
{
	map->map_high = 10;
	map->map_wide = 18;
	map->img_high = 300;
	map->img_wide = 300;
	map->dx = round(map->img_wide / map->map_wide);
	map->dy = round(map->img_high / map->map_high);
}

void swap(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	cube(t_windows *window, int x, int y, t_map *map_info, t_line *line)
{
	line->x0 = x * map_info->dx;
	line->y0 = y * map_info->dy;
	line->x1 = line->x0 + map_info->dx;
	line->y1 = line->y0 + map_info->dy;
	printf("x =%d x0=%d x1=%d\n", x, line->x0, line->x1);
	while (line->y0 < line->y1)
	{
		window->data[line->y0 * map_info->img_wide + line->x0] = 0xDD9933;
		line->y0++;
	}
	line->y0--;
	while(line->x0 < line->x1)
	{
		window->data[line->y0 * map_info->img_wide + line->x0] = 0xDD9933;
		line->x0++;
	}
	printf("x =%d x0=%d x1=%d\n", x, line->x0, line->x1);
	while (line->y0 > (y * map_info->dy))
	{
		window->data[line->y0 * map_info->img_wide + line->x0] = 0xFFFFFF;
		line->y0--;
	}
	while (line->x0 > (x * map_info->dx))
	{
		window->data[line->y0 * map_info->img_wide + line->x0] = 0xFFFFFF;
		line->x0--;
	}
}

void	drwMap(t_windows *window, t_map *map_info, t_line *line, char **map)
{
	int	x;
	int	y;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == '1')
				cube(window, x, y, map_info, line);
			x++;
		}
		y++;
	}
}

int	main(void)
{
	t_windows	*window;
	t_line		*line;
	t_map		*map_info;
	char		*map[10];

	//** start: map**//
	map[0] = "1111111111";
	map[1] = "1000000001";
	map[2] = "1000000001";
	map[3] = "1000000001";
	map[4] = "1000000001";
	map[5] = "1000000001";
	map[6] = "1000000001";
	map[7] = "1000000001";
	map[8] = "1000000001";
	map[9] = "1111111111";
	map[10] = NULL;
	//** end: map**//
	window = (t_windows *)malloc(sizeof(t_windows));
	line = (t_line *)malloc(sizeof(t_line));
	map_info = (t_map *)malloc(sizeof(t_map));
	init_map(map_info);            // init map_info
	init_window(window, map_info); // init window
	init_line(line);             // init line
	drwMap(window, map_info, line, map); // draw map
	mlx_put_image_to_window(window->mlx, window->win, window->img, 50, 50);
	mlx_loop(window->mlx);
}
//** end: exmaple **//