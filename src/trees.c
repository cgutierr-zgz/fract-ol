/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trees.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgutierr <cgutierr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 11:53:23 by cgutierr          #+#    #+#             */
/*   Updated: 2021/06/15 19:32:27 by cgutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int trees(t_fractol *fractol)
{
	int y = 0;
	int x;
	int i;
	y = 0;
	int n;
	n = 1;
	//n *= fractol->random / fractol->random_two;
	while (y < fractol->screen.y)
	{
		i = 2;//rand() * sin(x * y) / 2;
		x = 0;

		while (x < fractol->screen.x)
		{
			//	if (!((x / 1) % rando == 1 && (y / 1) % rando == 1) && !((x / rando) % rando == 1 && (y / rando) % rando == 1) && !((x / (rando * 3)) % rando == 1 && (y / (rando * 3)) % rando == 1) && !((x / (rando * 9)) % rando == 1 && (y / (rando * 9)) % rando == 1) && !((x / (rando * 27)) % rando == 1 && (y / (27 * rando)) % rando == 1))

			if (!((x / 1) % n == 1 && (y / 1) % n == 1) && !((x / 3) % n == 1 && (y / 3) % n == 1) && !((x / 9) % n == 1 && (y / 9) % n == 1) && !((x / 27) % n == 1 && (y / 27) % n == 1) && !((x / 81) % n == 1 && (y / 81) % n == 1))
			{
				set_color(fractol, &i); // &x, etc...
				//fractol->color = 231332;
				my_pixel_put(&fractol->main_img, x, y, fractol->color);
			}
			else
			{
				fractol->color = create_trgb(0, 0, 0, 0);
				my_pixel_put(&fractol->main_img, x, y, fractol->color);
			}
			x++;
		}
		y++;
	}
	return (0);
}
