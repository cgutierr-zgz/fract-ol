/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sierpinski.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgutierr <cgutierr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 11:53:23 by cgutierr          #+#    #+#             */
/*   Updated: 2021/06/15 21:19:15 by cgutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void	mainsierpinki(int *x, int y, int *i, t_fractol *fractol)
{
	if (!((*x / 1) % 3 == 1 && (y / 1) % 3 == 1) && !((*x / 3) % 3 == 1
			&& (y / 3) % 3 == 1) && !((*x / 9) % 3 == 1
			&& (y / 9) % 3 == 1) && !((*x / 27) % 3 == 1
			&& (y / 27) % 3 == 1) && !((*x / 81) % 3 == 1
			&& (y / 81) % 3 == 1))
	{
		set_color(fractol, i);
		my_pixel_put(&fractol->main_img, *x, y, fractol->color);
	}
	else
	{
		fractol->color = create_trgb(0, 0, 0, 0);
		my_pixel_put(&fractol->main_img, *x, y, fractol->color);
	}
	*x += 1;
}

int	sierpinski(t_fractol *fractol)
{
	int	y;
	int	x;
	int	i;

	y = 0;
	while (y < fractol->screen.y)
	{
		i = rand() * sin(x * y) / 2;
		x = 0;
		while (x < fractol->screen.x)
			mainsierpinki(&x, y, &i, fractol);
		y++;
	}
	return (0);
}
