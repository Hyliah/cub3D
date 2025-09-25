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

static void	will_move(t_cub *cub, int new_x, int new_y);
static void	move_player(t_cub *cub, int new_x, int new_y);

int	handle_key(int keycode, t_cub *cub)
{
	if (keycode == KEY_A)
		will_move(cub, cub->player.pos_x - 1, cub->player.pos_y);
	if (keycode == KEY_D)
		will_move(cub, cub->player.pos_x + 1, cub->player.pos_y);
	if (keycode == KEY_W)
		will_move(cub, cub->player.pos_x, cub->player.pos_y - 1);
	if (keycode == KEY_S)
		will_move(cub, cub->player.pos_x, cub->player.pos_y + 1);
	if (keycode == KEY_ESCAPE)
		clean_exit(cub);
	return (0);
}

static void	will_move(t_cub *cub, int new_x, int new_y)
{
	if (cub->map.map_tab[new_y][new_x] != '1')
	{
		if (cub->map.map_tab[new_y][new_x] == 'C')
		{
			cub->map.map_tab[new_y][new_x] = '0';
			move_player(cub, new_x, new_y);
		}
		if (cub->map.map_tab[new_y][new_x] == '0'
			|| cub->map.map_tab[new_y][new_x] == 'N')
			move_player(cub, new_x, new_y);
	}
}

static void	move_player(t_cub *cub, int new_x, int new_y)
{
	int pos_x;
	int	pos_y;

	pos_x = cub->player.pos_x;
	pos_y = cub->player.pos_y;

	create_tile(&cub->graphic, '0', pos_x, pos_y);
	create_tile(&cub->graphic, 'N', new_x, new_y);
	
	cub->player.pos_x = new_x;
	cub->player.pos_y = new_y;
}
