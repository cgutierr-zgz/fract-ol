/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rc_sprites.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgutierr <cgutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 15:33:30 by cgutierr          #+#    #+#             */
/*   Updated: 2021/04/23 09:31:42 by cgutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

static void	sprite_bucle(t_cub *cub, int *y, int *d)
{
	cub->rc_spr.texx = (int)(256 * (cub->rc_spr.stripe
				- (-cub->rc_spr.spriteWidth / 2 + cub->rc_spr.spr_screenx))
			* cub->txtrs.width[4] / cub->rc_spr.spriteWidth) / 256;
	if (cub->rc_spr.transformy > 0 && cub->rc_spr.stripe > 0
		&& cub->rc_spr.stripe < cub->screen.x
		&& cub->rc_spr.transformy < cub->data.zbuffer[cub->rc_spr.stripe])
	{
		*y = cub->rc_spr.drawstarty;
		while (*y < cub->rc_spr.drawendy)
		{
			*d = (*y) * 256 - cub->screen.y
				* 128 + cub->rc_spr.spr_height * 128;
			cub->rc_spr.texy = ((*d * cub->txtrs.height[4])
					/ cub->rc_spr.spr_height) / 256;
			cub->data.color = my_pixel_get(&cub->txtrs.img[4],
					cub->rc_spr.texx, cub->rc_spr.texy);
			if ((cub->data.color & 0x00FFFFFF) != 0)
				my_pixel_put(&cub->txtrs.main_img, cub->rc_spr.stripe,
					*y, cub->data.color);
			*y += 1;
		}
	}
}

static void	sprite_height_and_width(t_cub *cub)
{
	cub->rc_spr.spr_height = abs((int)(cub->screen.y
				/ (cub->rc_spr.transformy)));
	cub->rc_spr.drawstarty = -cub->rc_spr.spr_height / 2 + cub->screen.y / 2;
	if (cub->rc_spr.drawstarty < 0)
		cub->rc_spr.drawstarty = 0;
	cub->rc_spr.drawendy = cub->rc_spr.spr_height / 2 + cub->screen.y / 2;
	if (cub->rc_spr.drawendy >= cub->screen.y)
		cub->rc_spr.drawendy = cub->screen.y - 1;
	cub->rc_spr.spriteWidth = abs((int)(cub->screen.y
				/ (cub->rc_spr.transformy)));
	cub->rc_spr.drawstartx = -cub->rc_spr.spriteWidth
		/ 2 + cub->rc_spr.spr_screenx;
	if (cub->rc_spr.drawstartx < 0)
		cub->rc_spr.drawstartx = 0;
	cub->rc_spr.drawendx = cub->rc_spr.spriteWidth
		/ 2 + cub->rc_spr.spr_screenx;
	if (cub->rc_spr.drawendx >= cub->screen.x)
		cub->rc_spr.drawendx = cub->screen.x - 1;
}

static void	sprite_relative_to_cam(t_cub *cub, t_sprite **sprite_actual)
{
	cub->rc_spr.spritex = (*sprite_actual)->x - cub->raycast.posx + 0.5;
	cub->rc_spr.spritey = (*sprite_actual)->y - cub->raycast.posy + 0.5;
	cub->rc_spr.invdet = 1.0 / (cub->raycast.planex * cub->raycast.diry
			- cub->raycast.dirx * cub->raycast.planey);
	cub->rc_spr.transformx = cub->rc_spr.invdet * (cub->raycast.diry
			* cub->rc_spr.spritex - cub->raycast.dirx * cub->rc_spr.spritey);
	cub->rc_spr.transformy = cub->rc_spr.invdet * (-cub->raycast.planey
			* cub->rc_spr.spritex + cub->raycast.planex * cub->rc_spr.spritey);
	cub->rc_spr.spr_screenx = (int)((cub->screen.x / 2) * (1
				+ cub->rc_spr.transformx / cub->rc_spr.transformy));
}

void	sprites(t_cub *cub)
{
	t_list		*sopita;
	t_sprite	*sprite_actual;
	int			i;
	int			y;
	int			d;

	i = 0;
	sopita = cub->txtrs.sprite_list;
	while (i < cub->txtrs.num_sprites)
	{
		sprite_actual = sopita->content;
		sprite_relative_to_cam(cub, &sprite_actual);
		sprite_height_and_width(cub);
		cub->rc_spr.stripe = cub->rc_spr.drawstartx;
		while (cub->rc_spr.stripe < cub->rc_spr.drawendx)
		{
			sprite_bucle(cub, &y, &d);
			cub->rc_spr.stripe++;
		}
		sopita = sopita->next;
		i++;
	}
}
