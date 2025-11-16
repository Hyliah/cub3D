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

void	parse_texture_line(t_cub *cub, char *line)
{
	char	**split;

	empty_texture_line(cub, line);
	split = split_texture_line(cub, line);
	parse_orientation(cub, split);
	free_tab(&split);
}

void	empty_texture_line(t_cub *cub, char *line)
{
	if (!line || !*line)
	{
		ft_error(ERR_TEXTURE);
		ft_putstr_fd("Empty texture line\n", 2);
		clean_exit_parsing(cub);
	}
}

char	**split_texture_line(t_cub *cub, char *line)
{
	char	**split;

	while (*line && (*line == ' ' || *line == '\t'))
		line++;
	split = ft_split(line, ' ');
	if (!split || !split[0] || !split[1] || split[2])
	{
		free_tab(&split);
		ft_error(ERR_TEXTURE);
		ft_putstr_fd("Invalid texture format\n", 2);
		clean_exit_parsing(cub);
	}
	return (split);
}

void	parse_orientation(t_cub *cub, char **split)
{
	char	*orientation;
	char	*path;

	orientation = split[0];
	path = split[1];
	if (ft_strncmp(orientation, "NO", 3) == 0)
		parse_text_no(cub, path, split);
	else if (ft_strncmp(orientation, "SO", 3) == 0)
		parse_text_so(cub, path, split);
	else if (ft_strncmp(orientation, "EA", 3) == 0)
		parse_text_ea(cub, path, split);
	else if (ft_strncmp(orientation, "WE", 3) == 0)
		parse_text_we(cub, path, split);
	else
	{
		free_tab(&split);
		ft_error(ERR_TEXTURE);
		ft_putstr_fd("Invalid texture orientation\n", 2);
		clean_exit_parsing(cub);
	}
}
