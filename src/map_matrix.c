/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_matrix.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgutierr <cgutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 16:13:16 by cgutierr          #+#    #+#             */
/*   Updated: 2021/04/27 17:36:55 by cgutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

/*
** Bibidibop
*/

static void	error_memory(int j, t_cub *cub)
{
	print_simple_errors("Couldn't allocate memory");
	j -= 1;
	while (j >= 0)
	{
		free(cub->map.map_matrix[j]);
		j--;
	}
	free(cub->map.map_matrix);
	free_content_cub(cub);
	ft_lstclear(&cub->map.map_list, clear_matrix_content);
	exit(1);
}

static void	store_sprites(t_cub *cub, int z)
{
	t_sprite	*sprite;

	sprite = malloc(sizeof(t_sprite));
	cub->map.map_matrix[cub->map.matrix_act][z] = '2';
	sprite->texture = 4;
	sprite->x = cub->map.matrix_act;
	sprite->y = z;
	cub->txtrs.num_sprites++;
	ft_lstadd_back(&cub->txtrs.sprite_list, ft_lstnew(sprite));
}

/*
** Depending on the info we store it accordingly
*/

static void	create_matrix(t_cub *cub, char *c)
{
	int	z;

	z = 0;
	while (c[z] && z < cub->map.max_len)
	{
		if (c[z] == '0')
			cub->map.map_matrix[cub->map.matrix_act][z] = '0';
		else if (c[z] == '1')
			cub->map.map_matrix[cub->map.matrix_act][z] = '1';
		else if (c[z] == '2')
			store_sprites(cub, z);
		else if (c[z] == 'N' || c[z] == 'S' || c[z] == 'E' || c[z] == 'W')
			cub->map.map_matrix[cub->map.matrix_act][z] = '0';
		else if (c[z] == ' ')
			cub->map.map_matrix[cub->map.matrix_act][z] = ' ';
		z++;
	}
	while (z < cub->map.max_len)
	{
		cub->map.map_matrix[cub->map.matrix_act][z] = ' ';
		z++;
	}
	cub->map.map_matrix[cub->map.matrix_act][z] = '\0';
}

/*
** We do some mallocs for the matrix
*/

void	fill_map_matrix(t_cub *cub, void *content)
{
	char	*c;
	int		j;

	c = content;
	if (!cub->map.matrix_mall)
	{
		cub->map.map_matrix = malloc(sizeof(char *) * (cub->map.map_lines + 1));
		if (!cub->map.map_matrix)
			error_memory(-1, cub);
		j = 0;
		while (j < cub->map.map_lines)
		{
			cub->map.map_matrix[j] = malloc(sizeof(char)
					* (cub->map.max_len + 1));
			if (!cub->map.map_matrix[j])
				error_memory(j, cub);
			j++;
		}
		cub->map.map_matrix[j] = NULL;
		cub->map.matrix_mall = 1;
	}
	create_matrix(cub, c);
	cub->map.matrix_act++;
}
