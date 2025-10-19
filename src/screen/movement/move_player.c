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

static t_bool	safe_move(t_cub *cub, float new_x, float new_y);
static void		move(t_cub *cub, float direction);
static int		change_angle(int new_angle);

void	move_player(t_cub *cub)
{
	puts("hello");
	if (cub->game_on == TRUE)
	{
		if (cub->key.k_a)
			move(cub, cub->player.angle + 90.0f);
		if (cub->key.k_d)
			move(cub, cub->player.angle + 270.0f);
		if (cub->key.k_s)
			move(cub, cub->player.angle + 180.0f);
		if (cub->key.k_w)
			move(cub, cub->player.angle);
		if (cub->key.k_le)
			cub->player.angle = change_angle(cub->player.angle + 2);
		if (cub->key.k_ri)
			cub->player.angle = change_angle(cub->player.angle - 2);
		merge_screens(cub);
	}
}

static void	move(t_cub *cub, float direction)
{
	double 	speed;
	float	angle;
	float	new_x;
	float	new_y;
	
	//frame_time(cub);
	// faire les changements de speed comme on veut bien
	// if (cub->key.k_s)
	// 	speed = cub->fps.frame_time * 5.0;
	// else if (cub->key.k_sh)
	// 	speed = cub->fps.frame_time * 5.0;
	// else
	// 	speed = cub->fps.frame_time * 2.0;
	speed = 0.5;
	debug_log("como esta");
	printf("speed = %d\n", speed);
	puts("3");
	if (direction > 360)
		direction = direction - 360;
	angle = direction * M_PI / 180.0;
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

// si porte ptetre mettre aussi une impossibilite d avancer si y a une porte ?
// ptetre avec un bool de door -> if door=FALSE on passse pas et inversement ?
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
	return (TRUE);
}

static int	change_angle(int new_angle)
{
	if (new_angle > 360)
		return (0);
	else if (new_angle < 0)
		return (360);
	else
		return (new_angle);
}
