/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcular_distancias.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgutierr <cgutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 12:55:07 by cgutierr          #+#    #+#             */
/*   Updated: 2021/04/23 09:31:00 by cgutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

void	calcular_distancia(t_cub *cub, void *content)
{
	t_sprite	*sapato;

	sapato = content;
	sapato->dist = pow(sapato->x - cub->raycast.posx, 2)
		+ pow(sapato->y - cub->raycast.posy, 2);
}
