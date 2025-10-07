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
	//parse_file(cub, av[1]): // lecture complete et stock textures, couleur et map
	//check_textures(cub); // verifie que c'est correct
	//check_colors(cub); // same
	check_map(cub); // invalid char, line, player puis wall (?) a supp si floodfill ? 
	// flood fill ici ? A la toute fin ( apres player ) 

}


//OUVERTURE ET LECTURE DU FICHIER
// verif que le fichier est lisible ( open + gestion erreur ) OK ---
// lecture ligne par ligen  ( get next line ?? ) 
// ensuite check :
// 1-  parametre ( texture et couleur )
// 			- texture ( NO SO ...) definie une seule fois + verif que le chemin existe ( open)
//			- couleur ( FC ) : velur separe par ',' + 3 composantes + chaque composante (0 255)
// 2- la map ( 0 1 N S E W)
//			- caractere valide only comme ds so_long mais avec 0, 1, N, S, E, W
//			- un seul joueur 
//			- map fermee par murs ( bordure avec 1 et flood fill aussi ?)


void	parse_file(t_cub *cub, char *pathname)
{
	int		fd;
	char	*line;

	fd = open(pathname, O_RDONLY);
	while ((line = get_next_line(fd)) != NULL) // attention a reprednre 
	{
		// degager les \n ?? faire fonction 
		// ignorer les lignes vides 

		// detecter le debut de la map et mettre un flag debutdemap ( map_start)
		// check si ya 0 1 n e ... et si oui flag ok

		// sinon on parse les param :
		//parse_texture_line()
		//parse_color_line()
		// attention si qqch d'invalid free et exit a chaque fois 


		free(line);
	}
	close(fd);
	// remplir la struct avec les element du parsing 
	//cub->map. ...
	//cub->map. ...
	//cub->map. ... check la struct again 

	// free ?
	// clean ?
}

// parsing de la ligne de texture : "NO ./path/to/texture.xpm"
void	parse_texture_line(t_cub *cub, char *line)
{

}

// parsing de la ligne des couleurs floor et ceiling ex :  "F 220,100,0"
void	parse_color_line(t_cub *cub, char *line)
{

}

// alloc du tableau de ligen de la map 
char	**alloc_map_line(char **map, int *count, char *line)
{

}



// faire un flood fill aussi ? 
// check path ? 
// lignes vides avant et apres la map mais pas au milieu 

// faire des messages d’erreur pour chaque cas et quitter de maniere clean