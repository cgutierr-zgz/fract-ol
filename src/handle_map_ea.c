/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_map_ea.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgutierr <cgutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 23:19:19 by cgutierr          #+#    #+#             */
/*   Updated: 2021/03/25 13:40:51 by cgutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

void	close_fds(t_cub *cub)
{
	close(cub->fd);
	close(cub->map_d.s_fd);
	close(cub->map_d.ea_fd);
	close(cub->map_d.we_fd);
	close(cub->map_d.no_fd);
	close(cub->map_d.so_fd);
}

void	handle_map_ea(t_cub *cub, char **content, int n_words)
{
	if (is_bit_set(cub->elems, EA))
	{
		print_errors(cub, "East texture was already set");
		aux(cub, content, n_words);
	}
	if (n_words == 2)
	{
		cub->map_d.ea_fd = open_texture(content[1]);
		if (cub->map_d.ea_fd < 0)
		{
			print_errors(cub, "Couldn't open texture for \"EA\"");
			aux(cub, content, n_words);
		}
		cub->map_d.ea_txt = ft_strdup(content[1]);
		cub->elems = set_bit(cub->elems, EA);
	}
	else
	{
		print_errors(cub, "Invalid params for \"EA\"");
		aux(cub, content, n_words);
	}
}
