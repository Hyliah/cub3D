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

t_rgb	parse_rgb(t_cub *cub, char *str)
{
	char	**rgb;
	t_rgb	color;
	int		count;

	check_rgb_format(cub, str);
	rgb = ft_split(str, ',');
	if (!rgb)
		clean_exit_parsing(cub);
	count = 0;
	while (rgb[count])
	{
		ft_strtrim_spaces(rgb[count]);
		check_rgb_component(cub, rgb[count], rgb);
		count++;
	}
	if (count != 3)
	{
		ft_error(ERR_COLOR);
		ft_putstr_fd("Invalid RGB format (need 3 components : R, G, B)\n", 2);
		free_tab(&rgb);
		clean_exit_parsing(cub);
	}
	color = convert_and_check_rgb(cub, rgb);
	return (color);
}

void	check_rgb_format(t_cub *cub, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]) && str[i] != ',' && str[i] != ' '
			&& str[i] != '\t')
		{
			ft_error(ERR_COLOR);
			ft_putstr_fd("Invalid RGB format", 2);
			ft_putstr_fd(" (must contain only digits and commas)\n", 2);
			clean_exit_parsing(cub);
		}
		check_no_space_between_digits(cub, str, i);
		i++;
	}
	if (check_comma(str) == FALSE)
	{
		ft_error(ERR_COLOR);
		ft_putstr_fd(COMMA, 2);
		clean_exit_parsing(cub);
	}
}

void	check_no_space_between_digits(t_cub *cub, char *str, int i)
{
	int	j;

	if (ft_isdigit(str[i]) && (str[i + 1] == ' ' || str[i + 1] == '\t'))
	{
		j = i + 1;
		while (str[j] == ' ' || str[j] == '\t')
			j++;
		if (ft_isdigit(str[j]))
		{
			ft_error(ERR_COLOR);
			ft_putstr_fd("Invalid RGB format (space between digits)\n", 2);
			clean_exit_parsing(cub);
		}
	}
}

void	check_rgb_component(t_cub *cub, char *comp, char **rgb)
{
	int	i;

	i = 0;
	if (comp[0] == '0' && comp[1] != '\0')
	{
		ft_error(ERR_COLOR);
		ft_putstr_fd("Invalid RGB component (no '0' at the beggining)\n", 2);
		free_tab(&rgb);
		clean_exit_parsing(cub);
	}
	check_rgb_component_length(cub, comp, rgb);
	while (comp[i])
	{
		if (!ft_isdigit(comp[i]))
		{
			ft_error(ERR_COLOR);
			ft_putstr_fd("RGB components must be digits only\n", 2);
			free_tab(&rgb);
			clean_exit_parsing(cub);
		}
		i++;
	}
}

t_rgb	convert_and_check_rgb(t_cub *cub, char **rgb)
{
	t_rgb	color;

	color.r = ft_atoi(rgb[0]);
	color.g = ft_atoi(rgb[1]);
	color.b = ft_atoi(rgb[2]);
	free_tab(&rgb);
	if (color.r < 0 || color.r > 255
		|| color.g < 0 || color.g > 255
		|| color.b < 0 || color.b > 255)
	{
		ft_error(ERR_COLOR);
		ft_putstr_fd("Color value must be between 0 and 255\n", 2);
		clean_exit_parsing(cub);
	}
	return (color);
}
