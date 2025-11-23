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

static void	handle_key_open(t_cub *cub);
static void	change_key_status(t_cub *cub, int keycode, t_bool is_pressed);

int	key_press(int key, t_cub *cub)
{
	change_key_status(cub, key, TRUE);
	if (key == KEY_M)
	{
		if (cub->mmap.mm_show == TRUE)
			cub->mmap.mm_show = FALSE;
		else
			cub->mmap.mm_show = TRUE;
	}
	if (key == KEY_O)
		handle_key_open(cub);
	if (key == KEY_ESCAPE)
		clean_exit(cub);
	opening_screen_handle(cub, key);
	return (0);
}

int	key_release(int keycode, t_cub *cub)
{
	change_key_status(cub, keycode, FALSE);
	return (0);
}

static void	change_key_status(t_cub *cub, int keycode, t_bool is_pressed)
{
	if (keycode == KEY_A)
		cub->key.k_a = is_pressed;
	if (keycode == KEY_S)
		cub->key.k_s = is_pressed;
	if (keycode == KEY_D)
		cub->key.k_d = is_pressed;
	if (keycode == KEY_W)
		cub->key.k_w = is_pressed;
	if (keycode == KEY_LEFTARROW)
		cub->key.k_le = is_pressed;
	if (keycode == KEY_RIGHTARROW)
		cub->key.k_ri = is_pressed;
	if (keycode == KEY_UPARROW)
		cub->key.k_up = is_pressed;
	if (keycode == KEY_DOWNARROW)
		cub->key.k_do = is_pressed;
	if (keycode == KEY_SHIFT)
		cub->key.k_sh = is_pressed;
}

static void	handle_key_open(t_cub *cub)
{
	int	x;
	int	y;

	if (cub->map.is_door_open == TRUE)
	{
		x = (int)cub->player.pos_x;
		y = (int)cub->player.pos_y;
		if (cub->map.map_tab[y][x] == 'D')
		{
			cub->map.is_door_open = TRUE;
		}
		else
			cub->map.is_door_open = FALSE;
	}
	else
		cub->map.is_door_open = TRUE;
}
