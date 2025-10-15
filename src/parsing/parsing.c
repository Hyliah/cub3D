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
	// ok so far -------------------------------------------------------------------------
	parse_file(cub, av[1]); // lecture complete et stock textures, couleur et map
	//printf("apres parse file\n");
	check_texture(cub); // verifie que c'est correct
	//printf("debug\n"); //---------------------------------------------------------------
	check_color(cub); // same
	check_map(cub); // invalid char, line, player puis wall (?) a supp si floodfill ? 
	// flood fill ici ? A la toute fin ( apres player ) 

}

void	parse_file(t_cub *cub, char *pathname )
{
	int		fd;
	char	*line;

	printf("DEBUG: open_cub_file\n"); // ---------------------------------------------------
	fd = open_cub_file(cub, pathname);
	printf("DEBUG: get_next_valid_line\n"); // ---------------------------------------------------
	line = get_next_valid_line(fd);
	while (line)
	{

		printf("DEBUG: new line -> '%s'\n", line); // ---------------------------------------------------
		if (!cub->map.map_start)
			process_config_line(cub, line);
		else
			process_map_line(cub, line);
		free(line);
		line = get_next_valid_line(fd);
	}
	close(fd);
	printf("DEBUG: finalize map\n"); // ---------------------------------------------------
	finalize_map_parsing(cub);
	printf("DEBUG: end of parse_file\n"); // ---------------------------------------------------
}

// ouvre le fihcier et renvoie le FD 
int	open_cub_file(t_cub *cub, char *pathname)
{
	int	fd;

	fd = open(pathname, O_RDONLY);
	if (fd < 0)
	{
		ft_error(ERR_FILE_NOT_FOUND);
		clean_exit_parsing(cub);
	}
	return (fd);
}

// va lire la prochaine line pas vide et supp le \n avec trim
char	*get_next_valid_line(int fd)
{
	char		*line;

	line = get_next_line(fd);
	while (line)
	{
		ft_strtrim_newline(line);
		if (!is_empty_line(line))
			return (line);
		free(line);
		line = get_next_line(fd);
	}
	return (NULL);
}
// Juste pour les lignes de config AVANT la map  ( texture et color)
void	process_config_line(t_cub *cub, char *line)
{
	if (is_map_line(line))
	{
		cub->map.map_start = 1;
		cub->map.map_tab = alloc_map_line(cub, cub->map.map_tab, &cub->map.height, line);
	}
	else if (is_texture_line(line))
		parse_texture_line(cub, line);
	else if (is_color_line(line))
		parse_color_line(cub, line);
	else
	{
		ft_error(ERR_MAP_INVALID);
		ft_putstr_fd("Invalid config line\n", 2);
		clean_exit_parsing(cub);
	}
}

//gere uniauement les ligens de map une fois qu'elle a commence
void	process_map_line(t_cub *cub, char *line)
{
	if (!is_map_line(line))
	{
		ft_error(ERR_MAP_INVALID);
		ft_putstr_fd("Element should not be after the map\n", 2);
		clean_exit_parsing(cub);
	}
	cub->map.map_tab = alloc_map_line(cub, cub->map.map_tab, &cub->map.height, line);
}

// verif qu'au moins une ligen a ete lue et calcul la largeur max 
void	finalize_map_parsing(t_cub *cub)
{
	if (cub->map.height == 0)
	{
		ft_error(ERR_MAP_INVALID);
		ft_putstr_fd("No map lines were found\n", 2);
		clean_exit_parsing(cub);
	}
	cub->map.width = get_map_width(cub->map.map_tab, cub->map.height);
}