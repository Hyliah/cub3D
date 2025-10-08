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

static void	init_struct_graphic(t_cub *cub);
static void	init_struct_map_settings(t_cub *cub);
static void	init_struct_player(t_cub *cub);

void	init_struct(t_cub *cub)
{
	cub->game_on = FALSE;
	init_struct_graphic(cub);
	init_struct_map_settings(cub);
	init_struct_player(cub);
}

static void	init_struct_map_settings(t_cub *cub)
{
	cub->map.height = 0;
	cub->map.width = 0;
	cub->map.map_tab = NULL;
	cub->setting.fd = -1;
	cub->setting.c_color = 0;
	cub->setting.f_color = 0;
	cub->setting.start_dir = 0;
}

static void	init_struct_player(t_cub *cub)
{
	cub->player.dir = 0;
	cub->player.dir_x = 0;
	cub->player.dir_y = 0;
	cub->player.new_time = 0;
	cub->player.old_time = 0;
	cub->player.pl_x = 0;
	cub->player.pl_y = 0;
	cub->player.pos_x = 0;
	cub->player.pos_y = 0;
	cub->key.k_a = FALSE;
	cub->key.k_s = FALSE;
	cub->key.k_d = FALSE;
	cub->key.k_w = FALSE;
	cub->key.k_up = FALSE;
	cub->key.k_do = FALSE;
	cub->key.k_le = FALSE;
	cub->key.k_ri = FALSE;
}

static void	init_struct_graphic(t_cub *cub)
{
	cub->graphic.s_height = 1080;
	cub->graphic.s_width = 1920;
	cub->graphic.img_e = 0;
	cub->graphic.img_n = 0;
	cub->graphic.img_s = 0;
	cub->graphic.img_w = 0;
	cub->graphic.mlx_ptr = NULL;
	cub->graphic.win_ptr = NULL;
	cub->graphic.img_screen.addr_ptr = NULL;
	cub->graphic.img_screen.bpp = 0;
	cub->graphic.img_screen.endian = 0;
	cub->graphic.img_screen.img_ptr = NULL;
	cub->graphic.img_screen.size_line = 0;
	cub->mmap.img_mmap.addr_ptr = NULL;
	cub->mmap.img_mmap.bpp = 0;
	cub->mmap.img_mmap.endian = 0;
	cub->mmap.img_mmap.img_ptr = NULL;
	cub->mmap.img_mmap.size_line = 0;
	cub->mmap.mm_show = TRUE;
	cub->oscreen.img_os = NULL;
	cub->oscreen.img_pe = NULL;
	cub->oscreen.img_si = NULL;
	cub->oscreen.img_olp = NULL;
	cub->oscreen.img_ols = NULL;
	cub->oscreen.is_sirius = TRUE;
}

// #ifdef __linux__

// static void	init_struct_graphic(t_cub *cub)
// {

// 	cub->graphic.s_height = 1080;
// 	cub->graphic.s_width = 1920;
// 	cub->graphic.img_e = 0;
// 	cub->graphic.img_n = 0;
// 	cub->graphic.img_s = 0;
// 	cub->graphic.img_w = 0;
// 	cub->graphic.mlx_ptr = NULL;
// 	cub->graphic.win_ptr = NULL;
// 	cub->graphic.screen.addr_ptr = NULL;
// 	cub->graphic.screen.bpp = 0;
// 	cub->graphic.screen.endian = 0;
// 	cub->graphic.screen.img_ptr = NULL;
// 	cub->graphic.screen.size_line = 0;
// 	cub->mmap.minimap.addr_ptr = NULL;
// 	cub->mmap.minimap.bpp = 0;
// 	cub->mmap.minimap.endian = 0;
// 	cub->mmap.minimap.img_ptr = NULL;
// 	cub->mmap.minimap.size_line = 0;
// }

// #else

// static void	init_struct_graphic(t_cub *cub)
// {
// 	cub->graphic.s_height = 540;
// 	cub->graphic.s_width = 960;
// 	cub->graphic.img_e = 0;
// 	cub->graphic.img_n = 0;
// 	cub->graphic.img_s = 0;
// 	cub->graphic.img_w = 0;
// 	cub->graphic.mlx_ptr = NULL;
// 	cub->graphic.win_ptr = NULL;
// 	cub->graphic.screen.addr_ptr = NULL;
// 	cub->graphic.screen.bpp = 0;
// 	cub->graphic.screen.endian = 0;
// 	cub->graphic.screen.img_ptr = NULL;
// 	cub->graphic.screen.size_line = 0;
// 	cub->mmap.minimap.addr_ptr = NULL;
// 	cub->mmap.minimap.bpp = 0;
// 	cub->mmap.minimap.endian = 0;
// 	cub->mmap.minimap.img_ptr = NULL;
// 	cub->mmap.minimap.size_line = 0;
// }

// #endif