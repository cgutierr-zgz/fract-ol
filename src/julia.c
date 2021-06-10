/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgutierr <cgutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 11:53:23 by cgutierr          #+#    #+#             */
/*   Updated: 2021/06/10 14:59:46 by cgutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void fill_black_screen(t_fractol *fractol)
{
	for (int i = 0; i < fractol->screen.x; i++)
	{

		for (int i2 = 0; i2 < fractol->screen.y; i2++)
		{
			my_pixel_put(&fractol->main_img, i, i2, create_trgb(0, 0, 0, 0));
		}
	}
}

int julia(t_fractol *fractol)
{
	//screen(400, 300, 0, "Julia Set"); //make larger to see more detail!
	mlx_sync(MLX_SYNC_WIN_CMD_COMPLETED, fractol->window);

	//each iteration, it calculates: new = old*old + c, where c is a constant and old starts at current pixel
	double cRe, cIm;					   //real and imaginary part of the constant c, determinate shape of the Julia Set
	double newRe, newIm, oldRe, oldIm;	   //real and imaginary parts of new and old
	double zoom = 1, moveX = 0, moveY = 0; //you can change these to zoom and change position
	int color = rand();					   //the RGB color value for the pixel
	int maxIterations = 300;			   //after how much iterations the function should stop

	//pick some values for the constant c, this determines the shape of the Julia Set
	cRe = -0.7;
	cIm = 0.27015;

	//loop through every pixel
	for (int y = 0; y < fractol->screen.y; y++)
		for (int x = 0; x < fractol->screen.x; x++)
		{
			//calculate the initial real and imaginary part of z, based on the pixel location and zoom and position values
			newRe = 1.5 * (x - fractol->screen.x / 2) / (0.5 * zoom * fractol->screen.x) + moveX;
			newIm = (y - fractol->screen.y / 2) / (0.5 * zoom * fractol->screen.y) + moveY;
			//i will represent the number of iterations
			int i;
			//start the iteration process
			for (i = 0; i < maxIterations; i++)
			{
				//remember value of previous iteration
				oldRe = newRe;
				oldIm = newIm;
				//the actual iteration, the real and imaginary part are calculated
				newRe = oldRe * oldRe - oldIm * oldIm + cRe;
				newIm = 2 * oldRe * oldIm + cIm;
				//if the point is outside the circle with radius 2: stop
				if ((newRe * newRe + newIm * newIm) > 4)
					break;
			}
			//use color model conversion to get rainbow palette, make brightness black if maxIterations reached
			//	color = rand(); //HSVtoRGB(ColorHSV(i % 256, 255, 255 * (i < maxIterations)));
			//draw the pixel
			//pset(x, y, color);
			my_pixel_put(&fractol->main_img, x, y, color - (x * y));
		}
	//make the Julia Set visible and wait to exit
	//redraw();
	//	sleep();
	//	return 0;
	mlx_put_image_to_window(fractol->mlx, fractol->window,
							fractol->main_img.img, 0, 0);
	return (0);
}