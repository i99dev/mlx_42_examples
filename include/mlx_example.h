/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_example.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oal-tena <oal-tena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 10:03:41 by oal-tena          #+#    #+#             */
/*   Updated: 2022/08/21 13:10:44 by oal-tena         ###   ########.fr       */
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

# include <fcntl.h>
# include <math.h>
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <time.h>
# include <unistd.h>


#endif