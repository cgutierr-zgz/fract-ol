/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sierpinski.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgutierr <cgutierr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 11:53:23 by cgutierr          #+#    #+#             */
/*   Updated: 2021/06/16 11:44:56 by cgutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void	mainsierpinki(int *x, int y, t_fractol *fractol)
{
	int n;

	if(fractol->random > 8)
		fractol->random = 4;
	n = fractol->random / 2;
	if (!((*x / 1) % n == 1 && (y / 1) % n == 1) && !((*x / 3) % n == 1
			&& (y / 3) % n == 1) && !((*x / 9) % n == 1
			&& (y / 9) % n == 1) && !((*x / 27) % n == 1
			&& (y / 27) % n == 1) && !((*x / 81) % n == 1
			&& (y / 81) % n == 1))
	{
		fractol->color = create_trgb(0, (cos(y) + y + *x ) * n,
				(*x + y * 2), (y + *x * 2));
		my_pixel_put(&fractol->main_img, *x, y, fractol->color);
	}
	else
	{
		fractol->color = create_trgb(125, 0, 0, 0);
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
		i = sin(x * y) / 2;
		x = 0;
		while (x < fractol->screen.x)
			mainsierpinki(&x, y, fractol);
		y++;
	}
	return (0);
}
