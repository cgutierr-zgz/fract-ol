/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgutierr <cgutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 19:48:28 by cgutierr          #+#    #+#             */
/*   Updated: 2021/05/31 14:16:07 by cgutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void	good_args(char **argv, t_fractol *fractol)
{
	if (!ft_strcmp("julia", argv[1]) && !ft_strcmp("mandelbrot", argv[1]))
	{
		printf("Error\nUnknown command: ");
		printf(W_B_RED "\"%s\"\n" RESET, argv[1]);
		printf("Try with:\n\t·julia\n\t·mandelbrot\n");
		exit(1);
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
}

int	main(int argc, char **argv)
{
	t_fractol	fractol;

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
