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

static void	init_t_img(t_img *img);
static void	init_struct_graphic(t_cub *cub);
static void	init_struct_map_settings(t_cub *cub);
static void	init_struct_player(t_cub *cub);

void	init_struct(t_cub *cub)
{
	cub->game_on = FALSE;
	init_struct_graphic(cub);
	init_struct_map_settings(cub);
	init_struct_player(cub);
	frame_time(cub);
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
	cub->player.dir_x = 0;
	cub->player.dir_y = 0;
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
	cub->key.k_sh = FALSE;
}

#ifdef __linux__

static void	init_struct_graphic(t_cub *cub)
{
	cub->graphic.s_height = 1080;
	cub->graphic.s_width = 1920;
	cub->graphic.mlx_ptr = NULL;
	cub->graphic.win_ptr = NULL;
	cub->mmap.mm_show = TRUE;
	cub->oscreen.img_os = NULL;
	cub->oscreen.img_pe = NULL;
	cub->oscreen.img_si = NULL;
	cub->oscreen.is_sirius = TRUE;
	cub->weapons.s_nb = 1;
	cub->weapons.up = TRUE;
	init_t_img(&cub->weapons.img_w1);
	init_t_img(&cub->weapons.img_w2);
	init_t_img(&cub->weapons.img_w3);
	init_t_img(&cub->weapons.img_w4);
	init_t_img(&cub->weapons.img_w5);
	init_t_img(&cub->oscreen.img_olay);
	init_t_img(&cub->graphic.img_screen);
	init_t_img(&cub->mmap.img_mmap);
	init_t_img(&cub->mmap.img_player);
}

#else

static void	init_struct_graphic(t_cub *cub)
{
	cub->graphic.s_height = 540;
	cub->graphic.s_width = 960;
	cub->graphic.mlx_ptr = NULL;
	cub->graphic.win_ptr = NULL;
	cub->mmap.mm_show = TRUE;
	cub->oscreen.img_os = NULL;
	cub->oscreen.img_pe = NULL;
	cub->oscreen.img_si = NULL;
	cub->oscreen.is_sirius = TRUE;
	cub->weapons.s_nb = 1;
	cub->weapons.up = TRUE;
	init_t_img(&cub->weapons.img_w1);
	init_t_img(&cub->weapons.img_w2);
	init_t_img(&cub->weapons.img_w3);
	init_t_img(&cub->weapons.img_w4);
	init_t_img(&cub->weapons.img_w5);
	init_t_img(&cub->oscreen.img_olay);
	init_t_img(&cub->graphic.img_screen);
	init_t_img(&cub->mmap.img_mmap);
	init_t_img(&cub->mmap.img_player);
	init_t_img(&cub->graphic.img_e);
	init_t_img(&cub->graphic.img_s);
	init_t_img(&cub->graphic.img_n);
	init_t_img(&cub->graphic.img_w);
}

#endif

static void	init_t_img(t_img *img)
{
	img->addr_ptr = NULL;
	img->bpp = 0;
	img->endian = 0;
	img->img_ptr = NULL;
	img->size_line = 0;
}
