/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgutierr <cgutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 19:48:28 by cgutierr          #+#    #+#             */
/*   Updated: 2021/06/10 12:05:58 by cgutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"
int destroy(t_fractol *cub)
{
	int x = cub->julia;
	x++;
	exit(1);
}

int keys(int keycode, t_fractol *cub)
{
	if (keycode == K_ESC)
		destroy(cub);
	//printf("\rbye\n"); //cub->mov.up = 1;
	//fflush(stdout);
	if (keycode == K_W)
	{
	}
	if (keycode == K_A)
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
		cub->mov.mov_s *= 2;
	return (keycode);
}

static void good_args(char **argv, t_fractol *fractol)
{
	if (!ft_strcmp("julia", argv[1]) && !ft_strcmp("mandelbrot", argv[1]))
	{
		printf("Error\nUnknown command: ");
		printf("\"%s\"\n", argv[1]);
		printf("Try with:\n\t·julia\n\t·mandelbrot\n");
		//FIXME: change this tosingle line && add exit
		exit(1);
	}
	if (ft_strcmp("julia", argv[1]))
		fractol->julia = 1;
	if (ft_strcmp("mandelbrot", argv[1]))
		fractol->mandelbrot = 1;
	/*
	Minilibx+window
	Handle events (Hooks+loop)
	Teclas -> Esc, mover, zooms, etc...
	Pintar
	Cerrar
	IDEAS BONUS:
	• Un fractal diferente más.
	• El zoom sigue la posición actual del ratón.
	• Adicionalmente al zoom: moverse con flechas.
	• Haz que el rango de color cambie.
	// save?
	
	*/

	fractol->mlx = mlx_init();
	if (!fractol->mlx)
	{
		print_simple_errors("There was a problem with MiniLibx");
		exit(1);
	}
	//TODO: Change 100 x 100 for window size
	//	int	x;
	//	int	y;

	//mlx_get_screen_size(fractol->mlx, &x, &y);
	mlx_get_screen_size(fractol->mlx, &fractol->screen.x, &fractol->screen.y);
	//mlx_get_screen_size(fractol->mlx, fractol->window.x, &fractol->window.y);

	// FIXME: 45 55.. etcc
	fractol->window = mlx_new_window(fractol->mlx, fractol->screen.x, fractol->screen.y - 55, "fract-ol");
// if ! window???


	fractol->main_img.img = mlx_new_image(fractol->mlx,
			fractol->screen.x, fractol->screen.y);
	fractol->main_img.addr = mlx_get_data_addr(fractol->main_img.img,
			&fractol->main_img.bpp, &fractol->main_img.line_l,
			&fractol->main_img.endian);





	mlx_hook(fractol->window, KEY_PRESS, 1L << 0, keys, fractol);
	mlx_hook(fractol->window, DESTROY_NOTIFY, 0L, destroy, fractol);
	//	mlx_hook(fractol->window, KEY_RELEASE, 1L << 1, key_release, cub);
	mlx_loop_hook(fractol->mlx, mandelbrot, fractol);

	mlx_loop(fractol->mlx);
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
