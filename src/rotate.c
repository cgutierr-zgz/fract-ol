/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgutierr <cgutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 13:32:56 by cgutierr          #+#    #+#             */
/*   Updated: 2021/04/23 09:31:42 by cgutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

void	key_left(t_cub *cub)
{
	double	olddirx;
	double	oldplanex;

	olddirx = cub->raycast.dirx;
	cub->raycast.dirx = cub->raycast.dirx
		* cos(cub->mov.rot_s) - cub->raycast.diry * sin(cub->mov.rot_s);
	cub->raycast.diry = olddirx
		* sin(cub->mov.rot_s) + cub->raycast.diry * cos(cub->mov.rot_s);
	oldplanex = cub->raycast.planex;
	cub->raycast.planex = cub->raycast.planex
		* cos(cub->mov.rot_s) - cub->raycast.planey * sin(cub->mov.rot_s);
	cub->raycast.planey = oldplanex
		* sin(cub->mov.rot_s) + cub->raycast.planey * cos(cub->mov.rot_s);
}

void	key_right(t_cub *cub)
{
	double	olddirx;
	double	oldplanex;

	olddirx = cub->raycast.dirx;
	cub->raycast.dirx = cub->raycast.dirx
		* cos(-cub->mov.rot_s) - cub->raycast.diry * sin(-cub->mov.rot_s);
	cub->raycast.diry = olddirx
		* sin(-cub->mov.rot_s) + cub->raycast.diry * cos(-cub->mov.rot_s);
	oldplanex = cub->raycast.planex;
	cub->raycast.planex = cub->raycast.planex
		* cos(-cub->mov.rot_s) - cub->raycast.planey * sin(-cub->mov.rot_s);
	cub->raycast.planey = oldplanex
		* sin(-cub->mov.rot_s) + cub->raycast.planey * cos(-cub->mov.rot_s);
}

void	rotate_x(t_cub *cub, double force)
{
	double	olddirx;
	double	oldplanex;

	olddirx = cub->raycast.dirx;
	cub->raycast.dirx = cub->raycast.dirx
		* cos(-force) - cub->raycast.diry * sin(-force);
	cub->raycast.diry = olddirx
		* sin(-force) + cub->raycast.diry * cos(-force);
	oldplanex = cub->raycast.planex;
	cub->raycast.planex = cub->raycast.planex
		* cos(-force) - cub->raycast.planey * sin(-force);
	cub->raycast.planey = oldplanex
		* sin(-force) + cub->raycast.planey * cos(-force);
}

/* Efecto TP

	double	oldplaney;
	
	oldplaney = cub->raycast.planey;
	cub->raycast.planey = cub->raycast.planey
		* cos(-force) - cub->raycast.planex * sin(-force);
	cub->raycast.planex = oldplaney
		* sin(-force) + cub->raycast.planey * cos(-force);

		
void	TELEPORT_EFFECT(t_cub *cub, double force)
{
	double	olddiry;
	double	oldplaney;

	olddiry = cub->raycast.diry;
	cub->raycast.diry = cub->raycast.diry
		* cos(-force) - cub->raycast.dirx * sin(-force);
	cub->raycast.dirx = olddiry
		* sin(-force) + cub->raycast.dirx * cos(-force);
	oldplaney = cub->raycast.planey;
	cub->raycast.planey = cub->raycast.planey
		* cos(-force) - cub->raycast.planex * sin(-force);
	cub->raycast.planex = oldplaney
		* sin(-force) + cub->raycast.planey * cos(-force);
}
*/
