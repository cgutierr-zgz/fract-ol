/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgutierr <cgutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 18:45:44 by cgutierr          #+#    #+#             */
/*   Updated: 2021/06/10 21:10:20 by cgutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int destroy(t_fractol *fractol)
{
	int x = fractol->julia;
	x++;
	exit(0);
}

static void handle_keys_mandelbrot(int keycode, t_fractol *fractol)
{
	if (keycode == K_DOWN)
		fractol->mdlbr.move_down = 1;
	if (keycode == K_LEFT)
		fractol->mdlbr.move_left = 1;
	if (keycode == K_RIGHT)
		fractol->mdlbr.move_right = 1;
	if (keycode == K_UP)
		fractol->mdlbr.move_up = 1;
	if (keycode == K_PLUS)
		fractol->mdlbr.more_iter = 1;
	if (keycode == K_LESS)
		fractol->mdlbr.less_iter = 1;
}

static void handle_keys_release_mandelbrot(int keycode, t_fractol *fractol)
{
	if (keycode == K_DOWN)
		fractol->mdlbr.move_down = 0;
	if (keycode == K_LEFT)
		fractol->mdlbr.move_left = 0;
	if (keycode == K_RIGHT)
		fractol->mdlbr.move_right = 0;
	if (keycode == K_UP)
		fractol->mdlbr.move_up = 0;
	if (keycode == K_PLUS)
		fractol->mdlbr.more_iter = 0;
	if (keycode == K_LESS)
		fractol->mdlbr.less_iter = 0;
}

int keys(int keycode, t_fractol *fractol)
{
	if (keycode == K_ESC)
		destroy(fractol);
	if (fractol->mdlbr.selected)
		handle_keys_mandelbrot(keycode, fractol);
	//	printf("KEY = [%d]\n", keycode);
	return (keycode);
}

int keys_release(int keycode, t_fractol *fractol)
{
	if (fractol->mdlbr.selected)
		handle_keys_release_mandelbrot(keycode, fractol);
	return (keycode);
}

int mouse_hook(int keycode, int x, int y, t_fractol *fractol)
{
	if (fractol->mdlbr.selected)
	{
		if (keycode == SCROLL_UP)
			fractol->mdlbr.zoom_out = 1;
		if (keycode == SCROLL_DOWN && fractol->mdlbr.zoom > 0.1)
			fractol->mdlbr.zoom_in = 1;
	}
	return (0);
}