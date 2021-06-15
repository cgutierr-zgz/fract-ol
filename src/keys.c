/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgutierr <cgutierr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 18:45:44 by cgutierr          #+#    #+#             */
/*   Updated: 2021/06/15 19:30:27 by cgutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int destroy(t_fractol *fractol)
{
	fractol->mdlbr.selected = 0;
	fractol->julia.selected = 0;
	exit(0);
}

int keys(int keycode, t_fractol *fractol)
{
	if (keycode == K_ESC)
		destroy(fractol);
	if (fractol->bonus)
	{
		if (keycode == K_DOWN || keycode == K_S)
			fractol->move_down = 1;
		if (keycode == K_LEFT || keycode == K_A)
			fractol->move_left = 1;
		if (keycode == K_RIGHT || keycode == K_D)
			fractol->move_right = 1;
		if (keycode == K_UP || keycode == K_W)
			fractol->move_up = 1;
		if (keycode == K_PLUS)
			fractol->more_iter = 1;
		if (keycode == K_LESS)
			fractol->less_iter = 1;
	}
	return (keycode);
}

static void change_fractal(t_fractol *fractol)
{
	if (fractol->julia.selected)
	{
		fractol->mdlbr.selected = 1;
		fractol->julia.selected = 0;
		fractol->sierpinski.selected = 0;
		fractol->trees.selected = 0;
	}
	else if (fractol->mdlbr.selected)
	{
		fractol->mdlbr.selected = 0;
		fractol->julia.selected = 0;
		fractol->sierpinski.selected = 1;
		fractol->trees.selected = 0;
	}
	else if (fractol->sierpinski.selected)
	{
		fractol->mdlbr.selected = 0;
		fractol->julia.selected = 0;
		fractol->sierpinski.selected = 0;
		fractol->trees.selected = 1;
	}
	else if (fractol->trees.selected)
	{
		fractol->mdlbr.selected = 0;
		fractol->julia.selected = 1;
		fractol->sierpinski.selected = 0;
		fractol->trees.selected = 0;
	}
}

int keys_release(int keycode, t_fractol *fractol)
{
	if (fractol->bonus)
	{
		if (keycode == K_DOWN || keycode == K_S)
			fractol->move_down = 0;
		if (keycode == K_LEFT || keycode == K_A)
			fractol->move_left = 0;
		if (keycode == K_RIGHT || keycode == K_D)
			fractol->move_right = 0;
		if (keycode == K_UP || keycode == K_W)
			fractol->move_up = 0;
		if (keycode == K_PLUS)
			fractol->more_iter = 0;
		if (keycode == K_LESS)
			fractol->less_iter = 0;
		if (keycode == K_ENTER)
			change_fractal(fractol);
		if (keycode == K_ONE)
			fractol->julia.cIm += 0.0002 * FRAME_TIME / fractol->zoom;
		if (keycode == K_TWO)
			fractol->julia.cIm -= 0.0002 * FRAME_TIME / fractol->zoom;
		if (keycode == K_THREE)
			fractol->julia.cRe += 0.0002 * FRAME_TIME / fractol->zoom;
		if (keycode == K_FOUR)
			fractol->julia.cRe -= 0.0002 * FRAME_TIME / fractol->zoom;
	}
	return (keycode);
}

// TODO: Zoom to mouse position

int mouse_hook(int keycode, int x, int y, t_fractol *fractol)
{
	x++; y++;
	if (keycode == SCROLL_UP && fractol->zoom > 0.1)
		fractol->zoom_out = 1;
	if (keycode == SCROLL_DOWN)
		fractol->zoom_in = 1;
	if (fractol->bonus)
	{
		/*
		if (x >= fractol->screen.x / 2)
		{
			fractol->moveX += (x * 0.000003) * FRAME_TIME / fractol->zoom;
		}
		else
		{

			fractol->moveX -= (x * 0.000003) * FRAME_TIME / fractol->zoom;
		}

		if (y >= fractol->screen.y / 2)
		{
			fractol->moveY += (y * 0.000003) * FRAME_TIME / fractol->zoom;
		}
		else
		{

			fractol->moveY -= (y * 0.000003) * FRAME_TIME / fractol->zoom;
		}*/
	}
	return (0);
}
