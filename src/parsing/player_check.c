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

void	check_player(t_cub *cub)
{
	int		x;
	int		y;
	char	c;

	y = 0;
	while (cub->map.map_tab[y])
	{
		x = 0;
		while (cub->map.map_tab[y][x])
		{
			c = cub->map.map_tab[y][x];
			if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
			{
				check_too_many_players(cub);
				init_player(cub, x, y, c);
				cub->map.map_tab[y][x] = '0';
			}
			x++;
		}
		y++;
	}
	check_no_player(cub);
}

void	check_too_many_players(t_cub *cub)
{
	if (cub->player.has_player == 1)
	{
		ft_error(ERR_PLAYER);
		ft_putstr_fd("Too many players on the map\n", 2);
		clean_exit_parsing(cub);
	}
}

void	check_no_player(t_cub *cub)
{
	if (cub->player.has_player == 0)
	{
		ft_error(ERR_PLAYER);
		ft_putstr_fd("No player on the map\n", 2);
		clean_exit_parsing(cub);
	}
}

void	init_player(t_cub *cub, int x, int y, char dir)
{
	cub->player.has_player = 1;
	cub->player.pos_x = x + 0.5;
	cub->player.pos_y = y + 0.5;
	if (dir == 'N')
		cub->player.dir = NORTH;
	else if (dir == 'S')
		cub->player.dir = SOUTH;
	else if (dir == 'E')
		cub->player.dir = EAST;
	else if (dir == 'W')
		cub->player.dir = WEST;
	else
	{
		ft_error(ERR_PLAYER);
		ft_putstr_fd("Invalid player direction\n", 2);
		clean_exit_parsing(cub);
	}
	init_player_angle(&cub->player);
}

void	init_player_angle(t_player *player)
{
	if (player->dir == NORTH)
		player->angle = 90.0;
	if (player->dir == SOUTH)
		player->angle = 270.0;
	if (player->dir == EAST)
		player->angle = 0.0;
	if (player->dir == WEST)
		player->angle = 180.0;
}
