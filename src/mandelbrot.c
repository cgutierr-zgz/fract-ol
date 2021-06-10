/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgutierr <cgutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 11:53:23 by cgutierr          #+#    #+#             */
/*   Updated: 2021/06/10 14:52:43 by cgutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"
#include <math.h>
#define MAXCOUNT 30
// Function to draw mandelbrot set
void fractal(t_fractol *fractol)
{

	float left, top, xside, yside;

	left = -1.75;
	top = -0.25;
	xside = 0.25;
	yside = 0.45;

	float xscale, yscale, zx, zy, cx, tempx, cy;
	int x, y; // i, j;
	int maxx, maxy, count;

	// getting maximum value of x-axis of screen
	maxx = fractol->screen.x; //getmaxx();

	// getting maximum value of y-axis of screen
	maxy = fractol->screen.y; //getmaxy();

	// setting up the xscale and yscale
	xscale = xside / maxx;
	yscale = yside / maxy;

	// calling rectangle function
	// where required image will be seen
	//rectangle(0, 0, maxx, maxy);//FIXME:

	// scanning every point in that rectangular area.
	// Each point represents a Complex number (x + yi).
	// Iterate that complex number
	for (y = 1; y <= maxy - 1; y++)
	{
		for (x = 1; x <= maxx - 1; x++)
		{
			// c_real
			cx = x * xscale + left;

			// c_imaginary
			cy = y * yscale + top;

			// z_real
			zx = 0;

			// z_imaginary
			zy = 0;
			count = 0;

			// Calculate whether c(c_real + c_imaginary) belongs
			// to the Mandelbrot set or not and draw a pixel
			// at coordinates (x, y) accordingly
			// If you reach the Maximum number of iterations
			// and If the distance from the origin is
			// greater than 2 exit the loop
			while ((zx * zx + zy * zy < 4) && (count < MAXCOUNT))
			{
				// Calculate Mandelbrot function
				// z = z*z + c where z is a complex number

				// tempx = z_real*_real - z_imaginary*z_imaginary + c_real
				tempx = zx * zx - zy * zy + cx;

				// 2*z_real*z_imaginary + c_imaginary
				zy = 2 * zx * zy + cy;

				// Updating z_real = tempx
				zx = tempx;

				// Increment count
				count = count + 1;
			}

			// To display the created fractal
			my_pixel_put(&fractol->main_img, x, y, rand());
			//my_pixel_put(&fractol->main_img, x, y, create_trgb(0, 255, 55, 42));
			//putpixel(x, y, count);
		}
	}
}

int mandelbrot(t_fractol *fractol)
{
	//fractal(fractol);
	mlx_sync(MLX_SYNC_WIN_CMD_COMPLETED, fractol->window);
	int A, B, i;
	double a, b, x, y, t, n = 200;
	int color_random = rand();

	for (B = 0; B <= 4 * n; B++)
	{
		b = 2 - (B / n);
		for (A = 0; A <= 4 * n; A++)
		{
			a = -2 + (A / n);
			x = 0;
			y = 0;
			for (i = 1; i <= 1000; i++)
			{
				t = x;

				x = (x * x) - (y * y) + a;
				y = (2 * t * y) + b;
				if ((x * x) + (y * y) > 4)
					break;
			}
			if (i == 1001) //color_random - (A * B));
				my_pixel_put(&fractol->main_img, A, B, color_random - (A * B));
			else
				my_pixel_put(&fractol->main_img, A, B, create_trgb(0, 0, 0, 0));
		}
	}

	mlx_put_image_to_window(fractol->mlx, fractol->window, fractol->main_img.img, fractol->screen.x / 4, fractol->screen.y / 4);
	return (0);
}