/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_map_r.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgutierr <cgutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 23:07:40 by cgutierr          #+#    #+#             */
/*   Updated: 2021/04/26 18:39:13 by cgutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

static void	first_r_check(t_cub *cub, char **content)
{
	int	x;
	int	y;

	mlx_get_screen_size(cub->mlx, &x, &y);
	y -= 45;
	if (content[1][0] == '-')
		cub->screen.x = -1;
	else
	{
		cub->screen.x = ft_atoi_noletters(content[1]);
		if (cub->screen.x < 0)
			cub->screen.x = x;
	}
	if (content[2][0] == '-')
		cub->screen.y = -1;
	else
	{
		cub->screen.y = ft_atoi_noletters(content[2]);
		if (cub->screen.y < 0)
			cub->screen.y = y;
	}
}

void	handle_map_r(t_cub *cub, char **content, int n_words)
{
	if (is_bit_set(cub->elems, R))
	{
		print_errors(cub, "Resolution was already set");
		aux(cub, content, n_words);
	}
	if (n_words == 3)
	{
		first_r_check(cub, content);
		if (cub->screen.x < 50 || cub->screen.y < 50 || cub->screen.x > INT_MAX
			|| cub->screen.y > INT_MAX)
		{
			printf("Error\n(Line %d): ", cub->actual_line);
			printf(W_B_RED "Invalid resolution \"%dx%d\"\n" RESET,
				cub->screen.x, cub->screen.y);
			aux(cub, content, n_words);
		}
		cub->elems = set_bit(cub->elems, R);
	}
	else
	{
		print_errors(cub, "Invalid params for \"R\"");
		aux(cub, content, n_words);
	}
}
