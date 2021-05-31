/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgutierr <cgutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 19:47:07 by cgutierr          #+#    #+#             */
/*   Updated: 2021/05/31 13:14:15 by cgutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void	print_map(t_cub *cub, int i)
{
	int	z;
	int	z2;

	if (i)
	{
		z = 0;
		printf("\n");
		while (z < cub->map.map_lines)
		{
			z2 = 0;
			while (z2 < cub->map.max_len)
			{
				printf("%c", cub->map.map_matrix[z][z2]);
				z2++;
			}
			printf("\n");
			z++;
		}
	}
	printf("\n[" GREEN "✔" RESET "] Valid map\n[" RESET);
	if (cub->save_first)
		printf(GREEN "✔" RESET);
	else
		printf(RED "✘" RESET);
	printf("] Screenshot\n" RESET);
}

static void	print_map_info(t_cub *cub)
{
	printf(WHITE_BOX "\n*************\n*    MAP    *\n*************\n\n" RESET);
	printf("Map lines = "RESET);
	printf(YELLOW"%d\n"RESET, cub->map.map_lines);
	printf("Longest line = "RESET);
	printf(YELLOW"%d\n"RESET, cub->map.max_len);
	printf("Player orientation = "RESET);
	printf(YELLOW"%c\n"RESET, cub->map.player_o);
	printf("Player position = "RESET);
	printf(YELLOW"%d,%d\n"RESET, cub->map.player_pos.x, cub->map.player_pos.y);
	printf("Number of sprites = "RESET);
	printf(YELLOW"%d\n"RESET, cub->txtrs.num_sprites);
	print_map(cub, 0);
}

void	print_specificators(t_cub *cub)
{
	printf(WHITE_BOX "\n*************\n*   INFO    *\n*************\n\n" RESET);
	printf("R  = " RESET);
	printf(YELLOW "%dx%d\n" RESET, cub->screen.x, cub->screen.y);
	printf("NO = " RESET);
	printf(YELLOW "%s\n" RESET, cub->map_d.no_txt);
	printf("SO = " RESET);
	printf(YELLOW "%s\n" RESET, cub->map_d.so_txt);
	printf("WE = " RESET);
	printf(YELLOW "%s\n" RESET, cub->map_d.we_txt);
	printf("EA = " RESET);
	printf(YELLOW "%s\n" RESET, cub->map_d.ea_txt);
	printf("S  = " RESET);
	printf(YELLOW "%s\n" RESET, cub->map_d.s_txt);
	printf("F  = " RESET);
	printf(YELLOW "%d,%d,%d\n" RESET, cub->map_d.floor.r, cub->map_d.floor.g,
		   cub->map_d.floor.b);
	printf("C  = " RESET);
	printf(YELLOW "%d,%d,%d\n" RESET, cub->map_d.ceiling.r,
		cub->map_d.ceiling.g, cub->map_d.ceiling.b);
	print_map_info(cub);
}

void	print_errors(t_cub *cub, char *str)
{
	printf("Error\n(Line %d): ", cub->actual_line);
	printf(W_B_RED "%s\n" RESET, str);
}

void	print_simple_errors(char *str)
{
	printf("Error\n");
	printf(W_B_RED "%s\n" RESET, str);
}
