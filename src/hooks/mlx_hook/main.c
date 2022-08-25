/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaljaber <aaljaber@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 01:14:40 by aaljaber          #+#    #+#             */
/*   Updated: 2022/08/26 01:23:59 by aaljaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../MLX/mlx.h"
# include <stdlib.h>

typedef struct mlx
{
	void	*mlx_ptr;
	void	*win_ptr;
}	t_mlx;

int	close(t_mlx *info)
{
	mlx_destroy_window(info->mlx_ptr, info->win_ptr);
	exit (0);
}

int main ()
{
	t_mlx	info;

	info.mlx_ptr = mlx_init();
	info.win_ptr = mlx_new_window(info.mlx_ptr, 300, 500, "loop_hook");
	mlx_hook(info.win_ptr, 17, 1L << 17, &close, &info);
	mlx_loop(info.mlx_ptr);
}