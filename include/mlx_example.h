/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_example.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oal-tena <oal-tena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 10:03:41 by oal-tena          #+#    #+#             */
/*   Updated: 2022/08/09 10:50:23 by oal-tena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_EXAMPLE_H
# define MLX_EXAMPLE_H


# ifdef __linux__
#  include "../lib/minilibx-linux/mlx.h"
#  include "key_linux.h"
#  define ESCAPE_KEY 65307
# endif

# ifdef __APPLE__
#  include "../lib/macos/mlx.h"
#  include "key_macos.h"
#  define ESCAPE_KEY 53
# endif




#endif