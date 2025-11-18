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

int	game_loop(t_cub *cub);

int	main(int ac, char **av)
{
	t_cub	cub;

	init_struct(&cub);
	parsing(&cub, ac, av);
	if (create_window(&cub))
		return (1);
	mlx_hook(cub.graphic.win_ptr, KEY_PRESS, KEY_PRESS_MASK, key_press, &cub);
	mlx_hook(cub.graphic.win_ptr, KEY_RELEASE, KEY_RELEASE_MASK,
		key_release, &cub);
	mlx_hook(cub.graphic.win_ptr, BUTTON_PRESS, (1L << 2), mouse_press, &cub);
	mlx_hook(cub.graphic.win_ptr, MOTION_NOTIFY, (1L << 6), mouse_move, &cub);
	mlx_hook(cub.graphic.win_ptr, BUTTON_RELEASE, (1L << 3),
		mouse_release, &cub);
	mlx_loop_hook(cub.graphic.mlx_ptr, game_loop, &cub);
	mlx_loop(cub.graphic.mlx_ptr);
	return (0);
}

int	game_loop(t_cub *cub)
{
	if (cub->game_on)
		limit_fps(cub);
	move_player(cub);
	return (0);
}
