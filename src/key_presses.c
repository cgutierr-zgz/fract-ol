/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_presses.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgutierr <cgutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 23:13:50 by cgutierr          #+#    #+#             */
/*   Updated: 2021/04/23 09:31:42 by cgutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

void	key_w(t_cub *cub)
{
	if (cub->map.map_matrix[(int)(cub->raycast.posx + cub->raycast.dirx
			* cub->mov.mov_s)][(int)(cub->raycast.posy)] != '1'
		&& cub->map.map_matrix[(int)(cub->raycast.posx + cub->raycast.dirx
			* cub->mov.mov_s)][(int)(cub->raycast.posy)] != '2')
		cub->raycast.posx += cub->raycast.dirx * cub->mov.mov_s;
	if (cub->map.map_matrix[(int)(cub->raycast.posx)]
		[(int)(cub->raycast.posy + cub->raycast.diry * cub->mov.mov_s)] != '1'
		&& cub->map.map_matrix[(int)(cub->raycast.posx)]
		[(int)(cub->raycast.posy + cub->raycast.diry * cub->mov.mov_s)] != '2')
		cub->raycast.posy += cub->raycast.diry * cub->mov.mov_s;
}

void	key_a(t_cub *cub)
{
	if (cub->map.map_matrix[(int)(cub->raycast.posx - cub->raycast.planex
			* cub->mov.mov_s)][(int)(cub->raycast.posy)] != '1'
		&& cub->map.map_matrix[(int)(cub->raycast.posx - cub->raycast.planex
			* cub->mov.mov_s)][(int)(cub->raycast.posy)] != '2')
		cub->raycast.posx -= cub->raycast.planex * cub->mov.mov_s;
	if (cub->map.map_matrix[(int)(cub->raycast.posx)][(int)(cub->raycast.posy
			- cub->raycast.planey * cub->mov.mov_s)] != '1'
		&& cub->map.map_matrix[(int)(cub->raycast.posx)][(int)(cub->raycast.posy
			- cub->raycast.planey * cub->mov.mov_s)] != '2')
		cub->raycast.posy -= cub->raycast.planey * cub->mov.mov_s;
}

void	key_s(t_cub *cub)
{
	if (cub->map.map_matrix[(int)(cub->raycast.posx - cub->raycast.dirx
			* cub->mov.mov_s)][(int)(cub->raycast.posy)] != '1'
		&& cub->map.map_matrix[(int)(cub->raycast.posx - cub->raycast.dirx
			* cub->mov.mov_s)][(int)(cub->raycast.posy)] != '2')
		cub->raycast.posx -= cub->raycast.dirx * cub->mov.mov_s;
	if (cub->map.map_matrix[(int)(cub->raycast.posx)]
		[(int)(cub->raycast.posy - cub->raycast.diry * cub->mov.mov_s)] != '1'
		&& cub->map.map_matrix[(int)(cub->raycast.posx)]
		[(int)(cub->raycast.posy - cub->raycast.diry * cub->mov.mov_s)] != '2')
		cub->raycast.posy -= cub->raycast.diry * cub->mov.mov_s;
}

void	key_d(t_cub *cub)
{
	if (cub->map.map_matrix[(int)(cub->raycast.posx + cub->raycast.planex
			* cub->mov.mov_s)][(int)(cub->raycast.posy)] != '1'
		&& cub->map.map_matrix[(int)(cub->raycast.posx + cub->raycast.planex
			* cub->mov.mov_s)][(int)(cub->raycast.posy)] != '2')
		cub->raycast.posx += cub->raycast.planex * cub->mov.mov_s;
	if (cub->map.map_matrix[(int)(cub->raycast.posx)][(int)(cub->raycast.posy
			+ cub->raycast.planey * cub->mov.mov_s)] != '1'
		&& cub->map.map_matrix[(int)(cub->raycast.posx)][(int)(cub->raycast.posy
			+ cub->raycast.planey * cub->mov.mov_s)] != '2')
		cub->raycast.posy += cub->raycast.planey * cub->mov.mov_s;
}
