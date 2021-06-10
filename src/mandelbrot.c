/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgutierr <cgutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 11:53:23 by cgutierr          #+#    #+#             */
/*   Updated: 2021/06/10 20:10:16 by cgutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

#define FRAME_TIME 60.0

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
		if (fractol->mdlbr.maxIterations > 2)
			fractol->mdlbr.maxIterations /= 2;
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

int	mandelbrot(t_fractol *fractol)
{
	int	y;
	int	x;
	int	i;

	y = 0;
	mlx_sync(MLX_SYNC_WIN_CMD_COMPLETED, fractol->window);
	while (y < fractol->screen.y)
	{
		x = 0;
		while (x < fractol->screen.x)
		{
			maindelbrot(fractol, &x, &y, &i);
			fractol->mdlbr.color = create_trgb(0, i % 256, 255, 255
					* (i < fractol->mdlbr.maxIterations));
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
