/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlichten <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 02:07:23 by hlichten          #+#    #+#             */
/*   Updated: 2025/11/30 02:07:24 by hlichten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	ft_error(t_error error)
{
	ft_putstr_fd("Error\n", STDERR_FILENO);
	if (error == ERR_ARGS)
		ft_putstr_fd("Need: ./cub3d map.cub\n", STDERR_FILENO);
	else if (error == ERR_FILE_EXT)
		ft_putstr_fd("File must have .cub extension\n", STDERR_FILENO);
	else if (error == ERR_MEMORY)
		ft_putstr_fd("Memory allocation failed while ", STDERR_FILENO);
	else if (error == ERR_MAP_INVALID)
		ft_putstr_fd("Map invalid\n", STDERR_FILENO);
	else if (error == ERR_MAP_INVALID_CHAR)
		ft_putstr_fd("Map invalid (wrong char)\n", STDERR_FILENO);
	else if (error == ERR_MAP_WALLS)
		ft_putstr_fd("Map not enclosed with walls\n", STDERR_FILENO);
	else if (error == ERR_MAP_PATH)
		ft_putstr_fd("Invalid path\n", STDERR_FILENO);
	else if (error == ERR_FILE_NOT_FOUND)
		ft_putstr_fd("File not found\n", STDERR_FILENO);
	else if (error == ERR_PLAYER)
		ft_putstr_fd("Error player: ", STDERR_FILENO);
	else if (error == ERR_MAP_LINE)
		ft_putstr_fd("No empty line on the map\n", STDERR_FILENO);
	else if (error == ERR_COLOR)
		ft_putstr_fd("Invalid color: ", STDERR_FILENO);
	else if (error == ERR_TEXTURE)
		ft_putstr_fd("Invalid texture: ", STDERR_FILENO);
}
