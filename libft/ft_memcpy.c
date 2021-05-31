/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgutierr <cgutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 18:07:07 by cgutierr          #+#    #+#             */
/*   Updated: 2020/07/15 13:05:36 by cgutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Copia de un [n] bytes de [src] a [dst]
**
** ·1) Avanzamos en la cadena sin llegar al límite [n]
** ·2) Vamos igualando dst[i] a src[i]
**
** ·!) Si ocurre un solapamiento no hay un comportamiento definivo y se
**		recomienda el uso de (memmove)
*/

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*dest;
	unsigned char	*source;

	if ((!dst && !src))
		return (0);
	i = 0;
	dest = (unsigned char *)dst;
	source = (unsigned char *)src;
	while (i < n)
	{
		dest[i] = source[i];
		i++;
	}
	return (dest);
}
