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

static double	cal_speed(t_cub *cub);
static t_bool	safe_move(t_cub *cub, float new_x, float new_y);
static void		move(t_cub *cub, float direction);
static void		change_angle_merge(t_cub *cub);

void	move_player(t_cub *cub)
{
	if (cub->game_on == TRUE)
	{
		if ((cub->key.k_a && cub->key.k_d) || (cub->key.k_s && cub->key.k_w))
			change_angle_merge(cub);
		else
		{
			if (cub->key.k_a && cub->key.k_w)
				move(cub, cub->player.angle + 45.0f);
			else if (cub->key.k_d && cub->key.k_w)
				move(cub, cub->player.angle + 315.0f);
			else if (cub->key.k_d && cub->key.k_s)
				move(cub, cub->player.angle + 225.0f);
			else if (cub->key.k_a && cub->key.k_s)
				move(cub, cub->player.angle + 135.0f);
			else if (cub->key.k_a)
				move(cub, cub->player.angle + 90.0f);
			else if (cub->key.k_d)
				move(cub, cub->player.angle + 270.0f);
			else if (cub->key.k_s)
				move(cub, cub->player.angle + 180.0f);
			else if (cub->key.k_w)
				move(cub, cub->player.angle);
			change_angle_merge(cub);
		}
	}
}

static void	change_angle_merge(t_cub *cub)
{
	double	old_angle;
	double	new_angle;

	if (cub->key.k_le && cub->key.k_ri)
		merge_screens(cub);
	else
	{
		old_angle = cub->player.angle;
		if (cub->key.k_le)
			new_angle = old_angle + 4;
		else if (cub->key.k_ri)
			new_angle = old_angle - 4;
		else
			new_angle = old_angle;
		if (new_angle > 360)
			new_angle = 0;
		else if (new_angle < 0)
			new_angle = 360;
		cub->player.angle = new_angle;
		merge_screens(cub);
	}
}

static void	move(t_cub *cub, float direction)
{
	double	speed;
	float	angle;
	float	new_x;
	float	new_y;

	if (direction > 360)
		direction = direction - 360;
	angle = direction * M_PI / 180.0;
	speed = cal_speed(cub);
	new_x = cub->player.pos_x + (cos(angle)) * speed;
	new_y = cub->player.pos_y + (-sin(angle)) * speed;
	if (safe_move(cub, new_x, new_y))
	{
		mm_player_draw(cub, 0x0000000);
		cub->player.pos_x = new_x;
		cub->player.pos_y = new_y;
		mm_player_draw(cub, 0x622416);
	}
}

static double	cal_speed(t_cub *cub)
{
	double	speed;

	frame_time(cub);
	if (cub->key.k_sh && cub->key.k_w)
	{
		speed = cub->fps.frame_time * 4.0;
	}
	else if (cub->key.k_s)
		speed = cub->fps.frame_time * 0.75;
	else
		speed = cub->fps.frame_time * 1.5;
	if (speed < 0.1)
		return (speed);
	else
		return (0.15);
}

static t_bool	safe_move(t_cub *cub, float new_x, float new_y)
{
	float	r;

	r = 0.05f;
	if (cub->map.map_tab[(int)(new_y)][(int)(new_x)] == '1'
		|| cub->map.map_tab[(int)(new_y + r)][(int)(new_x)] == '1'
		|| cub->map.map_tab[(int)(new_y - r)][(int)(new_x)] == '1'
		|| cub->map.map_tab[(int)(new_y)][(int)(new_x + r)] == '1'
		|| cub->map.map_tab[(int)(new_y)][(int)(new_x - r)] == '1')
		return (FALSE);
	if (cub->map.is_door_open == FALSE)
	{
		if (cub->map.map_tab[(int)(new_y)][(int)(new_x)] == 'D'
			|| cub->map.map_tab[(int)(new_y + r)][(int)(new_x)] == 'D'
			|| cub->map.map_tab[(int)(new_y - r)][(int)(new_x)] == 'D'
			|| cub->map.map_tab[(int)(new_y)][(int)(new_x + r)] == 'D'
			|| cub->map.map_tab[(int)(new_y)][(int)(new_x - r)] == 'D')
			return (FALSE);
	}
	return (TRUE);
}
