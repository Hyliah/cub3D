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

static void	init_wall(t_cub *cub, t_img *img, char *xpm);

void	init_walls(t_cub *cub)
{
	init_wall(cub, &cub->graphic.img_e, WTE);
	init_wall(cub, &cub->graphic.img_s, WTS);
	init_wall(cub, &cub->graphic.img_w, WTW);
	init_wall(cub, &cub->graphic.img_n, WTN);
}

static void	init_wall(t_cub *cub, t_img *img, char *xpm)
{
	int	x;
	int	y;

	x = 1024;
	y = 1024;
	img->img_ptr = mlx_xpm_file_to_image(cub->graphic.mlx_ptr, xpm, &x, &y);
	// if (!img->img_ptr)
	// 	infructuous_smth;
	img->addr_ptr = mlx_get_data_addr(img->img_ptr, &img->bpp, &img->size_line,
			&img->endian);
	img->width = x;
	img->height = y;

	//maybe here change the way of xy for a more simple raycastng
}

void	texture_cal(t_cub *cub, int x, int y, int side)
{
	int		text_num;
	int		text_x;
	float	wall_x;
	float	step;
	float	tex_pos;

	text_num = cub->map.map_tab[x][y] - 1;
	if (side == 0)
		wall_x = cub->player.pos_y + cub->player.perp_wall_dist * cub->player.ray_dir_y;
	else
		wall_x = cub->player.pos_x + cub->player.perp_wall_dist * cub->player.ray_dir_x;
	
	// floor arrondi a l x.x le plus proche
	wall_x -= floor((double)wall_x);
	text_x = (int)wall_x * 1024;
	if ((side == 0 && cub->player.ray_dir_x > 0) || (side == 1 && cub->player.ray_dir_y < 0))
		text_x = 1024 - text_x - 1;

	step = 1.0f * 1024 / cub->player.line_height;
	
}
/*


			//texturing calculations
			int texNum = worldMap[mapX][mapY] - 1; //1 subtracted from it so that texture 0 can be used!

			//calculate value of wallX
			double wallX; //where exactly the wall was hit
			if (side == 0) wallX = posY + perpWallDist * rayDirY;
			else           wallX = posX + perpWallDist * rayDirX;
			wallX -= floor((wallX));

			//x coordinate on the texture
			int texX = int(wallX * double(texWidth));
			if(side == 0 && rayDirX > 0) texX = texWidth - texX - 1;
			if(side == 1 && rayDirY < 0) texX = texWidth - texX - 1;




		
				// How much to increase the texture coordinate per screen pixel
			double step = 1.0 * texHeight / lineHeight;
			// Starting texture coordinate
			double texPos = (drawStart - h / 2 + lineHeight / 2) * step;
			for(int y = drawStart; y<drawEnd; y++)
			{
				// Cast the texture coordinate to integer, and mask with (texHeight - 1) in case of overflow
				int texY = (int)texPos & (texHeight - 1);
				texPos += step;
				Uint32 color = texture[texNum][texHeight * texY + texX];
				//make color darker for y-sides: R, G and B byte each divided through two with a "shift" and an "and"
				if(side == 1) color = (color >> 1) & 8355711;
				buffer[y][x] = color;
			}
		}
*/