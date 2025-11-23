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

t_hex_c	get_pixel(t_img *img, int x, int y)
{
	char	*pixel;

	if (!img || !img->addr_ptr)
		return (0);
	if (x < 0 || x >= img->width)
		return (0);
	if (y < 0 || y >= img->height)
		return (0);
	pixel = img->addr_ptr
		+ y * img->size_line
		+ x * (img->bpp / 8);
	return (*(t_hex_c *)pixel);
}
