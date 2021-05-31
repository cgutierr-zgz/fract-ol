/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_map_c.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgutierr <cgutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 23:19:19 by cgutierr          #+#    #+#             */
/*   Updated: 2021/04/19 18:13:56 by cgutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

static void
	handle_map_c_aux2(t_cub *cub, char **split, int n_split)
{
	printf("Error\n(Line %d): ", cub->actual_line);
	printf(W_B_RED "Invalid parameters for Ceiling RGB \"%d,%d,%d\"\n" RESET,
		cub->map_d.ceiling.r, cub->map_d.ceiling.g, cub->map_d.ceiling.b);
	free_content_cub(cub);
	free_content_array(split, n_split);
	exit(1);
}

void	handle_map_c_aux1(t_cub *cub, char **content, int n_words)
{
	if (is_bit_set(cub->elems, C))
	{
		print_errors(cub, "Ceiling RGB was already set");
		free_content_array(content, n_words);
		free_content_cub(cub);
		exit(1);
	}
}

static void
	handle_map_c_store(t_cub *cub, char **split)
{
	cub->map_d.ceiling.r = ft_atoi_noletters(split[0]);
	cub->map_d.ceiling.g = ft_atoi_noletters(split[1]);
	cub->map_d.ceiling.b = ft_atoi_noletters(split[2]);
}

static void	content_c(char **content, char **join, int n_words)
{
	char	*aux;
	int		i;

	i = 1;
	*join = ft_strdup("");
	while (i < n_words)
	{
		aux = ft_strdup(*join);
		free(*join);
		*join = ft_strjoin(aux, content[i]);
		free(aux);
		i++;
	}
}

void	handle_map_c(t_cub *cub, char **content, int n_words)
{
	char	*join;
	char	**split;
	int		n_split;

	add_spaces_c_f(n_words, content);
	check_commas(content, n_words, cub, 1);
	content_c(content, &join, n_words);
	split = ft_split(join, ',');
	n_split = ft_split_n(join, ',');
	free(join);
	if (n_split > 3 || n_split < 3)
	{
		free_content_array(content, n_words);
		handle_map_c_aux2(cub, split, n_split);
	}
	handle_map_c_store(cub, split);
	if (cub->map_d.ceiling.r < 0 || cub->map_d.ceiling.r > 255
		|| cub->map_d.ceiling.g < 0 || cub->map_d.ceiling.g > 255
		|| cub->map_d.ceiling.b < 0 || cub->map_d.ceiling.b > 255)
	{
		free_content_array(content, n_words);
		handle_map_c_aux2(cub, split, n_split);
	}
	cub->elems = set_bit(cub->elems, C);
	free_content_array(split, n_split);
}
