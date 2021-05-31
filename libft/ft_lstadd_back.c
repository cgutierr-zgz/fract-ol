/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgutierr <cgutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 13:22:35 by cgutierr          #+#    #+#             */
/*   Updated: 2021/03/08 18:15:57 by cgutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Añadir un elemento al final de una lista
**
** ·1) Se comprueba que [*lst] exista, si no, se le iguala a new, puesto ese
**		sería la última posición
** ·2) igualamos [ptr] a la última posición de [lst] haciendo uso de
**		"ft_lstlast" y añadimos [new] a la siguiente [->next] posición
*/

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*ptr;

	if (!*lst)
		*lst = new;
	else
	{
		ptr = ft_lstlast(*lst);
		ptr->next = new;
	}
}
