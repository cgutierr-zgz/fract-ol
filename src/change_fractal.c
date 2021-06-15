/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_fractal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgutierr <cgutierr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 18:45:44 by cgutierr          #+#    #+#             */
/*   Updated: 2021/06/15 21:28:47 by cgutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void	set_fractal(int julia, int si, int tree, t_fractol *fctl)
{
	fctl->mdlbr.selected = 0;
	fctl->julia.selected = julia;
	fctl->sierpinski.selected = si;
	fctl->trees.selected = tree;
}

void	change_fractal(t_fractol *fractol)
{
	if (fractol->julia.selected)
	{
		fractol->mdlbr.selected = 1;
		fractol->julia.selected = 0;
		fractol->sierpinski.selected = 0;
		fractol->trees.selected = 0;
	}
	else if (fractol->mdlbr.selected)
		set_fractal(0, 1, 0, fractol);
	else if (fractol->sierpinski.selected)
		set_fractal(0, 0, 1, fractol);
	else if (fractol->trees.selected)
		set_fractal(1, 0, 0, fractol);
}
