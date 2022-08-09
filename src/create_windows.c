/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_windows.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oal-tena <oal-tena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 09:49:20 by oal-tena          #+#    #+#             */
/*   Updated: 2022/08/09 12:19:22 by oal-tena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/mlx_example.h"

#define WIDTH 800
#define HEIGHT 600

typedef struct create_windows
{
    void	*mlx;
    void	*win;
    void	*img;
    char	*data;
    int		bpp;
    int		size_line;
    int		endian;
}				t_create_windows;


void init_window(t_create_windows *window)
{
    window->mlx = mlx_init(); // Initialize the mlx library
    window->win = mlx_new_window(window->mlx, WIDTH, HEIGHT, "mlx_ex01");  // Create a new window
    window->img = mlx_new_image(window->mlx, WIDTH, HEIGHT); // Create a new image
    window->data = mlx_get_data_addr(window->img, &window->bpp, &window->size_line, &window->endian); // Get the address of the image data
}


int main (void)
{
    t_create_windows *window;

    window = (t_create_windows *)malloc(sizeof(t_create_windows));
    init_window(window);
    mlx_loop(window->mlx);
}