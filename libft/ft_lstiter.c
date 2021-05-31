/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgutierr <cgutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 12:17:11 by cgutierr          #+#    #+#             */
/*   Updated: 2021/03/08 18:15:42 by cgutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Aplicación de una función al iterar sobre cada elemento de una lista
**
** ·1) Se comprueba que [lst] exista
** ·2) Mientras esta exista (puesto que vamos igualándola a [ptr] y
**		[ptr] = [lst->next] al final aplicamos previamente [f] a
**		el contenido [lst->content] luego lo igualamos al puntero temporal
*/

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*ptr;

	if (lst)
	{
		while (lst)
		{
			ptr = lst->next;
			f(lst->content);
			lst = ptr;
		}
	}
}
