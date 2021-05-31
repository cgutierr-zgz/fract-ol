/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgutierr <cgutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 11:00:48 by cgutierr          #+#    #+#             */
/*   Updated: 2021/03/08 18:15:04 by cgutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Añade un nuevo elemento a una lista
**
** ·1) Añadir al nuevo elemento de la lista el contenido [content]
**
** ·!) Hacemos uso de la función "malloc" gracias a la librería <stdlib.h>
*/

t_list	*ft_lstnew(void *content)
{
	t_list	*ptr;

	ptr = (t_list *)malloc(sizeof(t_list));
	if (!(ptr))
		return (NULL);
	ptr->content = content;
	ptr->next = NULL;
	return (ptr);
}
