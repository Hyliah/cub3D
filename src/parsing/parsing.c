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


// faire fonction globale avec tt dedans 
void	parsing(t_cub *cub, int ac, char **av)
{
	check_arg(cub, ac, av);
	check_cub(cub, av[1]);
	check_file_access(cub, av[1]);
	parse_file(cub, av[1]); // lecture complete et stock textures, couleur et map
	check_textures(cub); // verifie que c'est correct
	check_colors(cub); // same
	check_map(cub); // invalid char, line, player puis wall (?) a supp si floodfill ? 
	// flood fill ici ? A la toute fin ( apres player ) 

}

void	parse_file(t_cub *cub, char *pathname)
{
	int		fd;
	char	*line;
	int		map_start;
	int		map_count;
	char	**map_lines ;

	map_start = 0;
	map_count = 0;
	map_lines = NULL;

	fd = open(pathname, O_RDONLY);
	if ( fd < 0)
	{
		ft_error(ERR_FILE_NOT_FOUND);
		clean_exit_parsing(cub);
	}
	line = get_next_line(fd);
	while (line != NULL) 
	{
		// degager les \n ?? faire fonction de trim ? 
		ft_strtrim_newline(line);

		// ignorer les lignes vides AVANT LA MAP //
		if (is_empty_line(line))
		{
			free(line);
			line = get_next_line(fd);
			continue;
		}

		// detecter le debut de la map et mettre un flag debutdemap ( map_start)
		if (!map_start)
		{
			if (is_map_line(line)) // evite de skip la first line 
			{
				map_start = 1;
				map_lines = alloc_map_line(map_lines, &map_count, line);
				map_count++;
			}
			else if (is_texture_line(line))
				parse_texture_line(cub, line);
			else if (is_color_line(line))
				parse_color_line(cub, line);
			else
			{
				free(line);
				ft_error(ERR_MAP_INVALID);
				clean_exit_parsing(cub);
			}
		}

		// on va stocker la ligne de map
		else 
		{
			if (!is_map_line(line)) // pour verif si y'a qqchose apres erreur 
			{
				ft_error(ERR_MAP_INVALID);
				clean_exit_parsing(cub);
			}
			map_lines = alloc_map_line(map_lines, &map_count, line);
			map_count++;
		}
		free(line);
		line = get_next_line(fd);
	}
	close(fd);

	// verif si aucune ligne trouvee 
	if ( map_count == 0)
	{
		ft_error(ERR_MAP_INVALID);
		clean_exit_parsing(cub);
	}
	// remplir la struct avec les element du parsing 
	cub->map.map_tab = map_lines;
	cub->map.height = map_count;
	cub->map.width = get_map_width(map_lines, map_count);
}


// alloc du tableau de ligen de la map 
char	**alloc_map_line(char **map, int *count, char *line)
{
	char	**new;
	int 	i;

	new = malloc(sizeof(char *) * (*count + 2));
	if (!new)
	{
		ft_error(ERR_MAP_INVALID);
		clean_exit_parsing;
	}
	i = 0;
	while ( i < *count)
	{
		new[i] = map[i];
		i++;
	}
	new[i] = ft_strdup(line);
	if (!new[i])
	{
		free(new);
		ft_error(ERR_MAP_INVALID);
		clean_exit_parsing;
	}
	new[i + 1] = NULL;
	free(map);
	return (new);
}



// faire un flood fill aussi ? 
// check path ? 
// lignes vides avant et apres la map mais pas au milieu 

// faire des messages d’erreur pour chaque cas et quitter de maniere clean