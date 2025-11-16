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

void	parse_color_line(t_cub *cub, char *line)
{
	t_rgb	color;
	int		i;
	char	identifier;

	i = 0;
	while (line[i] && (line[i] == ' ' || line[i] == '\t'))
		i++;
	if (!line[i] || (line[i] != 'F' && line[i] != 'C'))
	{
		ft_error(ERR_COLOR);
		ft_putstr_fd("Invalid color identifier (must be F or C)\n", 2);
		clean_exit_parsing(cub);
	}
	identifier = line[i];
	i++;
	while (line[i] && (line[i] == ' ' || line[i] == '\t'))
		i++;
	color = parse_rgb(cub, &line[i]);
	if (identifier == 'F')
		parse_color_floor(cub, color);
	else
		parse_color_ceiling(cub, color);
}

void	parse_color_floor(t_cub *cub, t_rgb color)
{
	if (cub->setting.has_floor)
	{
		ft_error(ERR_COLOR);
		ft_putstr_fd("Duplicate floor color definition\n", 2);
		clean_exit_parsing(cub);
	}
	cub->setting.rgb_f_color = color;
	cub->setting.f_color = rgb_to_hex(color);
	cub->setting.has_floor = 1;
}

void	parse_color_ceiling(t_cub *cub, t_rgb color)
{
	if (cub->setting.has_ceiling)
	{
		ft_error(ERR_COLOR);
		ft_putstr_fd("Duplicate ceiling color definition\n", 2);
		clean_exit_parsing(cub);
	}
	cub->setting.rgb_c_color = color;
	cub->setting.c_color = rgb_to_hex(color);
	cub->setting.has_ceiling = 1;
}

int	rgb_to_hex(t_rgb color)
{
	return ((color.r << 16) | (color.g << 8) | color.b);
}

t_bool	check_comma(char *str)
{
	int	comma;
	int	i;

	comma = 1;
	i = 0;
	while (str[i])
	{
		if (str[i] && str[i] == ',')
		{
			if (comma)
				return (FALSE);
			comma = 1;
		}
		else if (str[i] && str[i] != ',')
			comma = 0;
		i++;
	}
	if (comma == 1)
		return (FALSE);
	return (TRUE);
}
