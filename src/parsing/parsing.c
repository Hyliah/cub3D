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

void	parsing(t_cub *cub, int ac, char **av)
{
	check_arg(cub, ac, av);
	check_cub(cub, av[1]);
	check_file_access(cub, av[1]);
	parse_file(cub, av[1]);
	check_texture(cub);
	check_color(cub);
	check_player(cub);
	check_size(cub);
	check_wall(cub);
}

void	parse_file(t_cub *cub, char *pathname )
{
	int		fd;
	char	*line;

	fd = open_cub_file(cub, pathname);
	line = get_next_valid_line(cub, fd);
	cub->map.current_line = line;
	while (line)
	{
		if (line[0])
		{
			if (!cub->map.map_start)
				process_config_line(cub, line);
		}
		if (cub->map.map_start)
			process_map_line(cub, line);
		free(line);
		cub->map.current_line = NULL;
		line = get_next_valid_line(cub, fd);
		cub->map.current_line = line;
	}
	close(fd);
	finalize_map_parsing(cub);
}

void	process_config_line(t_cub *cub, char *line)
{
	if (is_map_line(line))
		cub->map.map_start = 1;
	else if (is_texture_line(line))
		parse_texture_line(cub, line);
	else if (is_color_line(line))
		parse_color_line(cub, line);
	else
	{
		ft_error(ERR_MAP_INVALID);
		ft_putstr_fd("Invalid config line\n", 2);
		clean_exit_parsing(cub);
	}
}

void	process_map_line(t_cub *cub, char *line)
{
	int	is_only_one;

	is_only_one = 0;
	cub->map.map_tab = alloc_map_line(cub, cub->map.map_tab,
			&cub->map.height, line);
	is_only_one = is_map_bottom_line(line);
	if (is_only_one == 1)
		cub->map.count_only_one++;
	if (cub->map.count_only_one == 2 && !is_map_line(line))
	{
		ft_error(ERR_MAP_INVALID);
		ft_putstr_fd("Element should not be after the map\n", 2);
		clean_exit_parsing(cub);
	}
	check_invalid_char(cub);
	check_line_empty_in_map(cub);
}

void	finalize_map_parsing(t_cub *cub)
{
	if (cub->map.height == 0)
	{
		ft_error(ERR_MAP_INVALID);
		ft_putstr_fd("No map lines were found\n", 2);
		clean_exit_parsing(cub);
	}
	cub->map.height = get_map_height(cub->map.map_tab);
	cub->map.width = get_map_width(cub->map.map_tab, cub->map.height);
}
