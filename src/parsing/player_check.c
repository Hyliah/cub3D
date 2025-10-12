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

// faire comme so_long ? no player, too many player ?? 
void	check_player(t_cub *cub)
{
	int		x;
	int		y;
	char	c;

	y = 0;
	while ( cub->map.map_tab[y])
	{
		x = 0;
		while ( cub->map.map_tab[y][x])
		{
			c = cub->map.map_tab[y][x];
			if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
			{
				if ( cub->player.has_player == 1) // check si deja un joueur = erreur 
				{
					ft_error(ERR_PLAYER);
					// too many player on the map \n
					clean_exit_parsing;
				}
				init_player(cub, x, y, c);
				cub->map.map_tab[y][x] = '0';	// remplacer le joueur par le sol dans la map
			}
			x++;
		}
		y++;
	}
	check_no_player(cub);
}

void	check_no_player(t_cub *cub)
{
	if (cub->player.has_player == 0)
	{
		ft_error(ERR_PLAYER);
		// no player on the map \n
		clean_exit_parsing(cub);
	}
}

void	init_player(t_cub *cub, int x, int y, char dir)
{
	cub->player.has_player = 1;
	cub->player.pos_x = x + 0.5; // position a 0.5 ? ou autre mesure ? 
	cub->player.pos_y = y + 0.5;
	
	// definir direction de depart pour la struct player dir 
	if ( dir == 'N')
		cub->player.dir = NORTH;
	else if ( dir == 'S')
		cub->player.dir = SOUTH;
	else if ( dir == 'E')
		cub->player.dir = EAST;
	else if ( dir == 'W')
		cub->player.dir = WEST;
}

