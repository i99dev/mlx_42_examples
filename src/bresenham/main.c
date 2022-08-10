/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oal-tena <oal-tena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 12:49:23 by oal-tena          #+#    #+#             */
/*   Updated: 2022/08/10 04:21:20 by oal-tena         ###   ########.fr       */
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
//** end: headre **//

//** start: exmaple **//
void	init_window(t_windows *window)
{
	window->mlx = mlx_init();
	window->win = mlx_new_window(window->mlx, WIDTH, HEIGHT, "mlx_ex01");
	window->img = mlx_new_image(window->mlx, WIDTH, HEIGHT);
	window->data = (int *)mlx_get_data_addr(window->img, &window->bpp,
			&window->size_line, &window->endian);
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

int	main(void)
{
	int			fd;
	t_windows	*window;
	t_line		*line;

	fd = open("src/bresenham/42.fdf", O_RDONLY);
	printf("%d\n", fd);
	window = (t_windows *)malloc(sizeof(t_windows));
	line = (t_line *)malloc(sizeof(t_line));
	init_window(window);
	init_line(line);
	mlx_put_image_to_window(window->mlx, window->win, window->img, 0, 0);
	mlx_loop(window->mlx);
}
//** end: exmaple **//