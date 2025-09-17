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

// check extension .cub
// modif de la fonction check_ber de mon so_long
void	check_cub(char *pathname)
{
	int		len;
	char	*extension;

	len = ft_strlen(pathname);
	if (len < 4)
		// faire fonction erreur here;
		ft_error(ERR_FILE_EXT);
	extension = pathname + (len - 4);
	if (ft_strncmp(extension, ".cub", 4) != 0)
		// faire fonction erreur here;
		ft_error(ERR_FILE_EXT);
}

// check presence de toutes les textures NO, SO, WE, EA

// check les couleurs ( entre 0 - 255)

// check validité des maps
// -> entourée de murs (1)
// -> validité des caracteres comme ds so_long mais avec 0, 1, N, S, E, W

// faire des messages d’erreur pour chaque cas et quitter de maniere clean