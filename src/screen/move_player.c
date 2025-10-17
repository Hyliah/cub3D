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
static void		mm_move_player(t_cub *cub, float new_x, float new_y);
static int		change_angle(int new_angle);

void	move_player(t_cub *cub)
{
	float	pos_x;
	float	pos_y;

	pos_x = cub->player.pos_x;
	pos_y = cub->player.pos_y;
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
			cub->player.angle = change_angle(cub->player.angle + 4);
		if (cub->key.k_ri)
			cub->player.angle = change_angle(cub->player.angle - 4);
		mm_move_player(cub, pos_x, pos_y);
	}
}

static void	move(t_cub *cub, float direction)
{
	float	angle;
	float	dir_x;
	float	dir_y;
	float	new_x;
	float	new_y;

	if (direction > 360)
		direction = direction - 360;
	angle = direction * M_PI / 180.0;

	dir_x = cos(angle);
	dir_y = -sin(angle);
	new_x = cub->player.pos_x + dir_x * 0.1f;
	new_y = cub->player.pos_y + dir_y * 0.1f;

	if (safe_move(cub, new_x, new_y))
	{
		cub->player.pos_x = new_x;
		cub->player.pos_y = new_y;
	}
}

// si porte ptetre mettre aussi une impossibilite d avancer si y a une porte ?
// ptetre avec un bool de door -> if door=FALSE on passse pas et inversement ?
static t_bool	safe_move(t_cub *cub, float new_x, float new_y)
{
	float	r;
	
	r = 0.2f;
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

//si on a une option sans minimap jsute faut pas l afficher 
// pcq on a besoin des derniere lignes whatsoever, 
//ou mettre dans une autre fonction if I fancy it 
static void	mm_move_player(t_cub *cub, float new_x, float new_y)
{
	(void)new_x;
	(void)new_y;
	mm_player_draw(cub, 0x0000000);
	// cub->player.pos_x = new_x;
	// cub->player.pos_y = new_y;
	mm_player_draw(cub, 0x622416);
	merge_screens(cub);
}


// void	move_player(t_cub *cub)
// {
// 	float	pos_x;
// 	float	pos_y;

// 	pos_x = cub->player.pos_x;
// 	pos_y = cub->player.pos_y;
// 	if (cub->game_on == TRUE)
// 	{
// 		if (cub->key.k_a && safe_move(cub, pos_x - 0.3, pos_y))
// 			pos_x = pos_x - 0.1;
// 		if (cub->key.k_d && safe_move(cub, pos_x + 0.3, pos_y))
// 			pos_x = pos_x + 0.1;
// 		if (cub->key.k_s && safe_move(cub, pos_x, pos_y + 0.3))
// 			pos_y = pos_y + 0.1;
// 		if (cub->key.k_w && safe_move(cub, pos_x, pos_y - 0.3))
// 			pos_y = pos_y - 0.1;
// 		if (cub->key.k_le)
// 			cub->player.angle = change_angle(cub->player.angle + 2);
// 		if (cub->key.k_ri)
// 			cub->player.angle = change_angle(cub->player.angle - 2);
// 		mm_move_player(cub, pos_x, pos_y);
// 	}
// }