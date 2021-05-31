/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgutierr <cgutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 19:48:28 by cgutierr          #+#    #+#             */
/*   Updated: 2021/05/31 13:19:58 by cgutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

/*
** If there was a problem reading the file we handle the error

static void	error_read(t_cub *cub)
{
	free_content_cub(cub);
	ft_lstclear(&cub->map.map_list, clear_matrix_content);
	print_simple_errors("An error ocurred reading the file");
	exit(1);
}
*/
/*
** Aux function to get rid of the norm


static int	reading(int *n, t_cub *cub, char **line)
{
	*n = get_next_line(cub->fd, line);
	return (*n);
}
*/
/*
** We loop with get_next_line trogh the given fd storing the data depending on
**	wich point we are
** If everything it's OK -> start_graphics


void	read_file(t_cub *cub)
{
	char	*line;
	int		n;

	while (reading(&n, cub, &line) >= 0)
	{
		cub->actual_line++;
		if (line[0] == '\0')
		{
			if (cub->is_map)
				cub->end_map = 1;
			free(line);
		}
		else if (cub->elems != 255)
			parse_specificators(cub, line);
		else
			parse_map(line, cub);
		if (n == 0)
			break ;
	}
	if (n == -1)
		error_read(cub);
	start_graphics(cub);
}
*/

static void	good_args(char **argv, t_cub *fractol)
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
}

int	main(int argc, char **argv)
{
	t_cub	fractol;

	ft_bzero(&fractol, sizeof(t_cub));
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
