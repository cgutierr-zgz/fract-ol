/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_fractal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgutierr <cgutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 18:45:44 by cgutierr          #+#    #+#             */
/*   Updated: 2021/06/16 17:17:39 by cgutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void	set_fractal(int mdlbr, int julia, int si, t_fractol *fctl)
{
	fctl->mdlbr.selected = mdlbr;
	fctl->julia.selected = julia;
	fctl->sierpinski.selected = si;
}

void	change_fractal(t_fractol *fractol)
{
	if (fractol->julia.selected)
		set_fractal(1, 0, 0, fractol);
	else if (fractol->mdlbr.selected)
		set_fractal(0, 0, 1, fractol);
	else if (fractol->sierpinski.selected)
		set_fractal(0, 1, 0, fractol);
}
