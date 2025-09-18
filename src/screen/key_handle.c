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

int	handle_key(int keycode, t_cub *cub)
{
	// if (keycode == KEY_A)
	// 	will_move(mlx, mlx->map.player.pos_x - 1, mlx->map.player.pos_y);
	// if (keycode == KEY_D)
	// 	will_move(mlx, mlx->map.player.pos_x + 1, mlx->map.player.pos_y);
	// if (keycode == KEY_W)
	// 	will_move(mlx, mlx->map.player.pos_x, mlx->map.player.pos_y - 1);
	// if (keycode == KEY_S)
	// 	will_move(mlx, mlx->map.player.pos_x, mlx->map.player.pos_y + 1);
	if (keycode == KEY_ESCAPE)
		clean_exit(cub);
	return (0);
}
