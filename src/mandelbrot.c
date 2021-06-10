/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgutierr <cgutierr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 11:53:23 by cgutierr          #+#    #+#             */
/*   Updated: 2021/06/11 01:27:21 by cgutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

#define FRAME_TIME 120.0

static void	mandlemove(t_fractol *fractol)
{
	if (fractol->mdlbr.move_down)
		fractol->mdlbr.moveY += 0.0003 * FRAME_TIME / fractol->mdlbr.zoom;
	if (fractol->mdlbr.move_up)
		fractol->mdlbr.moveY -= 0.0003 * FRAME_TIME / fractol->mdlbr.zoom;
	if (fractol->mdlbr.move_right)
		fractol->mdlbr.moveX += 0.0003 * FRAME_TIME / fractol->mdlbr.zoom;
	if (fractol->mdlbr.move_left)
		fractol->mdlbr.moveX -= 0.0003 * FRAME_TIME / fractol->mdlbr.zoom;
}

static void	mandelkeys(t_fractol *fractol)
{
	if (fractol->mdlbr.zoom_in)
	{
		fractol->mdlbr.zoom *= pow(1.001, FRAME_TIME);
		fractol->mdlbr.zoom_in = 0;
	}
	if (fractol->mdlbr.zoom_out)
	{
		fractol->mdlbr.zoom /= pow(1.001, FRAME_TIME);
		fractol->mdlbr.zoom_out = 0;
	}
	if (fractol->mdlbr.more_iter)
	{
		fractol->mdlbr.maxIterations += 4;
		fractol->mdlbr.more_iter = 0;
	}
	if (fractol->mdlbr.less_iter)
	{
		if (fractol->mdlbr.maxIterations > 4)
			fractol->mdlbr.maxIterations -= 4;
	}
	mandlemove(fractol);
}

static void	maindelbrot(t_fractol *fractol, int *x, int *y, int *i)
{
	fractol->mdlbr.pr = 1.5 * (*x - fractol->screen.x / 2)
		/ (0.5 * fractol->mdlbr.zoom * fractol->screen.x)
		+ fractol->mdlbr.moveX;
	fractol->mdlbr.pi = (*y - fractol->screen.y / 2)
		/ (0.5 * fractol->mdlbr.zoom * fractol->screen.y)
		+ fractol->mdlbr.moveY;
	fractol->mdlbr.oldIm = 0;
	fractol->mdlbr.oldRe = fractol->mdlbr.oldIm;
	fractol->mdlbr.newIm = fractol->mdlbr.oldRe;
	fractol->mdlbr.newRe = fractol->mdlbr.newIm;
	*i = 0;
	while (*i < fractol->mdlbr.maxIterations)
	{
		fractol->mdlbr.oldRe = fractol->mdlbr.newRe;
		fractol->mdlbr.oldIm = fractol->mdlbr.newIm;
		fractol->mdlbr.newRe = fractol->mdlbr.oldRe
			* fractol->mdlbr.oldRe - fractol->mdlbr.oldIm
			* fractol->mdlbr.oldIm + fractol->mdlbr.pr;
		fractol->mdlbr.newIm = 2 * fractol->mdlbr.oldRe
			* fractol->mdlbr.oldIm + fractol->mdlbr.pi;
		if ((fractol->mdlbr.newRe * fractol->mdlbr.newRe
				+ fractol->mdlbr.newIm * fractol->mdlbr.newIm) > 4)
			break ;
		*i += 1;
	}
}

//int random = (rand() % (10 - 3 + 1) + 3);
//color = HSVtoRGB(ColorHSV(i % 256, 255, 255 * (i < maxIterations)));

static void	set_color(t_fractol *fractol, int *i)
{
	int	r;
	int	g;
	int	b;

	g = (int)(255 * ((double)*i / (double)fractol->mdlbr.maxIterations));
	r = ((255 - g) * 0.60) * fabs(cos(fractol->mdlbr.random));
	b = ((255 - g) * 0.2) * fabs(sin(fractol->mdlbr.random_two));
	fractol->mdlbr.color = create_trgb(0, r * fractol->mdlbr.random, g, b);
	if (g == 255)
		fractol->mdlbr.color = create_trgb(0, 0, 0, 0);
}

int	mandelbrot(t_fractol *fractol)
{
	int	y;
	int	x;
	int	i;

	y = 0;
	fractol->mdlbr.random += 0.025;
	fractol->mdlbr.random_two += 0.01;
	mlx_sync(MLX_SYNC_WIN_CMD_COMPLETED, fractol->window);
	while (y < fractol->screen.y)
	{
		x = 0;
		while (x < fractol->screen.x)
		{
			maindelbrot(fractol, &x, &y, &i);
			set_color(fractol, &i);
			my_pixel_put(&fractol->main_img, x, y, fractol->mdlbr.color);
			x++;
		}
		y++;
	}
	mandelkeys(fractol);
	mlx_put_image_to_window(fractol->mlx, fractol->window,
		fractol->main_img.img, 0, 0);
	return (0);
}
