/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcollas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 15:05:11 by rcollas           #+#    #+#             */
/*   Updated: 2021/08/24 18:07:01 by rcollas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fract_ol.h"

void	window_adapt(t_pos *pos)
{
	pos->width_adpt = 0;
	pos->height_adpt = 0;
	if (HEIGHT > pos->zoom * (pos->y2 - pos->y1))
		pos->height_adpt = (HEIGHT - pos->zoom * (pos->y2 - pos->y1)) / 2;
	else if (HEIGHT < pos->zoom * (pos->y2 - pos->y1))
		pos->height_adpt = (pos->zoom * (pos->y2 - pos->y1) - HEIGHT) / 2;
	if (WIDTH > pos->zoom * (pos->x2 - pos->x1))
		pos->width_adpt = (WIDTH - pos->zoom * (pos->x2 - pos->x1)) / 2;
	else if (WIDTH < pos->zoom * (pos->x2 - pos->x1))
		pos->width_adpt = (pos->zoom * (pos->x2 - pos->x1) - WIDTH) / 2;
}

int	encode_rgb(UINT8_T red, UINT8_T green, UINT8_T blue)
{
	return (red << 16 | green << 8 | blue);
}

void	get_image(t_pos *pos)
{
	pos->delta_x = (pos->x2 - pos->x1) * pos->zoom;
	pos->delta_y = (pos->y2 - pos->y1) * pos->zoom;
}

void	img_pxl_put(t_img *img, int x, int y, int color)
{
	char	*pixel;

	pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(int *)pixel = color;
}
