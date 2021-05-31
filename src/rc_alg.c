/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rc_alg.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgutierr <cgutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 19:22:31 by cgutierr          #+#    #+#             */
/*   Updated: 2021/04/26 18:28:00 by cgutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

/*
** 	// // FUMADA ->         cub->data.color
** =  my_pixel_get(&cub->txtrs.main_img,  texx, texy);
**   texture[texnum][cub->txtrs.height[texnum] * texy + texx];
** 	// FUMADA 2 _> cub->data.color
** =  my_pixel_get(&cub->txtrs.main_img, texy, texx);
** 	//  addres + altura * y + x
** 	if (cub->map.map_matrix[cub->data.mapx][cub->data.mapy] == '1')
** 		cub->data.color = 0x00FF0000;
** 	else if (cub->map.map_matrix[cub->data.mapx][cub->data.mapy] == '2')
** 		cub->data.color = 0x0000FF00;
** 	else
**  		cub->data.color = 0x00FFFFFF;
** 	if (cub->data.side == 1)
** 		cub->data.color = cub->data.color / 2;
*/

static void	raycast_initializaction(t_cub *cub)
{
	cub->data.hit = 0;
	cub->data.mapx = (int)cub->raycast.posx;
	cub->data.mapy = (int)cub->raycast.posy;
	if (cub->mov.down)
		key_s(cub);
	if (cub->mov.up)
		key_w(cub);
	if (cub->mov.left)
		key_a(cub);
	if (cub->mov.right)
		key_d(cub);
	if (cub->mov.rotate_left)
		key_left(cub);
	if (cub->mov.rotate_right)
		key_right(cub);
	iter_cub_list(cub, cub->txtrs.sprite_list, calcular_distancia);
	bubble_sort(cub->txtrs.sprite_list);
	mlx_sync(MLX_SYNC_WIN_CMD_COMPLETED, cub->window);
}

static void	print_pointer(t_cub *cub)
{
	int	i;

	i = 0;
	i = cub->fd;
	while (i < 10)
	{
		my_pixel_put(&cub->txtrs.main_img, (cub->screen.x
				/ 2), (cub->screen.y / 2), 321321);
		my_pixel_put(&cub->txtrs.main_img, (cub->screen.x
				/ 2), (cub->screen.y / 2) + i, 321321);
		my_pixel_put(&cub->txtrs.main_img, (cub->screen.x
				/ 2), (cub->screen.y / 2) - i, 321321);
		my_pixel_put(&cub->txtrs.main_img, (cub->screen.x
				/ 2) + i, (cub->screen.y / 2), 321321);
		my_pixel_put(&cub->txtrs.main_img, (cub->screen.x
				/ 2) - i, (cub->screen.y / 2), 321321);
		i++;
	}
}

int	raycast(t_cub *cub)
{
	int	x;

	x = 0;
	if (cub->mov.delay + 1 == UINT_MAX)
		cub->mov.delay = 0;
	cub->mov.delay++;
	raycast_initializaction(cub);
	while (x < cub->screen.x)
	{
		wallcasting(cub, x);
		x++;
	}
	sprites(cub);
	print_pointer(cub);
	mlx_put_image_to_window(cub->mlx, cub->window,
		cub->txtrs.main_img.img, 0, 0);
	mlx_string_put(cub->mlx, cub->window, 0, cub->screen.y - 10, 321321,
		"cub3D by cgutierr");
	if (cub->save_first)
		bmp_save(cub);
	return (0);
}
