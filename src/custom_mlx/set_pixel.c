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

// index = (y * size_line) + ( x * (bpp / 8))
// deplacement de bpp / 8

// 0xFFFFFF = rbg 255 255 255

void	set_pixel(t_img *img, int x, int y, t_hex_c color)
{
	*(t_hex_c *)(img->addr_ptr + y * img->size_line
			+ x * (img->bpp / 8)) = color;
}
