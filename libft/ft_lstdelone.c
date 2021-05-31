/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgutierr <cgutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 19:23:12 by cgutierr          #+#    #+#             */
/*   Updated: 2020/07/15 11:45:51 by cgutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Borrar un elemento de una lista
**
** ·1) Comprobamos que [lst] y [del] existan
** ·2) Borramos el contenido de [lst] y lo liberamos con "free"
**
** ·!) Hacemos uso de la función "free" gracias a la librería <stdlib.h>
*/

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (lst && del)
	{
		del(lst->content);
		free(lst);
	}
}
