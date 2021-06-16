/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgutierr <cgutierr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 11:53:23 by cgutierr          #+#    #+#             */
/*   Updated: 2021/06/16 16:28:49 by cgutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void	draw_line(int x0, int y0, t_fractol *fractol)
{
	int	x1;
	int	y1;

	x1 = fractol->screen.x;
	y1 = fractol->screen.y;
	while (x0 < x1)
	{
		my_pixel_put(&fractol->main_img, x0, y0, create_trgb(0, 255, 0, 0));
		while (y0 < y1)
		{
			my_pixel_put(&fractol->main_img, x0, y0, fractol->color);
			y0++;
			break ;
		}
		x0++;
	}
}

int	grid(t_fractol *fractol)
{
	int	x;
	int	y;

	x = 0;
	fractol->color = create_trgb(0, 0, rand(), 0);
	while (x < fractol->screen.x)
	{
		y = 0;
		while (y < fractol->screen.y)
		{
			my_pixel_put(&fractol->main_img, x, y, create_trgb(0, 0, 0, 0));
			if (x % fractol->maxIterations == 0
				|| y % fractol->maxIterations == 0)
				draw_line(x, y, fractol);
			y++;
		}
		x++;
	}
	return (0);
}
