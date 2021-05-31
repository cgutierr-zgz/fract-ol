/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comma_help.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgutierr <cgutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 17:22:10 by cgutierr          #+#    #+#             */
/*   Updated: 2021/04/19 18:10:03 by cgutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

/*
** If there's a problem with C or F commas
*/

static void	print_comma_error(int x, t_cub *cub)
{
	if (x == 1)
		print_errors(cub, "Too many/few commas for Ceiling");
	else if (x == 0)
		print_errors(cub, "Too many/few commas for Floor");
}

/*
** Aux function to check the commas of C and F
*/

void	check_commas(char **content, int n_words, t_cub *cub, int x)
{
	int		commas;
	int		i;

	commas = 0;
	i = 0;
	if (x == 1)
		handle_map_c_aux1(cub, content, n_words);
	else if (x == 0)
		handle_map_f_aux1(cub, content, n_words);
	while (i < n_words)
	{
		commas += ft_countchar(content[i], ',');
		i++;
	}
	if (commas > 2 || commas < 2)
	{
		print_comma_error(x, cub);
		free_content_array(content, n_words);
		free_content_cub(cub);
		exit(1);
	}
}

void	add_spaces_c_f(int n_words, char **content)
{
	int		j;
	char	*sopa_aux;

	j = 0;
	while (j < n_words)
	{
		sopa_aux = ft_strjoin(content[j], " ");
		free(content[j]);
		content[j] = sopa_aux;
		j++;
	}
}
