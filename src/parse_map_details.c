/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_details.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgutierr <cgutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 14:48:14 by cgutierr          #+#    #+#             */
/*   Updated: 2021/04/19 17:29:46 by cgutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

/*
** We check that the given textures are different (NO, SO, WE, EA) but no S
*/

void	check_textures(t_cub *cub)
{
	if (ft_strcmp(cub->map_d.no_txt, cub->map_d.so_txt)
		|| ft_strcmp(cub->map_d.no_txt, cub->map_d.we_txt)
		|| ft_strcmp(cub->map_d.no_txt, cub->map_d.ea_txt)
		|| ft_strcmp(cub->map_d.so_txt, cub->map_d.we_txt)
		|| ft_strcmp(cub->map_d.so_txt, cub->map_d.ea_txt)
		|| ft_strcmp(cub->map_d.we_txt, cub->map_d.ea_txt))
	{
		print_simple_errors("Every single texture must be different");
		free_content_cub(cub);
		exit(1);
	}
}

/*
** Part 2 for handle content
*/

static void	handle_content_2(t_cub *cub, char **content, int n_words)
{
	if (content[0][0] == 'F' && content[0][1] == '\0')
		handle_map_f(cub, content, n_words);
	else if (content[0][0] == 'C' && content[0][1] == '\0')
		handle_map_c(cub, content, n_words);
}

/*
** Depending on the given chars we store the content accordingly
*/

static void	handle_content(t_cub *cub, char **content, int n_words)
{
	if (content[0][0] == 'R' && content[0][1] == '\0')
		handle_map_r(cub, content, n_words);
	else if (content[0][0] == 'N' && content[0][1] == 'O'
		&& content[0][2] == '\0')
		handle_map_no(cub, content, n_words);
	else if (content[0][0] == 'S' && content[0][1] == 'O'
		&& content[0][2] == '\0')
		handle_map_so(cub, content, n_words);
	else if (content[0][0] == 'W' && content[0][1] == 'E'
		&& content[0][2] == '\0')
		handle_map_we(cub, content, n_words);
	else if (content[0][0] == 'E' && content[0][1] == 'A'
		&& content[0][2] == '\0')
		handle_map_ea(cub, content, n_words);
	else if (content[0][0] == 'S' && content[0][1] == '\0')
		handle_map_s(cub, content, n_words);
	else if ((content[0][0] == 'F' && content[0][1] == '\0')
		|| (content[0][0] == 'C' && content[0][1] == '\0'))
		handle_content_2(cub, content, n_words);
	else
		handle_content_else(cub, n_words, content);
}

/*
** OK this is pretty weird, but we trim the given line (isspace except ' ')
**	then we split with ' ', i did the n_words cause I'm stupid, but i don't want
**	to change that now...
** If everything it's OK -> handle_content
*/

void	parse_specificators(t_cub *cub, char *line)
{
	char	**content;
	int		n_words;
	int		x;

	content = ft_split(line, ' ');
	n_words = ft_split_n(line, ' ');
	x = 0;
	while (line[x])
	{
		if (ft_isspace_no_space(line[x]))
		{
			print_errors(cub,
				"The information can only be separated by one or more spaces");
			free_content_array(content, n_words);
			free(line);
			free_content_cub(cub);
			exit(1);
		}
		x++;
	}
	free(line);
	if (content[0])
		handle_content(cub, content, n_words);
	free_content_array(content, n_words);
}
