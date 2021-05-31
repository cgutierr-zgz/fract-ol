/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgutierr <cgutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 18:36:48 by cgutierr          #+#    #+#             */
/*   Updated: 2021/03/08 18:14:19 by cgutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Copia de un [src] a [dst] hasta que se encuentre [c]
**
** ·1) Avanzamos en la cadena sin llegar al límite [n]
** ·2) Vamos igualando dst[i] a src[i]
** ·3) Si nos encontramos con que src[i] es igual que [c] devolvemos
**		el puntero esta cadena a partir de ese punto
** ·4) Si no [n] bytes son copiados y se devuleve un puntero NULL
*/

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		*(unsigned char *)&dst[i] = *(unsigned char *)&src[i];
		if (*(unsigned char *)&src[i] == (unsigned char)c)
			return (dst + i + 1);
		i++;
	}
	return (0);
}
