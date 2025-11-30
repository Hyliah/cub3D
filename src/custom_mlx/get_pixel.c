/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pixel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlichten <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 02:10:48 by hlichten          #+#    #+#             */
/*   Updated: 2025/11/30 02:10:51 by hlichten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

/**
 * @brief Retrieves the color of a specific pixel in an image.
 *
 * Returns 0 if the image is NULL, the address is invalid,
 * or the coordinates are out of bounds.
 *
 * @param img Pointer to the image structure.
 * @param x X coordinate of the pixel.
 * @param y Y coordinate of the pixel.
 * @return t_hex_c The color of the pixel at (x, y).
 */
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
