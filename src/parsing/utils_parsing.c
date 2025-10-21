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

void	ft_strtrim_newline(char *line)
{
	int	len;

	if (!line)
		return ;
	len = ft_strlen(line);
	if (len > 0 && line[len - 1] == '\n')
		line[len - 1] = '\0';
}

void	ft_strtrim_spaces(char *s)
{
	char	*dst;

	dst = s;
	while (*s)
	{
		if (*s != ' ' && *s != '\t')
			*dst++ = *s;
		s++;
	}
	*dst = '\0';
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

int	open_cub_file(t_cub *cub, char *pathname)
{
	int	fd;

	fd = open(pathname, O_RDONLY);
	if (fd < 0)
	{
		ft_error(ERR_FILE_NOT_FOUND);
		clean_exit_parsing(cub);
	}
	return (fd);
}
