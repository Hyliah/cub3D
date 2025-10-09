/*****************************************************************************/
/*                                                                           */
/*                                                                           */
/*                       LES CODEUSES DU DIMANCHE                            */
/*                               FONT UN                                     */
/*                        __  _  _  ___  ___  ___                            */
/*                       / _)( )( )(  ,)(__ )(   \                           */
/*                      ( (_  )()(  ) ,\ (_ \ ) ) )                          */
/*                       \__) \__/ (___/(___/(___/                           */
/*                                                                           */
/*****************************************************************************/

#include "cub.h"

// ma fonction ft_error de so_long
void	ft_error(t_error error)
{
	ft_putstr_fd("Error\n", STDERR_FILENO);
	if (error == ERR_ARGS)
		ft_putstr_fd("Need: ./cub3d map.cub\n", STDERR_FILENO);
	else if (error == ERR_FILE_EXT)
		ft_putstr_fd("File must have .cub extension\n", STDERR_FILENO);
	else if (error == ERR_MAP_SIZE)
		ft_putstr_fd("Map must be ... something \n", STDERR_FILENO); // a garder ?? pas utilise so far
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
	else if (error == ERR_NO_PLAYER)
		ft_putstr_fd("Need player on the map\n", STDERR_FILENO);
	else if (error == ERR_TOO_MANY_PLAYERS)
		ft_putstr_fd("Too many players on the map\n", STDERR_FILENO);
	else if (error == ERR_MAP_LINE)
		ft_putstr_fd("No empty line on the map\n", STDERR_FILENO);
	else if (error == ERR_COLOR)
		ft_putstr_fd("Invalid color\n", STDERR_FILENO);
	exit(EXIT_FAILURE);
}

// faire fonction de trim pour remplacer les \n par des \0 
void	ft_strtrim_newline(char *line)
{
	int len;

	if (!line)
		return;
	len = ft_strlen(line);
	if ( len > 0 && line[len - 1] == '\n')
		line[len - 1] = '\0';
}

// get map width pour renvoyer la longueru max ? 
int	get_map_width(char **map, int height)
{
	int	max_width;
	int	current_width;
	int	i;

	if (!map || height == 0)
		return (0);
	max_width = 0;
	i = 0;
	while ( i < height)
	{
		current_width = ft_strlen(map[i]);
		if (current_width > max_width)
			max_width = current_width;
		i++;
	}
	return(max_width);
}
