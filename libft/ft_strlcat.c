/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgutierr <cgutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 17:23:22 by cgutierr          #+#    #+#             */
/*   Updated: 2021/03/08 18:11:48 by cgutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Concatenación del string [src] al final de [dst]
**
** ·1) Obtenemos la longitud de [dst] y [src] gracias a "ft_strlen"
** ·2) Concatenará todo lo posible de:
**	->		[dstsize] - "ft_strlen"[dst] - 1(char)		<-
** ·3) Terminaremos el String en '\0'
** ·4) Inicialment se comprueba que [dstsize] no sea 0 o que [dst] sea
**		mayor que [dstsize]
** ·5) El valor de retorno es el tamaño [len] obtenido inicialmente con
**		ambos "ft_strlen"
*/

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t		i;
	size_t		len;

	len = ft_strlen(dst) + ft_strlen(src);
	if (dstsize <= ft_strlen(dst))
		return (ft_strlen(src) + dstsize);
	while (*dst)
		dst++;
	i = 0;
	while ((i < dstsize - (len - ft_strlen(src)) - 1) && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (len);
}
