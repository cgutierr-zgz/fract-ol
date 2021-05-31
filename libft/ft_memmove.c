/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgutierr <cgutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/30 11:24:53 by cgutierr          #+#    #+#             */
/*   Updated: 2021/03/08 18:14:52 by cgutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Copia de [len] bytes de [src] a [dst]
**
** ·1) Avanzamos en la cadena sin llegar al límite [n]
** ·2) Vamos igualando dst[i] a src[i]
**
** ·!) Puede haber solapamiento; la copia se realiza de manera
**		no destructiva
*/

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	int	i;

	if (!dst && !src)
		return (0);
	if (dst > src)
	{
		i = (int)len - 1;
		while (i >= 0)
		{
			*(char *)&dst[i] = *(char *)&src[i];
			i--;
		}
	}
	else
	{
		i = 0;
		while (i < (int)len)
		{
			*(char *)&dst[i] = *(char *)&src[i];
			i++;
		}
	}
	return (dst);
}
