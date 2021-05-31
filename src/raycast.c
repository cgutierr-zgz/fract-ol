/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgutierr <cgutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 17:09:59 by cgutierr          #+#    #+#             */
/*   Updated: 2021/04/23 09:37:34 by cgutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

/*
** Depending on the orientation we change the value and some info
*/

static void	orientation(t_cub *cub)
{
	cub->raycast.dirx = -1;
	cub->raycast.diry = 0;
	cub->mov.rot_s = 0.05;
	cub->mov.mov_s = 0.05;
	if (cub->map.player_o == 'S')
	{
		cub->raycast.planey = -0.66;
		cub->raycast.dirx = 1;
	}
	else if (cub->map.player_o == 'E')
	{
		cub->raycast.dirx = 0;
		cub->raycast.diry = 1;
		cub->raycast.planex = 0.66;
		cub->raycast.planey = 0;
	}
	else if (cub->map.player_o == 'W')
	{
		cub->raycast.dirx = 0;
		cub->raycast.diry = -1;
		cub->raycast.planex = -0.66;
		cub->raycast.planey = 0;
	}
}

/*
** We set the player orientation and position and some more info
** Initialization of the window and the hooks (Keys + main Raycast)
*/

static void	hooks(t_cub *cub)
{
	cub->data.zbuffer = malloc(sizeof(double *) * cub->screen.x);
	if (!cub->data.zbuffer)
	{
		print_simple_errors("Couldn't allocate enough memory");
		free_content_cub(cub);
		free_content_map_matrix(cub);
		ft_lstclear(&cub->txtrs.sprite_list, clear_matrix_content);
		exit(1);
	}
	if (!cub->save_first)
	{
		mlx_hook(cub->window, KEY_PRESS, 1L << 0, keys, cub);
		mlx_hook(cub->window, DESTROY_NOTIFY, 0L, destroy, cub);
		mlx_hook(cub->window, KEY_RELEASE, 1L << 1, key_release, cub);
		mlx_loop_hook(cub->mlx, raycast, cub);
		mlx_loop(cub->mlx);
	}
	else
		raycast(cub);
}

void	cub_tresd(t_cub *cub)
{
	cub->raycast.posx = (double)cub->map.player_pos.x - 0.5;
	cub->raycast.posy = (double)cub->map.player_pos.y - 0.5;
	cub->raycast.planex = 0;
	cub->raycast.planey = 0.66;
	orientation(cub);
	cub->window
		= mlx_new_window(cub->mlx, cub->screen.x, cub->screen.y, "cub3D");
	if (!(cub->window))
	{
		print_simple_errors("Something went wrong trying to open a window");
		free_content_cub(cub);
		free_content_map_matrix(cub);
		ft_lstclear(&cub->txtrs.sprite_list, clear_matrix_content);
		exit(1);
	}
	cub->txtrs.main_img.img = mlx_new_image(cub->mlx,
			cub->screen.x, cub->screen.y);
	cub->txtrs.main_img.addr = mlx_get_data_addr(cub->txtrs.main_img.img,
			&cub->txtrs.main_img.bpp, &cub->txtrs.main_img.line_l,
			&cub->txtrs.main_img.endian);
	cub->map_d.ceiling.trgb = create_trgb(0, cub->map_d.ceiling.r,
			cub->map_d.ceiling.g, cub->map_d.ceiling.b);
	cub->map_d.floor.trgb = create_trgb(0, cub->map_d.floor.r,
			cub->map_d.floor.g, cub->map_d.floor.b);
	hooks(cub);
}

/*
** cub->txtrs.main_img.img
**		= mlx_new_image(cub->mlx, cub->screen.x, cub->screen.y);
**	cub->txtrs.main_img.addr
**		= mlx_get_data_addr(cub->txtrs.main_img.img, &cub->txtrs.main_img.bpp,
**			&cub->txtrs.main_img.line_l, &cub->txtrs.main_img.endian);
*/
