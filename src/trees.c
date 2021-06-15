/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trees.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgutierr <cgutierr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 11:53:23 by cgutierr          #+#    #+#             */
/*   Updated: 2021/06/15 15:13:37 by cgutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int trees(t_fractol *fractol)
{
	int x = 0;
	int y = 0;
	fractol->color = create_trgb(0, 0, 0, 0);
	my_pixel_put(&fractol->main_img, x, y, fractol->color);

	mlx_put_image_to_window(fractol->mlx, fractol->window,
							fractol->main_img.img, 0, 0);

	return (0);
}
