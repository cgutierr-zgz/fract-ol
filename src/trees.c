/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trees.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgutierr <cgutierr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 11:53:23 by cgutierr          #+#    #+#             */
/*   Updated: 2021/06/15 23:17:47 by cgutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void draw_line(int x0, int y0, int x1, int y1, t_fractol *fractol)
{
	while (x0 < x1)
	{
		my_pixel_put(&fractol->main_img, x0, y0, create_trgb(0, 0, 0, 0));
		while (y0 < y1)
		{
			my_pixel_put(&fractol->main_img, x0, y0, 31243);
			y0++;
			break;
		}

		x0++;
	}
}

int trees(t_fractol *fractol)
{
	draw_line(0, 0, fractol->screen.x, fractol->screen.y, fractol);
	return (0);
}
