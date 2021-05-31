/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgutierr <cgutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 14:55:17 by cgutierr          #+#    #+#             */
/*   Updated: 2021/04/13 16:34:30 by cgutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

/*
** We store and check the player orientation
*/

static void	check_player_orientation(char *line, int j, t_cub *cub)
{
	if (ft_strchr("NSEW", line[j]) && !cub->map.player_o)
	{
		cub->map.player_o = line[j];
		cub->map.player_pos.x = cub->map.map_lines;
		cub->map.player_pos.y = j + 1;
	}
	else if (ft_strchr("NSEW", line[j]) && cub->map.player_o)
	{
		print_errors(cub, "Player orientation was already set");
		free_content_cub(cub);
		ft_lstclear(&cub->map.map_list, clear_matrix_content);
		exit(1);
	}
}

/*
** We store the content in a linked list and we do some checks of errors
*/

static void	store_map_line(char *line, t_cub *cub)
{
	int	j;
	int	len;

	j = 0;
	cub->map.map_lines += 1;
	ft_lstadd_back(&cub->map.map_list, ft_lstnew(line));
	len = ft_strlen(line);
	if (cub->map.max_len < len)
		cub->map.max_len = len;
	j = 0;
	while (line[j])
	{
		check_player_orientation(line, j, cub);
		if (!ft_strchr(MAP_IDENTIFICATORS, line[j]))
		{
			printf("Error\n(Line %d): ", cub->actual_line);
			printf(W_B_RED "\"%c\" Not valid for the map\n" RESET, line[j]);
			free_content_cub(cub);
			ft_lstclear(&cub->map.map_list, clear_matrix_content);
			exit(1);
		}
		j++;
	}
}

/*
** This is to get rid of lines with just spaces at the start and we only store
**	lines with content after that
*/

static void	parse_map_line(char *line, t_cub *cub)
{
	int	j;

	j = 0;
	if (!cub->map.has_content)
	{
		while (line[j])
		{
			if (ft_strchr("NSEW120", line[j]))
				cub->map.has_content = 1;
			j++;
		}
	}
	if (cub->map.has_content)
		store_map_line(line, cub);
	else
		free(line);
}

/*
** We start parsing the map itself -> parse_map_line
**	If there's content after the map -> Error
*/

void	parse_map(char *line, t_cub *cub)
{
	check_textures(cub);
	cub->is_map = 1;
	if (!cub->end_map)
		parse_map_line(line, cub);
	else
	{
		print_errors(cub, "There should be no content after the map");
		free(line);
		free_content_cub(cub);
		ft_lstclear(&cub->map.map_list, clear_matrix_content);
		exit(1);
	}
}
