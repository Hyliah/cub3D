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

// ma fonction ft_error de so_long A MODIFIER
void	ft_error(t_error error)
{
	ft_putstr_fd("Error\n", STDERR_FILENO);
	if (error == ERR_ARGS)
		ft_putstr_fd("Need: ./cub3d map.cub\n", STDERR_FILENO);
	else if (error == ERR_FILE_EXT)
		ft_putstr_fd("File must have .cub extension\n", STDERR_FILENO);
	else if (error == ERR_MAP_SIZE)
		ft_putstr_fd("Map must be ... something \n", STDERR_FILENO); // a modif ??
	else if (error == ERR_MAP_INVALID)
		ft_putstr_fd("Map invalid \n", STDERR_FILENO);
	else if (error == ERR_MAP_INVALID_CHAR)
		ft_putstr_fd("Map invalid (wrong char)\n", STDERR_FILENO);
	else if (error == ERR_MAP_WALLS)
		ft_putstr_fd("Map not enclosed with walls\n", STDERR_FILENO);
	else if (error == ERR_MAP_PATH)
		ft_putstr_fd("Invalid path\n", STDERR_FILENO);
	else if (error == ERR_MAP_NOT_FOUND)
		ft_putstr_fd("Map not found\n", STDERR_FILENO);
	else if (error == ERR_NO_PLAYER)
		ft_putstr_fd("Need player on the map\n", STDERR_FILENO);
	exit(EXIT_FAILURE);
}

// changer faire un ft error exit ? avec cub et code pour affichage direct du mess et clean exit 

// faire fonction de trim pour remplacer les \n par des \0 

// get map width pour renvoyer la longueru max ? 
