/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgutierr <cgutierr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 02:19:53 by cgutierr          #+#    #+#             */
/*   Updated: 2021/06/11 02:21:16 by cgutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

#define FRAME_TIME 120.0

static void	more_keys(t_fractol *fractol)
{
	if (fractol->move_down)
		fractol->moveY += 0.0003 * FRAME_TIME / fractol->zoom;
	if (fractol->move_up)
		fractol->moveY -= 0.0003 * FRAME_TIME / fractol->zoom;
	if (fractol->move_right)
		fractol->moveX += 0.0003 * FRAME_TIME / fractol->zoom;
	if (fractol->move_left)
		fractol->moveX -= 0.0003 * FRAME_TIME / fractol->zoom;
}

void	fractal_keys(t_fractol *fractol)
{
	if (fractol->zoom_in)
	{
		fractol->zoom *= pow(1.001, FRAME_TIME);
		fractol->zoom_in = 0;
	}
	if (fractol->zoom_out)
	{
		fractol->zoom /= pow(1.001, FRAME_TIME);
		fractol->zoom_out = 0;
	}
	if (fractol->more_iter)
	{
		fractol->maxIterations += 4;
		fractol->more_iter = 0;
	}
	if (fractol->less_iter)
	{
		if (fractol->maxIterations > 4)
			fractol->maxIterations -= 4;
	}
	more_keys(fractol);
}