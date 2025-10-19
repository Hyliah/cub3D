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

// fonction parse rgb ?? 
t_rgb	parse_rgb(t_cub *cub, char *str)
{
	char	**rgb;
	t_rgb	color;
	int		count;

	check_rgb_format(cub, str);
	ft_strtrim_spaces(str);
	rgb = ft_split(str, ',');
	if(!rgb || !rgb[0] || !rgb[1] || !rgb[2])
	{
		ft_error(ERR_COLOR);
		ft_putstr_fd("Invalid RGB format (need 3 components : R, G, B)\n", 2);
		clean_exit_parsing(cub);
	}
	count = 0;
	while (rgb[count])
		count++;
	if (count != 3)
	{
		ft_error(ERR_COLOR);
		ft_putstr_fd("Invalid RGB format (too many or missing components)\n", 2);
		free_tab(&rgb);
		clean_exit_parsing(cub);
	}
	color = convert_and_check_rgb(cub, rgb);
	return(color);
}

void	check_rgb_format(t_cub *cub, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]) && str[i] != ',' && str[i] != ' ' && str[i] != '\t')
		{
			ft_error(ERR_COLOR);
			ft_putstr_fd("Invalid RGB format (must contain only digits and commas)\n", 2);
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
	return(color);
}
