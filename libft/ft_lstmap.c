/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgutierr <cgutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 12:28:17 by cgutierr          #+#    #+#             */
/*   Updated: 2021/03/08 18:15:29 by cgutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Creación de una Lista a partir de otra, tras aplicarle una función
**
** ·1) Se comprueba que tanto [ls] como [f] existan
** ·2) Vamos iterando por [ls] y si la asignación de memoria fallase saldríamos
**		borrando la lista y devolviendo NULL hacemos uso de "ft_lstnew"
**		"ft_lstclear"
** ·3) Mientras la asignación de memoria funcione, simplemente, añadimos el
**		nuevo elemento a la nueva lista, igualando [ls] a [ls->next]
**		para avanzar en esta y añadiéndolo al final haciendo uso de
**		"ft_lstadd_back"
*/

t_list	*ft_lstmap(t_list *ls, void *(*f)(void *), void (*dl)(void *))
{
	t_list	*new_lst;
	t_list	*new_elem;

	if (!ls && !f)
		return (NULL);
	new_lst = NULL;
	while (ls)
	{
		new_elem = ft_lstnew(f(ls->content));
		if (!(new_elem))
		{
			ft_lstclear(&new_lst, dl);
			return (NULL);
		}
		ft_lstadd_back(&new_lst, new_elem);
		ls = ls->next;
	}
	return (new_lst);
}
