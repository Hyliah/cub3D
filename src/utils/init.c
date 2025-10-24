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

static void	init_setting_map_fps(t_cub *cub);
static void	init_player_oscreen(t_cub *cub);
static void	init_t_imgs(t_cub *cub);
static void	init_t_img(t_img *img);

#ifdef __linux__

void	init_struct(t_cub *cub)
{
	cub->graphic.s_height = 1080;
	cub->graphic.s_width = 1920;
	cub->setting.fd = -1;
	cub->mmap.mm_show = TRUE;
	cub->oscreen.is_sirius = TRUE;
	cub->weapons.s_nb = 1;
	cub->weapons.up = TRUE;
	cub->game_on = FALSE;
	init_setting_map_fps(cub);
	init_player_oscreen(cub);
	init_t_imgs(cub);
	frame_time(cub);
}

#else

void	init_struct(t_cub *cub)
{
	cub->graphic.s_height = 540;
	cub->graphic.s_width = 960;
	cub->setting.fd = -1;
	cub->mmap.mm_show = TRUE;
	cub->oscreen.is_sirius = TRUE;
	cub->weapons.s_nb = 1;
	cub->weapons.up = TRUE;
	cub->game_on = FALSE;
	init_setting_map_fps(cub);
	init_player_oscreen(cub);
	init_t_imgs(cub);
	frame_time(cub);
}

#endif

static void	init_setting_map_fps(t_cub *cub)
{
	cub->fps.frame_time = 0;
	cub->fps.old_time = 0;
	cub->fps.start_time = 0;
	cub->graphic.mlx_ptr = NULL;
	cub->graphic.win_ptr = NULL;
	cub->map.width = 0;
	cub->map.height = 0;
	cub->map.map_tab = NULL;
	cub->mmap.mm_hei = 0;
	cub->mmap.mm_sqr = 0;
	cub->mmap.mm_wid = 0;
	cub->setting.c_color = 0;
	cub->setting.f_color = 0;
	cub->setting.start_dir = 0;
	cub->tex.draw_end = 0;
	cub->tex.draw_start = 0;
	cub->tex.step = 0;
	cub->tex.tex_pos = 0;
	cub->tex.tex_x = 0;
	cub->tex.tex_y = 0;
	cub->tex.wall_x = 0;
}

static void	init_t_imgs(t_cub *cub)
{
	init_t_img(&cub->weapons.img_w1);
	init_t_img(&cub->weapons.img_w2);
	init_t_img(&cub->weapons.img_w3);
	init_t_img(&cub->weapons.img_w4);
	init_t_img(&cub->weapons.img_w5);
	init_t_img(&cub->oscreen.img_olay);
	init_t_img(&cub->graphic.img_screen);
	init_t_img(&cub->graphic.img_e);
	init_t_img(&cub->graphic.img_s);
	init_t_img(&cub->graphic.img_w);
	init_t_img(&cub->graphic.img_n);
	init_t_img(&cub->mmap.img_mmap);
	init_t_img(&cub->mmap.img_player);
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

static void	init_player_oscreen(t_cub *cub)
{
	cub->player.angle = 0;
	cub->player.cam_x = 0;
	cub->player.cam_y = 0;
	cub->player.delta_dist_x = 0;
	cub->player.delta_dist_y = 0;
	cub->player.dir_x = 0;
	cub->player.dir_y = 0;
	cub->player.line_height = 0;
	cub->player.map_x = 0;
	cub->player.map_y = 0;
	cub->player.perp_wall_dist = 0;
	cub->player.pl_x = 0;
	cub->player.pl_y = 0;
	cub->player.pos_x = 0;
	cub->player.pos_y = 0;
	cub->player.ray_dir_x = 0;
	cub->player.ray_dir_y = 0;
	cub->player.side_dist_x = 0;
	cub->player.side_dist_y = 0;
	cub->player.step_x = 0;
	cub->player.step_y = 0;
	cub->oscreen.img_os = NULL;
	cub->oscreen.img_pe = NULL;
	cub->oscreen.img_si = NULL;
}

static void	init_t_img(t_img *img)
{
	img->addr_ptr = NULL;
	img->bpp = 0;
	img->endian = 0;
	img->img_ptr = NULL;
	img->size_line = 0;
}
