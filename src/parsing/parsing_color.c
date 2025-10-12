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

// parsing de la ligne des couleurs floor et ceiling ex :  "F 220,100,0"
void	parse_color_line(t_cub *cub, char *line)
{
	char	**split;
	t_rgb	color;

	split = ft_split(line, ' ');
	if (!split || !split[0] || !split[1])
	{
		ft_error(ERR_COLOR);
		// mess extra ici ?
		clean_exit_parsing(cub);
	}
	color = parse_rgb(cub, split[1]);
	if (ft_strncmp(split[0], "F", 2) == 0)
		parse_color_floor(cub, color);
	else if (ft_strncmp(split[0], "C", 2) == 0)
		parse_color_ceiling(cub, color);
	else
	{
		ft_error(ERR_COLOR);
		// extra mess ?
		clean_exit_parsing(cub);
	}
	free_tab(split);
}
void	parse_color_floor(t_cub *cub, t_rgb color)
{
	if (cub->setting.has_floor)
		{
			ft_error(ERR_COLOR);
			// mess extra ici ? color floor alreadz defined ? duplicate floor ?
			clean_exit_parsing(cub);
		}
		cub->setting.f_color = color;
		cub->setting.has_floor = 1;
}
void	parse_color_ceiling(t_cub *cub, t_rgb color)
{
	if (cub->setting.has_ceiling)
		{
			ft_error(ERR_COLOR);
			// mess extra ici ? color ceiling alreadz defined ? duplicate ceiling?
			clean_exit_parsing(cub);
		}
		cub->setting.c_color = color;
		cub->setting.has_ceiling = 1;
}

// fonction parse rgb ?? 
t_rgb	parse_rgb(t_cub *cub, char *str)
{
	char	**rgb;
	t_rgb	color;

	rgb = ft_split(str, ',');
	if (!rgb || !rgb[0] || !rgb[1] || !rgb[2])
	{
		ft_error(ERR_COLOR);
		// mess extra ici ? invalid rgb format. 
		clean_exit_parsing(cub);
	}
	color.r = ft_atoi(rgb[0]);
	color.g = ft_atoi(rgb[1]);
	color.b = ft_atoi(rgb[2]);
	free_tab(rgb);
	if (color.r < 0 || color.r > 255 || color.g < 0 ||
		color.g > 255 || color.b < 0 || color.b > 255)
		{
			ft_error(ERR_COLOR);
			// mess extra ici ? must be between 0 255
			clean_exit_parsing(cub);
		}
	return (color);
}
