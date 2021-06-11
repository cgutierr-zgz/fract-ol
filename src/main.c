/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgutierr <cgutierr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 19:48:28 by cgutierr          #+#    #+#             */
/*   Updated: 2021/06/11 11:53:55 by cgutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

/*
	IDEAS BONUS:
	• Un fractal diferente más.
	• El zoom sigue la posición actual del ratón.
	• Adicionalmente al zoom: moverse con flechas.
	• Haz que el rango de color cambie.
	// save? TODO: regla bonus
	· cambiar iteraciones + -
	· cambiar formas x y z julia
	$ cambiar entre fracatales con el enter
*/

static void	initialize_fractals(t_fractol *fractol)
{
	fractol->zoom = 1;
	fractol->moveX = -0.5;
	fractol->moveY = 0;
	fractol->maxIterations = 24;
	fractol->julia.cRe = -0.7;
	fractol->julia.cIm = 0.27015;
}

static void	setup(t_fractol *fractol)
{
	fractol->main_img.img = mlx_new_image(fractol->mlx,
			fractol->screen.x, fractol->screen.y);
	fractol->main_img.addr = mlx_get_data_addr(fractol->main_img.img,
			&fractol->main_img.bpp, &fractol->main_img.line_l,
			&fractol->main_img.endian);
	initialize_fractals(fractol);
	mlx_hook(fractol->window, KEY_PRESS, 1L << 0, keys, fractol);
	mlx_hook(fractol->window, KEY_RELEASE, 1L << 0, keys_release, fractol);
	mlx_hook(fractol->window, DESTROY_NOTIFY, 0L, destroy, fractol);
	mlx_mouse_hook(fractol->window, mouse_hook, fractol);
	mlx_loop_hook(fractol->mlx, fractals, fractol);
	mlx_loop(fractol->mlx);
}

static void	good_args(char **argv, t_fractol *fractol)
{
	if (!ft_strcmp("julia", argv[1]) && !ft_strcmp("mandelbrot", argv[1]))
	{
		printf("Error\nUnknown set: \"%s\""
			   "\nTry with:\n\t·julia\n\t·mandelbrot\n",
			   argv[1]);
		exit(1);
	}
	if (ft_strcmp("julia", argv[1]))
		fractol->julia.selected = 1;
	if (ft_strcmp("mandelbrot", argv[1]))
		fractol->mdlbr.selected = 1;
	fractol->mlx = mlx_init();
	if (!fractol->mlx)
		print_simple_errors("There was a problem with MiniLibx");
	mlx_get_screen_size(fractol->mlx, &fractol->screen.x, &fractol->screen.y);
	fractol->screen.x = 500;
	fractol->screen.y = 500;
	fractol->window = mlx_new_window(fractol->mlx, fractol->screen.x,
			fractol->screen.y - 55, "fract-ol");
	if (!(fractol->window))
		print_simple_errors("There was a problem opening a new Window");
	setup(fractol);
}

int	main(int argc, char **argv)
{
	t_fractol	fractol;

	ft_bzero(&fractol, sizeof(t_fractol));
	if (argc < 2)
		print_simple_errors("A set is needed"
			"\nTry with:\n\t·julia\n\t·mandelbrot");
	if (argc == 2)
	{
		if (!(ft_strcmp("./fractol", argv[0]) || ft_strcmp("fractol", argv[0])))
			print_simple_errors("Executable must be a \"fractol\" file");
		good_args(argv, &fractol);
	}
	if (argc > 2)
		print_simple_errors("Too many arguments");
	return (0);
}
