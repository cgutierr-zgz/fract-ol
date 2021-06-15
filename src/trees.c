/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trees.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgutierr <cgutierr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 11:53:23 by cgutierr          #+#    #+#             */
/*   Updated: 2021/06/15 15:29:13 by cgutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int trees(t_fractol *fractol)
{
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
	}
	mlx_put_image_to_window(fractol->mlx, fractol->window,
							fractol->main_img.img, 0, 0);

	return (0);
}
