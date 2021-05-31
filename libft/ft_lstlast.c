/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgutierr <cgutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 12:40:31 by cgutierr          #+#    #+#             */
/*   Updated: 2021/03/08 18:15:37 by cgutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Devolvemos el último elemento de la lista
**
** ·1) Comprobamos que la lista exista, de no ser así se devuelve NULL
** ·2) Vamos recorriendo la lista igualando [ptr] a [ptr->next]
**		y al llegar al final ese es el valor de retorno
*/

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*ptr;

	if (!lst)
		return (NULL);
	ptr = lst;
	while (ptr->next)
	{
		ptr = ptr->next;
	}
	return (ptr);
}
