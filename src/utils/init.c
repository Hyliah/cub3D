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
}

#ifdef __APPLE__

static void	init_struct_graphic(t_cub *cub)
{
	cub->graphic.s_height = 540;
	cub->graphic.s_width = 960;
	cub->graphic.mm_max_height = 135;
	cub->graphic.mm_max_width = 234;
	cub->graphic.img_e = 0;
	cub->graphic.img_n = 0;
	cub->graphic.img_s = 0;
	cub->graphic.img_w = 0;
	cub->graphic.mlx_ptr = NULL;
	cub->graphic.addr = NULL;
	cub->graphic.bpp = 32;
	cub->graphic.endian = 0;
	cub->graphic.img = NULL;
	cub->graphic.size_line = 1920 * 4; //a voir 
}
#elif defined(__linux__)

static void	init_struct_graphic(t_cub *cub)
{
	cub->graphic.s_height = 1080;
	cub->graphic.s_width = 1920;
	cub->graphic.maxi_mm = FALSE;
	cub->graphic.img_e = 0;
	cub->graphic.img_n = 0;
	cub->graphic.img_s = 0;
	cub->graphic.img_w = 0;
	cub->graphic.mlx_ptr = NULL;
	cub->graphic.addr = NULL;
	cub->graphic.bpp = 32;
	cub->graphic.endian = 0;
	cub->graphic.img = NULL;
	cub->graphic.size_line = 1920 * 4; //a voir 
}
#endif