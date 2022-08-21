/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main,c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaljaber <aaljaber@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 19:25:46 by aaljaber          #+#    #+#             */
/*   Updated: 2022/08/21 20:07:44 by aaljaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include	"../MLX/mlx.h"
# include	"./key_macos.h"

typedef struct mlx
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
	int		width;
	int		height;
}	t_mlx;

int	shape(int key, void	*param)
{
	t_mlx *info;

	info = (t_mlx *)param;
	if (key == K_S)
		mlx_put_image_to_window(info->mlx_ptr, info->win_ptr, info->img_ptr, 0, 0);
	else if (key == K_H)
		mlx_clear_window(info->mlx_ptr, info->win_ptr);
	return (0);
}

int main ()
{
	t_mlx	info;

	info.mlx_ptr = mlx_init();
	info.img_ptr = mlx_png_file_to_image(info.mlx_ptr, "key_hook/shape.png", &info.width, &info.height);
	info.win_ptr = mlx_new_window(info.mlx_ptr, info.width, info.height, "key_hook");
	mlx_key_hook(info.win_ptr, &shape, &info);
	mlx_loop(info.mlx_ptr);
}