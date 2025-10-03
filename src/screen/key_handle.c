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

//static t_bool	safe_move(t_cub *cub, float new_x, float new_y);
//static void	mm_move_player(t_cub *cub, float new_x, float new_y, t_bool forward);

int	handle_key(int keycode, t_cub *cub)
{
	// //mettre des boucles while avec boolean pour avoir la possibilite de garderla touche enfoncee
	// while (keycode == KEY_A)
	// {
	// 	if (safe_move(cub, cub->player.pos_x - 1.1, cub->player.pos_y))
	// 		mm_move_player(cub, cub->player.pos_x - 0.1, cub->player.pos_y, FALSE);
	// }

	if (keycode == KEY_ESCAPE)
		clean_exit(cub);
	return (0);
}

// // si on met une porte peut etre mettre aussi une impossibilite d avancer si y a une porte ?
// // peut etre avec un boolean de door -> if door=FALSE on passse pas et inversement ?
// static t_bool	safe_move(t_cub *cub, float new_x, float new_y)
// {
// 	if (cub->map.map_tab[(int)new_y][(int)new_x] != '1')
// 		return (TRUE);
// 	return (FALSE);
// }

// si on a une option sans minimap jsute faut pas l afficher pcq on a besoin des derniere lignes whatsoever, ou mettre dans une autre fonction if I fancy it 
// static void	mm_move_player(t_cub *cub, float new_x, float new_y, t_bool forward)
// {
// 	float 	mini_x;
// 	float	mini_y;

// 	mini_x = (int)new_x * cub->mmap.mm_square;
// 	mini_y = (int)new_y * cub->mmap.mm_square;

// 	if (forward = TRUE)
// 	{
// 		//deplacer les pixel avec le ratio, a voir quoi comment 
// 	}
// 	else 

// 	cub->player.pos_x = new_x;
// 	cub->player.pos_y = new_y;
// }


// static void	move_player(t_cub *cub, int new_x, int new_y)
// {
// 	float 	pos_x;
// 	float	pos_y;

// 	pos_x = cub->player.pos_x;
// 	pos_y = cub->player.pos_y;

// 	if (cub->map.map_tab[pos_y][pos_x] == 'E')
// 		create_tile(&cub->graphic, 'E', pos_x, pos_y);
// 	else
// 		create_tile(&cub->graphic, '0', pos_x, pos_y);
// 	create_tile(&cub->graphic, 'P', new_x, new_y);
// 	create_tile(&cub->graphic, '0', pos_x, pos_y);
// 	create_tile(&cub->graphic, 'N', new_x, new_y);

// 	cub->player.pos_x = new_x;
// 	cub->player.pos_y = new_y;
// }


// int	handle_key(int keycode, t_cub *cub)
// {
// 	printf("%d\n", keycode);
// 	if (keycode == KEY_A)
// 		will_move(cub, cub->player.pos_x - 1, cub->player.pos_y);
// 	if (keycode == KEY_D)
// 		will_move(cub, cub->player.pos_x + 1, cub->player.pos_y);
// 	if (keycode == KEY_W)
// 		will_move(cub, cub->player.pos_x, cub->player.pos_y - 1);
// 	if (keycode == KEY_S)
// 		will_move(cub, cub->player.pos_x, cub->player.pos_y + 1);
// 	if (keycode == KEY_ESCAPE)
// 		clean_exit(cub);
// 	return (0);
// }







// void	will_move(t_mlx *mlx, int new_x, int new_y)
// {
// 	if (mlx->map.map_tab[new_y][new_x] != '1')
// 	{
// 		if (mlx->map.map_tab[new_y][new_x] == 'C')
// 		{
// 			mlx->map.map_tab[new_y][new_x] = '0';
// 			move_player(mlx, new_x, new_y);
// 			mlx->inputs.collected++;
// 			ft_printf("Num num num treats 🦴\n");
// 		}
// 		if (mlx->map.map_tab[new_y][new_x] == '0'
// 			|| mlx->map.map_tab[new_y][new_x] == 'P')
// 			move_player(mlx, new_x, new_y);
// 		if (mlx->map.map_tab[new_y][new_x] == 'E')
// 		{
// 			if (mlx->inputs.collected == mlx->inputs.check_c)
// 			{
// 				need_message();
// 				clean_exit(mlx);
// 			}
// 			else
// 				return (count_move(), ft_printf("Need more treats\n"),
// 					move_player(mlx, new_x, new_y));
// 		}
// 		count_move();
// 	}
// }


// int	handle_key(int keycode, t_mlx *mlx)
// {
// 	if (keycode == KEY_A || keycode == KEY_LEFTARROW)
// 		will_move(mlx, mlx->map.player.pos_x - 1, mlx->map.player.pos_y);
// 	if (keycode == KEY_D || keycode == KEY_RIGHTARROW)
// 		will_move(mlx, mlx->map.player.pos_x + 1, mlx->map.player.pos_y);
// 	if (keycode == KEY_W || keycode == KEY_UPARROW)
// 		will_move(mlx, mlx->map.player.pos_x, mlx->map.player.pos_y - 1);
// 	if (keycode == KEY_S || keycode == KEY_DOWNARROW)
// 		will_move(mlx, mlx->map.player.pos_x, mlx->map.player.pos_y + 1);
// 	if (keycode == KEY_ESCAPE)
// 		clean_exit(mlx);
// 	return (0);
// }


// void	will_move(t_mlx *mlx, int new_x, int new_y)
// {
// 	if (mlx->map.map_tab[new_y][new_x] != '1')
// 	{
// 		if (mlx->map.map_tab[new_y][new_x] == 'C')
// 		{
// 			mlx->map.map_tab[new_y][new_x] = '0';
// 			move_player(mlx, new_x, new_y);
// 			mlx->inputs.collected++;
// 			ft_printf("Num num num treats 🦴\n");
// 		}
// 		if (mlx->map.map_tab[new_y][new_x] == '0'
// 			|| mlx->map.map_tab[new_y][new_x] == 'P')
// 			move_player(mlx, new_x, new_y);
// 		if (mlx->map.map_tab[new_y][new_x] == 'E')
// 		{
// 			if (mlx->inputs.collected == mlx->inputs.check_c)
// 			{
// 				need_message();
// 				clean_exit(mlx);
// 			}
// 			else
// 				return (count_move(), ft_printf("Need more treats\n"),
// 					move_player(mlx, new_x, new_y));
// 		}
// 		count_move();
// 	}
// }

// void	move_player(t_mlx *mlx, int new_x, int new_y)
// {
// 	if (mlx->map.map_tab[mlx->map.player.pos_y][mlx->map.player.pos_x] == 'E')
// 		create_tile(&mlx->graphic, 'E', mlx->map.player.pos_x * 64,
// 			mlx->map.player.pos_y * 64);
// 	else
// 		create_tile(&mlx->graphic, '0', mlx->map.player.pos_x * 64,
// 			mlx->map.player.pos_y * 64);
// 	create_tile(&mlx->graphic, 'P', new_x * 64, new_y * 64);
// 	mlx->map.player.pos_x = new_x;
// 	mlx->map.player.pos_y = new_y;
// }












/* version so_long */


// static void	will_move(t_cub *cub, int new_x, int new_y);
// static void	move_player(t_cub *cub, int new_x, int new_y);

// int	handle_key(int keycode, t_cub *cub)
// {
// 	if (keycode == KEY_A)
// 		will_move(cub, cub->player.pos_x - 1, cub->player.pos_y);
// 	if (keycode == KEY_D)
// 		will_move(cub, cub->player.pos_x + 1, cub->player.pos_y);
// 	if (keycode == KEY_W)
// 		will_move(cub, cub->player.pos_x, cub->player.pos_y - 1);
// 	if (keycode == KEY_S)
// 		will_move(cub, cub->player.pos_x, cub->player.pos_y + 1);
// 	if (keycode == KEY_ESCAPE)
// 		clean_exit(cub);
// 	return (0);
// }

// /* si on finit par garder cette version mais je doute, il faut ajouter W E S */
// static void	will_move(t_cub *cub, int new_x, int new_y)
// {
// 	if (cub->map.map_tab[new_y][new_x] != '1')
// 	{
// 		if (cub->map.map_tab[new_y][new_x] == 'C')
// 		{
// 			cub->map.map_tab[new_y][new_x] = '0';
// 			move_player(cub, new_x, new_y);
// 		}
// 		if (cub->map.map_tab[new_y][new_x] == '0'
// 			|| cub->map.map_tab[new_y][new_x] == 'N')
// 			move_player(cub, new_x, new_y);
// 	}
// }

// /* si on finit par garder cette version mais je doute, il faut ajouter W E S */
// static void	move_player(t_cub *cub, int new_x, int new_y)
// {
// 	int pos_x;
// 	int	pos_y;

// 	pos_x = cub->player.pos_x;
// 	pos_y = cub->player.pos_y;

// 	create_tile(&cub->graphic, '0', pos_x, pos_y);
// 	create_tile(&cub->graphic, 'N', new_x, new_y);
	
// 	cub->player.pos_x = new_x;
// 	cub->player.pos_y = new_y;
// }
