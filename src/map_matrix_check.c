/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_matrix_check.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgutierr <cgutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 00:48:54 by cgutierr          #+#    #+#             */
/*   Updated: 2021/04/26 18:35:15 by cgutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

/*
** We change the char for x for later showing the errors
*/

static void	map_ko_matrix(t_cub *cub, int j, int j2)
{
	cub->map.map_matrix[j][j2] = 'x';
	cub->map.map_ko = 1;
}

/*
** We check if the map is closed pt2
*/

static void	check_aux(t_cub *cub, int j, int j2, int x)
{
	if (x)
	{
		if (j2 == 0 && ft_strchr("02", cub->map.map_matrix[j][j2]))
			map_ko_matrix(cub, j, j2);
		if (j == cub->map.map_lines - 1
			&& ft_strchr("02", cub->map.map_matrix[j][j2]))
			map_ko_matrix(cub, j, j2);
	}
	else
	{
		if ((cub->map.map_matrix[j][j2] == ' '
			&& ft_strchr("02", cub->map.map_matrix[j - 1][j2]))
			|| (cub->map.map_matrix[j - 1][j2] == ' '
			&& ft_strchr("02", cub->map.map_matrix[j][j2]))
			|| (cub->map.map_matrix[j][j2] == '0')
			|| (cub->map.map_matrix[j][j2] == '2'))
			map_ko_matrix(cub, j, j2);
	}
}

/*
** We check if the map is closed
*/

static void	bucle(int j, int j2, t_cub *cub)
{
	check_aux(cub, j, j2, 1);
	if (j2 == cub->map.max_len - 1)
		check_aux(cub, j, j2, 0);
	else if (((cub->map.map_matrix[j][j2] == '1')
		&& (ft_strchr("02", cub->map.map_matrix[j][j2 + 1]))
		&& (cub->map.map_matrix[j - 1][j2] == ' '))
		|| ((cub->map.map_matrix[j][j2] == '1')
		&& (ft_strchr("02", cub->map.map_matrix[j - 1][j2]))
		&& (cub->map.map_matrix[j][j2 + 1] == ' ')));
	else if ((cub->map.map_matrix[j][j2] == ' '
		&& ft_strchr("02", cub->map.map_matrix[j][j2 + 1]))
		|| (cub->map.map_matrix[j][j2] == ' '
		&& ft_strchr("02", cub->map.map_matrix[j - 1][j2]))
		|| (cub->map.map_matrix[j][j2 + 1] == ' '
		&& ft_strchr("02", cub->map.map_matrix[j][j2]))
		|| (cub->map.map_matrix[j][j2 + 1] == ' '
		&& ft_strchr("02", cub->map.map_matrix[j - 1][j2]))
		|| (cub->map.map_matrix[j - 1][j2] == ' '
		&& ft_strchr("02", cub->map.map_matrix[j][j2]))
		|| (cub->map.map_matrix[j - 1][j2] == ' '
		&& ft_strchr("02", cub->map.map_matrix[j][j2 + 1])))
		map_ko_matrix(cub, j, j2);
}

/*
** Pretty cool function to show the user the errors on the map
*/

static void	print_map_error(t_cub *cub)
{
	int	z;
	int	z2;

	z = 0;
	printf("Error\n");
	printf(W_B_RED "Invalid map" RESET);
	printf("\n\nFix the following errors:\n\n" RESET);
	while (z < cub->map.map_lines)
	{
		z2 = 0;
		while (z2 < cub->map.max_len)
		{
			if (cub->map.map_matrix[z][z2] == 'x')
				printf(W_B_RED " " RESET);
			else
				printf("%c", cub->map.map_matrix[z][z2]);
			z2++;
		}
		printf("\n");
		z++;
	}
}

/*
** The heart to check if our matrix is valid
*/

void	check_matrix_ok(t_cub *cub)
{
	int	j;
	int	j2;

	j = 1;
	while (j < cub->map.map_lines)
	{
		j2 = 0;
		while (j2 < cub->map.max_len)
		{
			bucle(j, j2, cub);
			j2++;
		}
		j++;
	}
	if (cub->map.map_ko)
	{
		print_map_error(cub);
		free_content_map_matrix(cub);
		free_content_cub(cub);
		exit(1);
	}
}
