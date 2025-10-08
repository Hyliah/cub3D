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
static void		mm_move_player(t_cub *cub, float new_x, float new_y);

void	move_player(t_cub *cub)
{
	float	pos_x;
	float	pos_y;

	pos_x = cub->player.pos_x;
	pos_y = cub->player.pos_y;
	if (cub->key.k_a && safe_move(cub, pos_x - 0.3, pos_y))
		pos_x = pos_x - 0.1;
	if (cub->key.k_d && safe_move(cub, pos_x + 0.3, pos_y))
		pos_x = pos_x + 0.1;
	if (cub->key.k_s && safe_move(cub, pos_x, pos_y + 0.3))
		pos_y = pos_y + 0.1;
	if (cub->key.k_w && safe_move(cub, pos_x, pos_y - 0.3))
		pos_y = pos_y - 0.1;
	/* faire les changements avec la plane de vision*/
	// if (keycode == KEY_LEFTARROW)
	// 	pos_x = pos_x - 0.1;
	// if (keycode == KEY_RIGHTARROW)
	// 	pos_x = pos_x + 0.1;
	mm_move_player(cub, pos_x, pos_y);
}

// si porte ptetre mettre aussi une impossibilite d avancer si y a une porte ?
// ptetre avec un bool de door -> if door=FALSE on passse pas et inversement ?
static t_bool	safe_move(t_cub *cub, float new_x, float new_y)
{
	if (cub->map.map_tab[(int)new_y][(int)new_x] != '1')
		return (TRUE);
	return (FALSE);
}

//si on a une option sans minimap jsute faut pas l afficher 
// pcq on a besoin des derniere lignes whatsoever, 
//ou mettre dans une autre fonction if I fancy it 
static void	mm_move_player(t_cub *cub, float new_x, float new_y)
{
	mm_player_draw(cub, 0x0000000);
	cub->player.pos_x = new_x;
	cub->player.pos_y = new_y;
	mm_player_draw(cub, 0x622416);
	merge_screens(cub);
}
