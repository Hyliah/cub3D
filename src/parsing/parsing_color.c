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
void parse_color_line(t_cub *cub, char *line)
{
    t_rgb   color;
    int     i;

    i = 0;
    while (line[i] && (line[i] == ' ' || line[i] == '\t'))
        i++;
    if (!line[i] || (line[i] != 'F' && line[i] != 'C'))
    {
        ft_error(ERR_COLOR);
        ft_putstr_fd("Invalid color identifier (must be F or C)\n", 2);
        clean_exit_parsing(cub);
    }
    
    char identifier = line[i];
    i++; // Passe le F ou C

    // Skip les espaces entre F/C et les valeurs RGB
    while (line[i] && (line[i] == ' ' || line[i] == '\t'))
        i++;

    // Parse la partie RGB
    color = parse_rgb(cub, &line[i]);

    // Assigne la couleur au bon composant
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
		cub->setting.f_color = color;
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
		cub->setting.c_color = color;
		cub->setting.has_ceiling = 1;
}
