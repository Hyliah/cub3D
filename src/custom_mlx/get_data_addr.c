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
/*
  Remplit tes variables bpp, size_line et endian avec les info de l’image.
  Donne un pointeur vers le début du buffer pour dessiner pixel par pixel.

  edian - > souvent = 0 -> indique si les octets d’un pixel sont stockés 
  du moins significatif au plus significatif (little: 0) ou l’inverse (big: 1)
*/

#ifdef __linux__

// Linux → vrai buffer MLX
char	*get_data_addr(t_graphic *g, int *bpp, int *size_line, int *endian)
{
	if (!g || !bpp || !size_line || !endian)
		return (NULL);
	*bpp = g->bpp;
	*size_line = g->size_line;
	*endian = g->endian;
	return (g->addr);
}

#else

// macOS → fallback : on dessine directement dans la fenêtre
char	*data_addr(t_graphic *g, int *bpp, int *size_line, int *endian)
{
	(void)g;
	*bpp = 32;
	*size_line = g->s_width * 4;
	*endian = 0;
	return (NULL); // pas de vrai buffer accessible
}

#endif