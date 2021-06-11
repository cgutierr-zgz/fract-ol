/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgutierr <cgutierr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 18:45:44 by cgutierr          #+#    #+#             */
/*   Updated: 2021/06/11 02:17:51 by cgutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	destroy(t_fractol *fractol)
{
	fractol->mdlbr.selected = 0;
	fractol->julia.selected = 0;
	exit(0);
}

static void	handle_keys_mandelbrot(int keycode, t_fractol *fractol)
{
	if (keycode == K_DOWN)
		fractol->move_down = 1;
	if (keycode == K_LEFT)
		fractol->move_left = 1;
	if (keycode == K_RIGHT)
		fractol->move_right = 1;
	if (keycode == K_UP)
		fractol->move_up = 1;
	if (keycode == K_PLUS)
		fractol->more_iter = 1;
	if (keycode == K_LESS)
		fractol->less_iter = 1;
}

static void	handle_keys_release_mandelbrot(int keycode, t_fractol *fractol)
{
	if (keycode == K_DOWN)
		fractol->move_down = 0;
	if (keycode == K_LEFT)
		fractol->move_left = 0;
	if (keycode == K_RIGHT)
		fractol->move_right = 0;
	if (keycode == K_UP)
		fractol->move_up = 0;
	if (keycode == K_PLUS)
		fractol->more_iter = 0;
	if (keycode == K_LESS)
		fractol->less_iter = 0;
}

//TODO: Key to change between julia and mandelbrot?

int	keys(int keycode, t_fractol *fractol)
{
	if (keycode == K_ESC)
		destroy(fractol);
	if (fractol->mdlbr.selected)
		handle_keys_mandelbrot(keycode, fractol);
	if (fractol->julia.selected)
	;
	return (keycode);
}

int	keys_release(int keycode, t_fractol *fractol)
{
	//if (fractol->mdlbr.selected)
		handle_keys_release_mandelbrot(keycode, fractol);
	//if (fractol->julia.selected)
	//;
	return (keycode);
}

// TODO: Zoom to mouse position

int	mouse_hook(int keycode, int x, int y, t_fractol *fractol)
{
	x++;
	y++;
	if (fractol->mdlbr.selected)
	{
		if (keycode == SCROLL_UP && fractol->zoom > 0.1)
			fractol->zoom_out = 1;
		if (keycode == SCROLL_DOWN)
			fractol->zoom_in = 1;
	}
	return (0);
}
