/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trees.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgutierr <cgutierr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 11:53:23 by cgutierr          #+#    #+#             */
/*   Updated: 2021/06/15 20:00:34 by cgutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void recursion(double posX, double posY, double dirX, double dirY, double size, int n,
			   t_fractol *fractol)
{
	double pi = 3.1415926535897932384626433832795;

	double angle = 0.2 * pi; //angle in radians
	double shrink = 1.8;	 //relative size of new branches

	int x1, x2, y1, y2;
	int x3, x4, y3, y4;
	x1 = (int)(posX);
	y1 = (int)(posY);
	x2 = (int)(posX + size * dirX);
	y2 = (int)(posY + size * dirY);
	//	if (clipLine(x1, y1, x2, y2, x3, y3, x4, y4))
	//		drawLine(x3, y3, x4, y4, ColorRGB(128, 96, 64));
	//	fractol->color = 23423;
	//	my_pixel_put(&fractol->main_img, x1, y1, fractol->color);

	if (n >= fractol->maxIterations)
		return;

	double posX2, posY2, dirX2, dirY2, size2;
	int n2;
	posX2 = posX + size * dirX;
	posY2 = posY + size * dirY;
	size2 = size / shrink;
	n2 = n + 1;
	dirX2 = cos(angle) * dirX + sin(angle) * dirY;
	dirY2 = -sin(angle) * dirX + cos(angle) * dirY;
	recursion(posX2, posY2, dirX2, dirY2, size2, n2, fractol);
	dirX2 = cos(-angle) * dirX + sin(-angle) * dirY;
	dirY2 = -sin(-angle) * dirX + cos(-angle) * dirY;
	recursion(posX2, posY2, dirX2, dirY2, size2, n2, fractol);
}

int trees(t_fractol *fractol)
{
	recursion(fractol->screen.x / 2, fractol->screen.y - 1, 0, -1, fractol->screen.y / 2.3, 0, fractol);
	return (0);
}
