/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgutierr <cgutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 11:53:23 by cgutierr          #+#    #+#             */
/*   Updated: 2021/06/10 15:00:32 by cgutierr         ###   ########.fr       */
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

/*
int main(int argc, char *argv[])
{
  screen(320, 240, 0, "Julia  Explorer");

  //each iteration, it calculates: new = old*old + c, where c is a constant and old starts at current pixel
  double cRe, cIm;           //real and imaginary part of the constant c, determines shape of the Julia Set
  double newRe, newIm, oldRe, oldIm;   //real and imaginary parts of new and old
  double zoom=1, moveX=0, moveY=0; //you can change these to zoom and change position
  ColorRGB color; //the RGB color value for the pixel
  int maxIterations=128; //after how much iterations the function should stop

  double time, oldTime, frameTime; //current and old time, and their difference (for input)
  int showText=0;

  //pick some values for the constant c, this determines the shape of the Julia Set
  cRe = -0.7;
  cIm = 0.27015;

  //begin the program loop
  while(!done())
  {
    //draw the fractal
    for(int y = 0; y < h; y++)
    for(int x = 0; x < w; x++)
    {
      //calculate the initial real and imaginary part of z, based on the pixel location and zoom and position values
      newRe = 1.5 * (x - w / 2) / (0.5 * zoom * w) + moveX;
      newIm = (y - h / 2) / (0.5 * zoom * h) + moveY;
      //i will represent the number of iterations
      int i;
      //start the iteration process
      for(i = 0; i < maxIterations; i++)
      {
        //remember value of previous iteration
        oldRe = newRe;
        oldIm = newIm;
        //the actual iteration, the real and imaginary part are calculated
        newRe = oldRe * oldRe - oldIm * oldIm + cRe;
        newIm = 2 * oldRe * oldIm + cIm;
        //if the point is outside the circle with radius 2: stop
        if((newRe * newRe + newIm * newIm) > 4) break;
      }
      //use color model conversion to get rainbow palette, make brightness black if maxIterations reached
      color = HSVtoRGB(ColorHSV(i % 256, 255, 255 * (i < maxIterations)));
      //draw the pixel
      pset(x, y, color);
    }

    //print the values of all variables on screen if that option is enabled
    if(showText <= 1)
    {
      print("X:", 1, 1, RGB_White, 1); print(moveX, 17, 1, RGB_White, 1);
      print("Y:", 1, 9, RGB_White, 1); print(moveY, 17, 9, RGB_White, 1);
      print("Z:", 1, 17, RGB_White, 1); print(zoom, 17, 17, RGB_White, 1);
      print("R:", 1, 25, RGB_White, 1); print(cRe, 17, 25, RGB_White, 1);
      print("I:", 1, 33, RGB_White, 1); print(cIm, 17, 33, RGB_White, 1);
      print("N:", 1, 41, RGB_White, 1); print(maxIterations, 17, 41, RGB_White, 1);
    }
    //print the help text on screen if that option is enabled
    if(showText == 0)
    {
      print("Arrows move (X,Y), Keypad +,- zooms (Z)", 1, h - 33, RGB_White, 1);
      print("Keypad arrows change shape (R,I)     ", 1, h - 25, RGB_White, 1);
      print("Keypad *,/ changes iterations (N)    ", 1, h - 17, RGB_White, 1);
      print("a to z=presets (qwerty), F1=cycle texts", 1, h - 9, RGB_White, 1);
    }
    redraw();

    //get the time and old time for time dependent input
    oldTime = time;
    time = getTicks();
    frameTime = time - oldTime;
    readKeys();
    //ZOOM keys
    if(keyDown(SDLK_KP_PLUS))  {zoom *= pow(1.001, frameTime);}
    if(keyDown(SDLK_KP_MINUS)) {zoom /= pow(1.001, frameTime);}
    //MOVE keys
    if(keyDown(SDLK_DOWN))  {moveY += 0.0003 * frameTime / zoom;}
    if(keyDown(SDLK_UP))  {moveY -= 0.0003 * frameTime / zoom;}
    if(keyDown(SDLK_RIGHT)) {moveX += 0.0003 * frameTime / zoom;}
    if(keyDown(SDLK_LEFT))  {moveX -= 0.0003 * frameTime / zoom;}
    //CHANGE SHAPE keys
    if(keyDown(SDLK_KP2)) {cIm += 0.0002 * frameTime / zoom;}
    if(keyDown(SDLK_KP8)) {cIm -= 0.0002 * frameTime / zoom;}
    if(keyDown(SDLK_KP6)) {cRe += 0.0002 * frameTime / zoom;}
    if(keyDown(SDLK_KP4)) {cRe -= 0.0002 * frameTime / zoom;}
    //keys to change number of iterations
    if(keyPressed(SDLK_KP_MULTIPLY)) {maxIterations *= 2;}
    if(keyPressed(SDLK_KP_DIVIDE))   {if(maxIterations > 2) maxIterations /= 2;}
    //key to change the text options
    if(keyPressed(SDLK_F1)) {showText++; showText %= 3;}
  }
}

*/