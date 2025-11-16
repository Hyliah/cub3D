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

static void	rotate_player(t_cub *cub, double angle);

int	mouse_press(int button, int x, int y, t_cub *cub)
{
	(void)y;
	if (button == 1) /* bouton gauche */
	{
		cub->mouse.pressed = TRUE;
		cub->mouse.last_x = x;
	}
	return (0);
}

int	mouse_release(int button, int x, int y, t_cub *cub)
{
	(void)x; (void)y;
	if (button == 1)
		cub->mouse.pressed = FALSE;
	return (0);
}

int	mouse_move(int x, int y, t_cub *cub)
{
	int		dx;
	double	angle;

	(void)y;
	if (!cub->mouse.pressed)
		return (0);
	dx = x - cub->mouse.last_x;
	cub->mouse.last_x = x;
	if (dx == 0)
		return (0);
	angle = dx * MOUSE_SENSITIVITY;
	rotate_player(cub, angle);
	return (0);
}

static void	rotate_player(t_cub *cub, double angle)
{
	double	old_dir_x;
	double	old_pl_x;

	old_dir_x = cub->player.dir_x;
	old_pl_x = cub->player.pl_x;
	cub->player.dir_x = old_dir_x * cos(angle) - cub->player.dir_y * sin(angle);
	cub->player.dir_y = old_dir_x * sin(angle) + cub->player.dir_y * cos(angle);
	cub->player.pl_x = old_pl_x * cos(angle) - cub->player.pl_y * sin(angle);
	cub->player.pl_y = old_pl_x * sin(angle) + cub->player.pl_y * cos(angle);
	cub->player.angle += angle;
}
