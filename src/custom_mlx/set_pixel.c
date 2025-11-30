/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_pixel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlichten <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 02:09:31 by hlichten          #+#    #+#             */
/*   Updated: 2025/11/30 02:09:33 by hlichten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

/**
 * @brief Sets the color of a specific pixel in an image.
 *
 * @param img Pointer to the image structure.
 * @param x X coordinate of the pixel.
 * @param y Y coordinate of the pixel.
 * @param color The color to set (t_hex_c format).
 */
void	set_pixel(t_img *img, int x, int y, t_hex_c color)
{
	*(t_hex_c *)(img->addr_ptr + y * img->size_line
			+ x * (img->bpp / 8)) = color;
}
