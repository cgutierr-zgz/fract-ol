/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_map_we.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgutierr <cgutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 23:19:19 by cgutierr          #+#    #+#             */
/*   Updated: 2021/03/25 13:36:57 by cgutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

void	handle_map_we(t_cub *cub, char **content, int n_words)
{
	if (is_bit_set(cub->elems, WE))
	{
		print_errors(cub, "West texture was already set");
		aux(cub, content, n_words);
	}
	if (n_words == 2)
	{
		cub->map_d.we_fd = open_texture(content[1]);
		if (cub->map_d.we_fd < 0)
		{
			print_errors(cub, "Couldn't open texture for \"WE\"");
			aux(cub, content, n_words);
		}
		cub->map_d.we_txt = ft_strdup(content[1]);
		cub->elems = set_bit(cub->elems, WE);
	}
	else
	{
		print_errors(cub, "Invalid params for \"WE\"");
		aux(cub, content, n_words);
	}
}
