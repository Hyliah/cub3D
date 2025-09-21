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

#ifdef __linux__

// Linux → vrai buffer ML
void	pixel_put(t_graphic *graph, int x, int y, int color)
{
	char	*dst;

	dst = graph->addr + (y * graph->size_line + x * (graph->bpp / 8));
	*(unsigned int *)dst = color;
}

#else

// macOS → fallback : on dessine directement dans la fenêtre
void	pixel_put(t_graphic *g, int x, int y, int color)
{
	if (x < 0 || x >= g->s_width || y < 0 || y >= g->s_height)
		return;
	g->buffer[y * g->s_width + x] = color;
}

#endif
