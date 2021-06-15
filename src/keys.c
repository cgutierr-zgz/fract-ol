/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgutierr <cgutierr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 18:45:44 by cgutierr          #+#    #+#             */
/*   Updated: 2021/06/15 15:19:47 by cgutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	destroy(t_fractol *fractol)
{
	fractol->mdlbr.selected = 0;
	fractol->julia.selected = 0;
	exit(0);
}

int	keys(int keycode, t_fractol *fractol)
{
	if (keycode == K_ESC)
		destroy(fractol);
	if (keycode == K_DOWN || (keycode == K_S && fractol->bonus))
		fractol->move_down = 1;
	if (keycode == K_LEFT || (keycode == K_A && fractol->bonus))
		fractol->move_left = 1;
	if (keycode == K_RIGHT || (keycode == K_D && fractol->bonus))
		fractol->move_right = 1;
	if (keycode == K_UP || (keycode == K_W && fractol->bonus))
		fractol->move_up = 1;
	if (keycode == K_PLUS && fractol->bonus)
		fractol->more_iter = 1;
	if (keycode == K_LESS && fractol->bonus)
		fractol->less_iter = 1;
	return (keycode);
}

static void	change_fractal(t_fractol *fractol)
{
	if (fractol->julia.selected)
	{
		fractol->mdlbr.selected = 1;
		fractol->julia.selected = 0;
	}
	else if (fractol->mdlbr.selected)
	{
		fractol->mdlbr.selected = 0;
		fractol->julia.selected = 1;
	}
}

int	keys_release(int keycode, t_fractol *fractol)
{
	if (keycode == K_DOWN || (keycode == K_S && fractol->bonus))
		fractol->move_down = 0;
	if (keycode == K_LEFT || (keycode == K_A && fractol->bonus))
		fractol->move_left = 0;
	if (keycode == K_RIGHT || (keycode == K_D && fractol->bonus))
		fractol->move_right = 0;
	if (keycode == K_UP || (keycode == K_W && fractol->bonus))
		fractol->move_up = 0;
	if (keycode == K_PLUS && fractol->bonus)
		fractol->more_iter = 0;
	if (keycode == K_LESS && fractol->bonus)
		fractol->less_iter = 0;
	if (keycode == K_ENTER && fractol->bonus)
		change_fractal(fractol);
	return (keycode);
}

// TODO: Zoom to mouse position

int	mouse_hook(int keycode, int x, int y, t_fractol *fractol)
{
	x++;
	y++;
	if (keycode == SCROLL_UP && fractol->zoom > 0.1)
		fractol->zoom_out = 1;
	if (keycode == SCROLL_DOWN)
		fractol->zoom_in = 1;
	return (0);
}
