/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlichten <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 02:07:17 by hlichten          #+#    #+#             */
/*   Updated: 2025/11/30 02:07:18 by hlichten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	is_config_line(char *line)
{
	while (*line && (*line == ' ' || *line == '\t'))
		line++;
	if (!ft_strncmp(line, "NO ", 3)
		|| !ft_strncmp(line, "SO ", 3)
		|| !ft_strncmp(line, "WE ", 3)
		|| !ft_strncmp(line, "EA ", 3)
		|| line[0] == 'F'
		|| line[0] == 'C')
		return (1);
	return (0);
}

int	is_map_line(char *line)
{
	int	i;

	while (*line && (*line == ' ' || *line == '\t'))
		line++;
	if (is_config_line(line))
		return (0);
	i = 0;
	while (line[i])
	{
		if (line[i] != '0' && line[i] != '1' && line[i] != 'N' && line[i] != 'S'
			&& line[i] != 'E' && line[i] != 'W' && line[i] != ' '
			&& line[i] != 'D')
			return (0);
		i++;
	}
	return (1);
}

int	is_empty_line(char *line)
{
	int	i;

	if (!line)
		return (1);
	i = 0;
	while (line[i])
	{
		if (line[i] != ' ' && line[i] != '\t' && line[i] != '\n')
			return (0);
		i++;
	}
	return (1);
}

int	is_texture_line(char *line)
{
	while (*line && (*line == ' ' || *line == '\t'))
		line++;
	if (!ft_strncmp(line, "NO ", 3) || !ft_strncmp(line, "SO ", 3)
		|| !ft_strncmp(line, "EA ", 3) || !ft_strncmp(line, "WE ", 3))
		return (1);
	return (0);
}

int	is_color_line(char *line)
{
	while (*line && (*line == ' ' || *line == '\t'))
		line++;
	if (!ft_strncmp(line, "F ", 2) || !ft_strncmp(line, "C ", 2))
		return (1);
	return (0);
}
