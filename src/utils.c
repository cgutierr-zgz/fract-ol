/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgutierr <cgutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 17:59:25 by cgutierr          #+#    #+#             */
/*   Updated: 2021/03/25 13:11:05 by cgutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

void	free_content_map_matrix(t_cub *cub)
{
	int	j;

	j = 0;
	while (j < cub->map.map_lines)
	{
		free(cub->map.map_matrix[j]);
		j++;
	}
	free(cub->map.map_matrix);
}

void	free_content_cub(t_cub *cub)
{
	if (is_bit_set(cub->elems, NO))
		free(cub->map_d.no_txt);
	if (is_bit_set(cub->elems, SO))
		free(cub->map_d.so_txt);
	if (is_bit_set(cub->elems, WE))
		free(cub->map_d.we_txt);
	if (is_bit_set(cub->elems, EA))
		free(cub->map_d.ea_txt);
	if (is_bit_set(cub->elems, S))
		free(cub->map_d.s_txt);
}

int	open_texture(char *texture)
{
	int	fd;

	fd = open(texture, O_RDONLY);
	return (fd);
}

void	free_content_array(char **content, int n_words)
{
	int	i;

	i = 0;
	while (i < n_words)
	{
		free(content[i]);
		i++;
	}
	free(content);
}

void	aux(t_cub *cub, char **content, int n_words)
{
	free_content_array(content, n_words);
	free_content_cub(cub);
	exit(1);
}
