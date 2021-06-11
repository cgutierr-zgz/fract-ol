/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgutierr <cgutierr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 11:53:23 by cgutierr          #+#    #+#             */
/*   Updated: 2021/06/11 02:55:40 by cgutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int julia(t_fractol *fractol)
{
	for (int y = 0; y < fractol->screen.y; y++)
		for (int x = 0; x < fractol->screen.x; x++)
		{
			//calculate the initial real and imaginary part of z, based on the pixel location and zoom and position values
			fractol->julia.newRe = 1.5 * (x - fractol->screen.y / 2) / (0.5 * fractol->zoom * fractol->screen.x) + fractol->moveX;
			fractol->julia.newIm = (y - fractol->screen.y / 2) / (0.5 * fractol->zoom * fractol->screen.y) + fractol->moveY;
			//i will represent the number of iterations
			int i;
			//start the iteration process
			for (i = 0; i < fractol->maxIterations; i++)
			{
				//remember value of previous iteration
				fractol->julia.oldRe = fractol->julia.newRe;
				fractol->julia.oldIm = fractol->julia.newIm;
				//the actual iteration, the real and imaginary part are calculated
				fractol->julia.newRe = fractol->julia.oldRe * fractol->julia.oldRe - fractol->julia.oldIm * fractol->julia.oldIm + fractol->julia.cRe;
				fractol->julia.newIm = 2 * fractol->julia.oldRe * fractol->julia.oldIm + fractol->julia.cIm;
				//if the point is outside the circle with radius 2: stop
				if ((fractol->julia.newRe * fractol->julia.newRe + fractol->julia.newIm * fractol->julia.newIm) > 4)
					break;
			}
			//use color model conversion to get rainbow palette, make brightness black if maxIterations reached
			fractol->color = create_trgb(0, i % 256, 255, 255 * (i < fractol->maxIterations)); //HSVtoRGB(ColorHSV(i % 256, 255, 255 * (i < maxIterations)));
																							   //draw the pixel
																							   //pset(x, y, color);
			my_pixel_put(&fractol->main_img, x, y, fractol->color);
		}

	//redraw(); //JULIA KEYS
	fractal_keys(fractol);

	mlx_put_image_to_window(fractol->mlx, fractol->window,
							fractol->main_img.img, 0, 0);

	/*
    //CHANGE SHAPE keys
    if(keyDown(SDLK_KP2)) {cIm += 0.0002 * frameTime / zoom;}
    if(keyDown(SDLK_KP8)) {cIm -= 0.0002 * frameTime / zoom;}
    if(keyDown(SDLK_KP6)) {cRe += 0.0002 * frameTime / zoom;}
    if(keyDown(SDLK_KP4)) {cRe -= 0.0002 * frameTime / zoom;}
	*/
	return (0);
}
