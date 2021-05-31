/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_map_so.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgutierr <cgutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 23:19:19 by cgutierr          #+#    #+#             */
/*   Updated: 2021/03/25 13:36:49 by cgutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

void	handle_map_so(t_cub *cub, char **content, int n_words)
{
	if (is_bit_set(cub->elems, SO))
	{
		print_errors(cub, "South texture was already set");
		aux(cub, content, n_words);
	}
	if (n_words == 2)
	{
		cub->map_d.so_fd = open_texture(content[1]);
		if (cub->map_d.so_fd < 0)
		{
			print_errors(cub, "Couldn't open texture for \"SO\"");
			aux(cub, content, n_words);
		}
		cub->map_d.so_txt = ft_strdup(content[1]);
		cub->elems = set_bit(cub->elems, SO);
	}
	else
	{
		print_errors(cub, "Invalid params for \"SO\"");
		aux(cub, content, n_words);
	}
}
