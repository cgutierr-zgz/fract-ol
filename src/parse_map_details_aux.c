/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_details_aux.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgutierr <cgutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 14:48:12 by cgutierr          #+#    #+#             */
/*   Updated: 2021/05/31 13:13:41 by cgutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

/*
** Something we do not handle
*/

void	handle_content_else(t_cub *cub, int n_words, char **content)
{
	printf("Error\n(Line %d): ", cub->actual_line);
	printf(W_B_RED "Unkown param \"%s\"\n" RESET, content[0]);
	free_content_array(content, n_words);
	free_content_cub(cub);
	exit(1);
}

/*
** Function for ft_lstclear (Clear sprite is unnecesary but ok)
*/

void	clear_matrix_content(void *content)
{
	free(content);
}

/*
** Player orientation error message
*/

void	player_orientation_error(t_cub *cub)
{
	print_simple_errors("Player orientation wasn't set");
	free_content_cub(cub);
	ft_lstclear(&cub->map.map_list, clear_matrix_content);
	exit(1);
}

/*
** Core function to store the matrix and clear the linked list
** Map needs to be 3x3
*/

void	check_map_details(t_cub *cub)
{
	if (!cub->map.player_o)
		player_orientation_error(cub);
	iter_cub_list(cub, cub->map.map_list, fill_map_matrix);
	ft_lstclear(&cub->map.map_list, clear_matrix_content);
	if (cub->map.map_lines < 3 || cub->map.max_len < 3)
	{
		print_simple_errors("A valid map requires at least a 3x3 grid");
		free_content_map_matrix(cub);
		free_content_cub(cub);
		exit(1);
	}
	check_matrix_ok(cub);
}
