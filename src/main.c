/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgutierr <cgutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 19:48:28 by cgutierr          #+#    #+#             */
/*   Updated: 2021/06/16 16:50:59 by cgutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

/*
	BONUS:
	· Un fractal diferente mas.
	· Adicionalmente al zoom: moverse con flechas. (WASD También).
	· Haz que el rango de color cambie.
	PROPIOS:
	· Cambiar iteraciones con + -
	· Cambiar formas en Julia con 1 2 3 4
	· Cambiar entre Fractales con Enter
	//TODO: Usar al menos unos pocos colores para mostrar profundidad de cada
	fractal
	// TODO: ignorar > 2
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

static void	print_ignored_args(int argc, char **argv)
{
	int	i;

	i = 2;
	if (argc > 2)
	{
		printf("The following arguments will be ignored:\n");
		while (i < argc)
		{
			printf(RED "\t·%s\n" RESET, argv[i]);
			i++;
		}
	}
}

static void	good_args(char **argv, t_fractol *fractol, int argc)
{
	if (!ft_strcmp("julia", argv[1]) && !ft_strcmp("mandelbrot", argv[1]))
	{
		printf("Error\nUnknown set: " RED "\"%s\"" RESET
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
	print_ignored_args(argc, argv);
	setup(fractol);
}

int	main(int argc, char **argv)
{
	t_fractol	fractol;

	ft_bzero(&fractol, sizeof(t_fractol));
	fractol.bonus = 0;
	if (argc < 2)
	{
		printf("Error\n" RED "A set is needed" RESET
			"\nTry with:\n\t·julia\n\t·mandelbrot\n");
		exit(1);
	}
	if (argc >= 2)
	{
		if (!(ft_strcmp("./fractol", argv[0]) || ft_strcmp("fractol", argv[0])))
			print_simple_errors("Executable must be a \"fractol\" file");
		good_args(argv, &fractol, argc);
	}
	return (0);
}
