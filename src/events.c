/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgutierr <cgutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 16:34:25 by cgutierr          #+#    #+#             */
/*   Updated: 2021/04/23 09:28:42 by cgutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

void	my_pixel_put(t_img *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_l + x * (data->bpp / 8));
	*(unsigned int *)dst = color;
}

int	my_pixel_get(t_img *data, int x, int y)
{
	return (*(unsigned int *)(data->addr + (y
			* data->line_l + x * (data->bpp / 8))));
}

/*
** Cierra el programa, tonto
**	system("leaks cub3D");
*/

int	destroy(t_cub *cub)
{
	free_content_cub(cub);
	free_content_map_matrix(cub);
	ft_lstclear(&cub->txtrs.sprite_list, clear_matrix_content);
	free(cub->data.zbuffer);
	printf(GREEN "\n\nHave a nice day!\n" RESET);
	exit(0);
	return (0);
}

int	key_release(int keycode, t_cub *cub)
{
	if (keycode == K_W)
		cub->mov.up = 0;
	if (keycode == K_A)
		cub->mov.left = 0;
	if (keycode == K_S)
		cub->mov.down = 0;
	if (keycode == K_D)
		cub->mov.right = 0;
	if (keycode == K_LEFT)
		cub->mov.rotate_left = 0;
	if (keycode == K_RIGHT)
		cub->mov.rotate_right = 0;
	else if (keycode == L_SHIFT && (cub->mov.mov_s > 0.05))
		cub->mov.mov_s /= 2;
	return (keycode);
}

int	keys(int keycode, t_cub *cub)
{
	if (keycode == K_ESC)
		destroy(cub);
	if (keycode == K_W)
		cub->mov.up = 1;
	if (keycode == K_A)
		cub->mov.left = 1;
	if (keycode == K_S)
		cub->mov.down = 1;
	if (keycode == K_D)
		cub->mov.right = 1;
	if (keycode == K_LEFT)
		cub->mov.rotate_left = 1;
	if (keycode == K_RIGHT)
		cub->mov.rotate_right = 1;
	else if (keycode == L_SHIFT)
		cub->mov.mov_s *= 2;
	return (keycode);
}
