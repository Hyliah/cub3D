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

// TO DO POUR LE PARSING

// check arg ? 
void check_arg(t_cub *cub, int ac, char **av)
{
	if (ac != 2)
	{
		clean_exit(cub);
		// ft_error mess : need map 
	}
	// check si arg NULL ? important ou redondant ? !av[1] || !av[1][0]
}

// check extension .cub
// modif de la fonction check_ber de mon so_long
void	check_cub(char *pathname)
{
	int		len;
	char	*extension;

	len = ft_strlen(pathname);
	if (len < 4)
	{
		// exit proprement, fonction clean_exit ? 
		ft_error(ERR_FILE_EXT); // Fonction a modifier
	}
	extension = pathname + (len - 4);
	if (ft_strncmp(extension, ".cub", 4) != 0)
	{
		// exit proprement, fonction clean_exit ? 
		ft_error(ERR_FILE_EXT); // Fonction a modifier
	}
}

// check presence de toutes les textures NO, SO, WE, EA
void check_direction()
{

}

// check les couleurs ( entre 0 - 255)
void check_color()
{

}

// faire comme so_long ? no player, too many player ?? 
void check_player()
{

}

// check validité des maps
// -> entourée de murs (1)
// -> validité des caracteres comme ds so_long mais avec 0, 1, N, S, E, W

void	check_wall()
{

}

void	check_invalid_char()
{

}
// faire un flood fill aussi ? 
// check path ? 

// faire des messages d’erreur pour chaque cas et quitter de maniere clean