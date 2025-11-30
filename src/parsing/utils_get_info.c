/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_get_info.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlichten <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 02:07:12 by hlichten          #+#    #+#             */
/*   Updated: 2025/11/30 02:07:13 by hlichten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

char	*get_next_valid_line(t_cub *cub, int fd)
{
	char	*line;

	line = get_next_line(fd);
	while (line)
	{
		ft_strtrim_newline(line);
		if (!cub->map.map_start && is_empty_line(line))
		{
			free(line);
			line = get_next_line(fd);
			ft_strtrim_newline(line);
		}
		return (line);
	}
	return (NULL);
}

int	get_map_width(char **map, int height)
{
	int	max_width;
	int	current_width;
	int	i;

	if (!map || height == 0)
		return (0);
	max_width = 0;
	i = 0;
	while (i < height)
	{
		current_width = ft_strlen(map[i]);
		if (current_width > max_width)
			max_width = current_width;
		i++;
	}
	return (max_width);
}

int	get_map_height(char **map)
{
	int	height;

	height = 0;
	if (!map)
		return (0);
	while (map[height])
		height++;
	return (height);
}
