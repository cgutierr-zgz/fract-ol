/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_map_no.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgutierr <cgutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 23:19:19 by cgutierr          #+#    #+#             */
/*   Updated: 2021/03/25 13:36:18 by cgutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

void	handle_map_no(t_cub *cub, char **content, int n_words)
{
	if (is_bit_set(cub->elems, NO))
	{
		print_errors(cub, "North texture was already set");
		aux(cub, content, n_words);
	}
	if (n_words == 2)
	{
		cub->map_d.no_fd = open_texture(content[1]);
		if (cub->map_d.no_fd < 0)
		{
			print_errors(cub, "Couldn't open texture for \"NO\"");
			aux(cub, content, n_words);
		}
		cub->map_d.no_txt = ft_strdup(content[1]);
		cub->elems = set_bit(cub->elems, NO);
	}
	else
	{
		print_errors(cub, "Invalid params for \"NO\"");
		aux(cub, content, n_words);
	}
}
