/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgutierr <cgutierr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 12:00:56 by cgutierr          #+#    #+#             */
/*   Updated: 2021/06/15 16:33:40 by cgutierr         ###   ########.fr       */
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

void	set_color(t_fractol *fractol, int *i)
{
	int	r;
	int	g;
	int	b;

	g = (int)(255 * ((double)*i / (double)fractol->maxIterations));
	r = ((255 - g) * 0.60) * fabs(cos(fractol->random));
	b = ((255 - g) * 0.2) * fabs(sin(fractol->random_two));
	fractol->color = create_trgb(0, r * fractol->random, g, b);
	if (g == 255)
		fractol->color = create_trgb(0, 0, 0, 0);
}

int	fractals(t_fractol *fractol)
{
	if(fractol->bonus)
	{
		fractol->random += 0.025;
		fractol->random_two += 0.010;
	}
	mlx_sync(MLX_SYNC_WIN_CMD_COMPLETED, fractol->window);
	if (fractol->julia.selected)
		julia(fractol);
	else if (fractol->mdlbr.selected)
		mandelbrot(fractol);
	else if (fractol->sierpinski.selected)
		sierpinski(fractol);
	fractal_keys(fractol);
	mlx_put_image_to_window(fractol->mlx, fractol->window,
							fractol->main_img.img, 0, 0);
	return (0);
}
