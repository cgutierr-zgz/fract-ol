/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rc_wallcasting.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgutierr <cgutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 16:15:58 by cgutierr          #+#    #+#             */
/*   Updated: 2021/04/23 09:31:42 by cgutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

static void	calculate_step_and_sidedist(t_cub *cub)
{
	if (cub->data.raydirx < 0)
	{
		cub->data.stepx = -1;
		cub->data.sidedistx = (cub->raycast.posx - cub->data.mapx)
			* cub->data.deltadistx;
	}
	else
	{
		cub->data.stepx = 1;
		cub->data.sidedistx = (cub->data.mapx + 1.0 - cub->raycast.posx)
			* cub->data.deltadistx;
	}
	if (cub->data.raydiry < 0)
	{
		cub->data.stepy = -1;
		cub->data.sidedisty = (cub->raycast.posy - cub->data.mapy)
			* cub->data.deltaDistY;
	}
	else
	{
		cub->data.stepy = 1;
		cub->data.sidedisty = (cub->data.mapy + 1.0 - cub->raycast.posy)
			* cub->data.deltaDistY;
	}
}

static void	perform_dda(t_cub *cub)
{
	while (cub->data.hit == 0)
	{
		if (cub->data.sidedistx < cub->data.sidedisty)
		{
			cub->data.sidedistx += cub->data.deltadistx;
			cub->data.mapx += cub->data.stepx;
			cub->data.side = 0;
		}
		else
		{
			cub->data.sidedisty += cub->data.deltaDistY;
			cub->data.mapy += cub->data.stepy;
			cub->data.side = 1;
		}
		if (cub->map.map_matrix[cub->data.mapx][cub->data.mapy] == '1')
			cub->data.hit = 1;
	}
	if (cub->data.side == 0)
		cub->data.perpwalldist = (cub->data.mapx - cub->raycast.posx
				+ (1 - cub->data.stepx) / 2) / cub->data.raydirx;
	else
		cub->data.perpwalldist = (cub->data.mapy - cub->raycast.posy
				+ (1 - cub->data.stepy) / 2) / cub->data.raydiry;
	cub->data.lineheight = (int)(cub->screen.y / cub->data.perpwalldist);
	cub->data.drawstart = -cub->data.lineheight / 2 + cub->screen.y / 2;
}

static void	textures(t_cub *cub)
{
	if (cub->data.drawstart < 0)
		cub->data.drawstart = 0;
	cub->data.drawend = cub->data.lineheight / 2 + cub->screen.y / 2;
	if (cub->data.drawend >= cub->screen.y)
		cub->data.drawend = cub->screen.y - 1;
	cub->data.texnum
		= ((cub->map.map_matrix[cub->data.mapx][cub->data.mapy]) - '0') - 1;
	if (cub->data.side == 0 && cub->data.raydirx > 0)
		cub->data.texnum = 1;
	else if (cub->data.side == 0 && cub->data.raydirx < 0)
		cub->data.texnum = 0;
	else if (cub->data.side == 1 && cub->data.raydiry > 0)
		cub->data.texnum = 3;
	else
		cub->data.texnum = 2;
	if (cub->data.side == 0)
		cub->data.wallx = cub->raycast.posy + cub->data.perpwalldist
			* cub->data.raydiry;
	else
		cub->data.wallx = cub->raycast.posx + cub->data.perpwalldist
			* cub->data.raydirx;
	cub->data.wallx -= floor((cub->data.wallx));
}

static void	tex_position(t_cub *cub, int *draw)
{
	cub->data.texx = (int)(cub->data.wallx
			* (double)(cub->txtrs.width[cub->data.texnum]));
	if (cub->data.side == 0 && cub->data.raydirx > 0)
		cub->data.texx
			= cub->txtrs.width[cub->data.texnum] - cub->data.texx - 1;
	if (cub->data.side == 1 && cub->data.raydiry < 0)
		cub->data.texx
			= cub->txtrs.width[cub->data.texnum] - cub->data.texx - 1;
	cub->data.step
		= 1.0 * (cub->txtrs.height[cub->data.texnum]) / cub->data.lineheight;
	cub->data.texpos = (cub->data.drawstart - cub->screen.y / 2
			+ cub->data.lineheight / 2) * cub->data.step;
	*draw = 0;
}

void	wallcasting(t_cub *cub, int x)
{
	int	draw;

	cub->data.camerax = 2 * x / (double)cub->screen.x - 1;
	cub->data.raydirx
		= cub->raycast.dirx + cub->raycast.planex * cub->data.camerax;
	cub->data.raydiry
		= cub->raycast.diry + cub->raycast.planey * cub->data.camerax;
	cub->data.mapx = (int)cub->raycast.posx;
	cub->data.mapy = (int)cub->raycast.posy;
	cub->data.deltadistx = fabs(1 / cub->data.raydirx);
	cub->data.deltaDistY = fabs(1 / cub->data.raydiry);
	cub->data.hit = 0;
	calculate_step_and_sidedist(cub);
	perform_dda(cub);
	textures(cub);
	tex_position(cub, &draw);
	draw_walls(cub, &draw, x);
	cub->data.zbuffer[x] = cub->data.perpwalldist;
}
