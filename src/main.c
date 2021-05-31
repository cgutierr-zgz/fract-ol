/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgutierr <cgutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 19:48:28 by cgutierr          #+#    #+#             */
/*   Updated: 2021/06/01 00:58:21 by cgutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int destroy(t_fractol *cub)
{

	int x = cub->save_first;
	x++;
	exit(1);
}

int keys(int keycode, t_fractol *cub)
{
	int x = cub->save_first;
	x++;
	if (keycode == K_ESC)
		destroy(cub);
	printf("\rbye\n"); //cub->mov.up = 1;
	fflush(stdout);
	if (keycode == K_W)
	{
	}
	/*if (keycode == K_A)
		cub->mov.left = 1;
	if (keycode == K_S)
		cub->mov.down = 1;
	if (keycode == K_D)
		cub->mov.right = 1;
	if (keycode == K_LEFT)
		cub->mov.rotate_left = 1;
	if (keycode == K_RIGHT)
		cub->mov.rotate_right = 1;
	else if (keycode == L_SHIFT)
		cub->mov.mov_s *= 2;*/
	return (keycode);
}
//#include <curses.h>

static void good_args(char **argv, t_fractol *fractol)
{
	if (!ft_strcmp("julia", argv[1]) && !ft_strcmp("mandelbrot", argv[1]))
	{
		printf("Error\nUnknown command: ");
		printf(W_B_RED "\"%s\"\n" RESET, argv[1]);
		printf("Try with:\n\t·julia\n\t·mandelbrot\n");
		exit(1);
		//FIXME: cambiar este exit por otra cosa en este y argc < 2 y tal
	}
	fractol->save_first = 1;
	//	read_file(cub);
	/*
	Minilibx+window
	Handle events (Hooks+loop)
	Teclas -> Esc, mover, zooms, etc...
	Pintar
	Cerrar
	// save?
*/

	/*
	fractol->mlx = mlx_init();
	if (!fractol->mlx)
	{
		print_simple_errors("There was a problem with MiniLibx");
		exit(1);
	}
	//TODO: Change 100 x 100 for window size
fractol->window = mlx_new_window(fractol->mlx, 100, 100, "SOPA");*/

	//	mlx_hook(fractol->window, KEY_PRESS, 1L << 0, keys, fractol);
	/*mlx_hook(fractol->window, DESTROY_NOTIFY, 0L, destroy, cub);
	mlx_hook(fractol->window, KEY_RELEASE, 1L << 1, key_release, cub);
	mlx_loop_hook(cub->mlx, raycast, cub);
*/
	//	mlx_loop(fractol->mlx); // change this for a while(1) loop

}

int main(int argc, char **argv)
{
	t_fractol fractol;

	ft_bzero(&fractol, sizeof(t_fractol));
	if (argc < 2)
	{
		print_simple_errors("A command is needed");
		printf("Try with:\n\t·julia\n\t·mandelbrot\n");
		exit(1);
	}
	if (argc == 2)
	{
		if (!(ft_strcmp("./fractol", argv[0]) || ft_strcmp("fractol", argv[0])))
		{
			print_simple_errors("Executable must be a \"fractol\" file");
			exit(1);
		}
		good_args(argv, &fractol);
	}
	if (argc > 2)
	{
		print_simple_errors("Too many arguments");
		exit(1);
	}
	return (0);
}
