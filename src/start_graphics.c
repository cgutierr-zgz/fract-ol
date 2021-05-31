/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_graphics.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgutierr <cgutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 09:38:01 by cgutierr          #+#    #+#             */
/*   Updated: 2021/04/26 18:15:04 by cgutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

/*
** Aux funtion for errors
*/

static void	check_all_textures_aux(t_cub *cub)
{
	print_simple_errors("There was an error with the textures");
	free_content_cub(cub);
	free_content_map_matrix(cub);
	ft_lstclear(&cub->txtrs.sprite_list, clear_matrix_content);
	exit(1);
}

/*
** Funtion used to change the textures from char * to mlx valid info
*/

static void	check_all_textures(t_cub *cub)
{
	char	**textures[5];
	int		zz;

	textures[0] = &cub->map_d.no_txt;
	textures[1] = &cub->map_d.so_txt;
	textures[2] = &cub->map_d.we_txt;
	textures[3] = &cub->map_d.ea_txt;
	textures[4] = &cub->map_d.s_txt;
	zz = 0;
	while (zz < 5)
	{
		cub->txtrs.img[zz].img = mlx_xpm_file_to_image(cub->mlx, *textures[zz],
				&cub->txtrs.width[zz], &cub->txtrs.height[zz]);
		if (!cub->txtrs.img[zz].img)
			check_all_textures_aux(cub);
		cub->txtrs.img[zz].addr
			= mlx_get_data_addr(cub->txtrs.img[zz].img, &cub->txtrs.img[zz].bpp,
				&cub->txtrs.img[zz].line_l, &cub->txtrs.img[zz].endian);
		zz++;
	}
}

/*
** Aux funtion for the bmp
*/

static void	write_headder(int fd, t_cub *c)
{
	unsigned char	headder[54];
	int				i;

	i = 0;
	while (i < 54)
		headder[i++] = (unsigned char)0;
	headder[0] = 'B';
	headder[1] = 'M';
	headder[10] = (unsigned char)(54);
	headder[14] = (unsigned char)(40);
	headder[18] = (unsigned char)(c->screen.x);
	headder[19] = (unsigned char)(c->screen.x >> 8);
	headder[20] = (unsigned char)(c->screen.x >> 16);
	headder[21] = (unsigned char)(c->screen.x >> 24);
	headder[22] = (unsigned char)(c->screen.y);
	headder[23] = (unsigned char)(c->screen.y >> 8);
	headder[24] = (unsigned char)(c->screen.y >> 16);
	headder[25] = (unsigned char)(c->screen.y >> 24);
	headder[26] = (unsigned char)1;
	headder[28] = (unsigned char)32;
	write(fd, headder, 54);
}

/*
** We store the first frame as a .bmp file
*/

void	bmp_save(t_cub *cub)
{
	int		fd;
	int		ww;
	int		y;
	int		bpp;

	bpp = cub->txtrs.main_img.bpp / 8;
	fd = open("./resources/exports/save.bmp",
			O_WRONLY | O_CREAT | O_TRUNC | O_APPEND, 0777);
	write_headder(fd, cub);
	y = cub->screen.y - 1;
	while (y >= 0)
	{
		ww = 0;
		while (ww < cub->screen.x)
		{
			write(fd,
				cub->txtrs.main_img.addr + ((y) * cub->txtrs.main_img.line_l
					+ ww * (bpp)), bpp);
			ww++;
		}
		y--;
	}
	close(fd);
	printf("\nFile saved to \"./resources/exports/save.bmp\"");
	destroy(cub);
}

/*
** We initialize mlx
** We close all given fd's (Map/textures)
** We check the map, and store it in a char[][]
** Stored info is printed
** We store the images for the mlx
** Depending on the current screen size we set that to be the maximum
** If save_first == 1 -> We just handle the save of the first frame
** else -> We start playing cub3D
*/

void	start_graphics(t_cub *cub)
{
	int	x;
	int	y;

	cub->mlx = mlx_init();
	if (!cub->mlx)
	{
		print_simple_errors("There was a problem with MiniLibx");
		free_content_map_matrix(cub);
		free_content_cub(cub);
		exit(1);
	}
	close_fds(cub);
	check_map_details(cub);
	check_all_textures(cub);
	print_specificators(cub);
	mlx_get_screen_size(cub->mlx, &x, &y);
	y -= 45;
	if (cub->screen.x > x)
		cub->screen.x = x;
	if (cub->screen.y > y)
		cub->screen.y = y;
	cub_tresd(cub);
}
