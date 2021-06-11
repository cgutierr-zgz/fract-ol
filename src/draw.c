/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgutierr <cgutierr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 12:00:56 by cgutierr          #+#    #+#             */
/*   Updated: 2021/06/11 02:56:34 by cgutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	my_pixel_put(t_img *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_l + x * (data->bpp / 8));
	*(unsigned int *)dst = color;
}

int	my_pixel_get(t_img *data, int x, int y)
{
	return (*(unsigned int *)(data->addr
		+ (y * data->line_l + x * (data->bpp / 8))));
}

int	fractals(t_fractol *fractol)
{
	if (fractol->julia.selected)
	{
		julia(fractol);
		return (0);
	}
	else if (fractol->mdlbr.selected)
	{
		mandelbrot(fractol);
		return (0);
	}
	return (0);
}