/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgutierr <cgutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 17:41:33 by cgutierr          #+#    #+#             */
/*   Updated: 2020/07/15 13:58:42 by cgutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Concatenación del string [src] al final de [dst]
**
** ·1) Se comprueba que los valores de [dst] y [src] no sean NULL, en tal
**		caso, se devolverá 0
** ·2) Vamos avanzando en la cadena y asignando el valor de [src] a [dst]
** ·3) Asignamos un último '\0' a la cadena
** ·4) El valor de retorno es el tamaño de la cadena
*/

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (!dst || !src)
		return (0);
	if (dstsize > 0)
	{
		while (src[i] && i < (dstsize - 1))
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	while (src[i])
		i++;
	return (i);
}
