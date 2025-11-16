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
	if (button == 1)
	{
		cub->mouse.pressed = TRUE;
		cub->mouse.last_x = x;
	}
	return (0);
}

int	mouse_release(int button, int x, int y, t_cub *cub)
{
	(void)x;
	(void)y;
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
	angle = dx * 0.03;
	rotate_player(cub, angle);
	return (0);
}

static void	rotate_player(t_cub *cub, double angle)
{
	double	old_angle;
	double	new_angle;

	old_angle = cub->player.angle;
	new_angle = old_angle + (angle * 3);
	cub->player.angle = new_angle;
}
