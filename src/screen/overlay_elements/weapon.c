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

static int		change_frame_number(t_cub *cub);
static t_img	*change_frame(t_cub *cub, int actual);

t_img	*move_weapon(t_cub *cub)
{
	static int	actual = 1;
	static int	i = 0;

	if (cub->key.k_a || cub->key.k_s || cub->key.k_d || cub->key.k_w)
	{
		if (i == 3)
		{
			i = 0;
			actual = change_frame_number(cub);
		}
		i++;
	}
	return (change_frame(cub, actual));
}

static int	change_frame_number(t_cub *cub)
{
	int		actual;
	t_bool	is_up;

	actual = cub->weapons.s_nb;
	is_up = cub->weapons.up;
	if (actual < 5 && is_up == TRUE)
	{
		actual++;
		cub->weapons.s_nb = actual;
		if (actual == 5)
			cub->weapons.up = FALSE;
	}
	else
	{
		actual--;
		cub->weapons.s_nb = actual;
		if (actual == 1)
			cub->weapons.up = TRUE;
	}
	return (actual);
}

static t_img	*change_frame(t_cub *cub, int actual)
{
	if (actual == 1)
		return (&cub->weapons.img_w1);
	else if (actual == 2)
		return (&cub->weapons.img_w2);
	else if (actual == 3)
		return (&cub->weapons.img_w3);
	else if (actual == 4)
		return (&cub->weapons.img_w4);
	else
		return (&cub->weapons.img_w5);
}
