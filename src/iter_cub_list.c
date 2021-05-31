/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter_cub_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgutierr <cgutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 17:35:42 by cgutierr          #+#    #+#             */
/*   Updated: 2021/04/19 18:40:52 by cgutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

void	iter_cub_list(t_cub *cub, t_list *lst, void (*f)(t_cub *, void *))
{
	t_list	*ptr;

	if (lst)
	{
		while (lst)
		{
			ptr = lst->next;
			f(cub, lst->content);
			lst = ptr;
		}
	}
}

void	iter_sprite_list(t_cub *cub, t_list *lst, void (*f)(t_cub *, void *))
{
	t_list	*ptr;

	if (lst)
	{
		while (lst)
		{
			ptr = lst->next;
			f(cub, lst->content);
			lst = ptr;
		}
	}
}
