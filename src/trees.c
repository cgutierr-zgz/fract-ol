/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trees.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgutierr <cgutierr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 11:53:23 by cgutierr          #+#    #+#             */
/*   Updated: 2021/06/15 16:32:21 by cgutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int trees(t_fractol *fractol)
{ /*
	int x;
	int y;

	y = 0;
	while (y < fractol->screen.y)
	{
		x = 0;
		while (x < fractol->screen.x)
		{
			fractol->color = create_trgb(0, 0, 0, 0);
			my_pixel_put(&fractol->main_img, x, y, fractol->color);
			x++;
		}
		y++;
	}*/
	for (int y = 0; y < fractol->screen.y; y++)
		for (int x = 0; x < fractol->screen.x; x++)
		{
			if (
				//Not both the first (rightmost) digits are '1' in base 3
				!(
					(x / 1) % 3 == 1 && (y / 1) % 3 == 1)

				&&

				//Not both the second digits are '1' in base 3
				!(
					(x / 3) % 3 == 1 && (y / 3) % 3 == 1)

				&&

				//Not both the third digits are '1' in base 3
				!(
					(x / 9) % 3 == 1 && (y / 9) % 3 == 1)

				&&

				//Not both the fourth digits are '1' in base 3
				!(
					(x / 27) % 3 == 1 && (y / 27) % 3 == 1)

				&&

				//Not both the fifth digits are '1' in base 3
				!(
					(x / 81) % 3 == 1 && (y / 81) % 3 == 1))
			{

				fractol->color = 231332; //create_trgb(0, 0, 0, 0);
				my_pixel_put(&fractol->main_img, x, y, fractol->color);
			}
			else
			{

				fractol->color = create_trgb(0, 0, 0, 0);
				my_pixel_put(&fractol->main_img, x, y, fractol->color);
			}
			//pset(x, y, RGB_White);
		}
	return (0);
}
