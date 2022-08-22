/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaljaber <aaljaber@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 19:25:46 by aaljaber          #+#    #+#             */
/*   Updated: 2022/08/21 21:34:18 by aaljaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include	"../MLX/mlx.h"
# include	 <unistd.h>

typedef struct mlx
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
	int		width;
	int		height;
}	t_mlx;

int	anime(t_mlx *info)
{
	static int	i;	
	char		*filename[6];

	filename[0] = "loop_hook/gif/1.xpm";
	filename[1] = "loop_hook/gif/2.xpm";
	filename[2] = "loop_hook/gif/3.xpm";
	filename[3] = "loop_hook/gif/4.xpm";
	mlx_clear_window(info->mlx_ptr, info->win_ptr);
	usleep (50000);
	info->img_ptr = mlx_xpm_file_to_image(info->mlx_ptr, filename[i], &info->width, &info->height);
	mlx_put_image_to_window(info->mlx_ptr, info->win_ptr, info->img_ptr, 0, 0);
	usleep(50000);
	if (i++ == 3)
		i = 0;
	return (1);
}

int main ()
{
	t_mlx	info;

	info.mlx_ptr = mlx_init();
	info.img_ptr = mlx_xpm_file_to_image(info.mlx_ptr, "loop_hook/gif/1.xpm", &info.width, &info.height);
	info.win_ptr = mlx_new_window(info.mlx_ptr, info.width, info.height, "loop_hook");
	mlx_put_image_to_window(info.mlx_ptr, info.win_ptr, info.img_ptr, 0, 0);
	mlx_loop_hook(info.mlx_ptr, &anime, &info);
	mlx_loop(info.mlx_ptr);
}