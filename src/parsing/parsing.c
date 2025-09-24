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

// faire fonction globale avec tt dedans 
void	parsing(t_cub *cub, int ac, char **av)
{
	check_arg(cub, ac, av);
	check_cub(cub, av[1]);
	check_file_access(cub, av[1]);
	//parse_file (pour lire ligne) a faire !!
	//check_textures(cub);
	//check_colors(cub);
	//check_player(cub);
	//check_map(cub); // avec dedans check_wall et check_invalid_char

}

// check arg 
void check_arg(t_cub *cub, int ac, char **av)
{
	if (ac != 2)
	{	
		ft_error(ERR_ARGS);
		clean_exit(cub);
	}
	if (!av[1] || !av[1][0] )
	{
		ft_error(ERR_ARGS); // (mettre un autre mess ?)
		clean_exit(cub);
	}
}

// check extension .cub
// modif de la fonction check_ber de mon so_long
void	check_cub(t_cub *cub, char *pathname)
{
	int		len;
	char	*extension;

	len = ft_strlen(pathname);
	if (len < 4)
	{
		ft_error(ERR_FILE_EXT);
		clean_exit(cub);
	}
	extension = pathname + (len - 4);
	if (ft_strncmp(extension, ".cub", 4) != 0)
	{
		ft_error(ERR_FILE_EXT);
		clean_exit(cub);
	}
}

//OUVERTURE ET LECTURE DU FICHIER
// verif que le fichier est lisible ( open + gestion erreur )
// lecture ligne par ligen  ( get next line ?? ) 
// ensuite check :
// 1-  parametre ( texture et couleur )
// 			- texture ( NO SO ...) definie une seule fois + verif que le chemin existe ( open)
//			- couleur ( FC ) : velur separe par ',' + 3 composantes + chaque composante (0 255)
// 2- la map ( 0 1 N S E W)
//			- caractere valide only comme ds so_long mais avec 0, 1, N, S, E, W
//			- un seul joueur 
//			- map fermee par murs ( bordure avec 1 et flood fill aussi ?)



//verif que le fichier est lisible ( open + gestion erreur )
void	check_file_access(t_cub *cub, char *pathname)
{
	int fd;

	fd = open(pathname, O_RDONLY);
	if (fd < 0)
	{
		ft_error(ERR_MAP_NOT_FOUND);
		clean_exit(cub);
	}
	close(fd);
}

void	parse_file(t_cub *cub)
{

}

// check presence de toutes les textures NO, SO, WE, EA
void check_texture(t_cub *cub)
{

}

// check les couleurs ( entre 0 - 255)
void check_color(t_cub *cub)
{
	
}

// faire comme so_long ? no player, too many player ?? 
void check_player(t_cub *cub)
{

}

// check validité des maps
// -> entourée de murs (1)
void	check_wall(t_cub *cub)
{

}
// -> validité des caracteres comme ds so_long mais avec 0, 1, N, S, E, W
void	check_invalid_char(t_cub *cub)
{

}
// faire un flood fill aussi ? 
// check path ? 
// lignes vides avant et apres la map mais pas au milieu 

// faire des messages d’erreur pour chaque cas et quitter de maniere clean