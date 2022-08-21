/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oal-tena <oal-tena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 13:08:58 by oal-tena          #+#    #+#             */
/*   Updated: 2022/08/21 13:10:55 by oal-tena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/mlx_example.h"

char *ft_strjoin(char *line,char c)
{
	int len = 0;
	char *str;
	int i = 0;
	while (line && line[len])
	{
		len++;
	}
	str = malloc(len + 2);
	if (line)
	{
		while (line[i])
		{
			str[i] = line[i];
			i++;
		}
	}
	str[i] = c;
	i++;
	str[i] = '\0';
	free(line);
	return(str);
}

char *get_next_line(int fd)
{
	char *line = NULL;
	char c;
	int i;
	i = read(fd,&c,1);
	while (i)
	{
		line = ft_strjoin(line,c);
		if (c == '\n')
			break;
		i = read(fd,&c,1);
	}
	return (line);
}