/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgutierr <cgutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 19:34:52 by cgutierr          #+#    #+#             */
/*   Updated: 2021/03/08 18:15:49 by cgutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Borrar todos los elementos de una lista
**
** ·1) Comprobamos que [lst], [*lst] y [del] existan
** ·2) Vamos avanzando con [->next] siempre que estas tengan contenido
**		y aplicamos la función y la libreación de memoria con el uso de
**		"ft_lstdelone" para cada uno de los elemento de la lista
*/

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*ptr;

	if (lst && del && *lst)
	{
		while (*lst)
		{
			ptr = (*lst)->next;
			ft_lstdelone(*lst, del);
			*lst = ptr;
		}
	}
}
