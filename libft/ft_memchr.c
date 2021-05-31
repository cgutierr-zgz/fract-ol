/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgutierr <cgutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/30 11:27:34 by cgutierr          #+#    #+#             */
/*   Updated: 2021/03/08 18:14:09 by cgutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Busqueda de [c] en la cadena [s]
**
** ·1) Avanzamos en la cadena sin llegar al límite [n]
** ·2) Si nos encontramos con que s[i] es igual que [c] devolvemos el
**		puntero a s[i]
*/

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned int	i;

	i = 0;
	while (i < n)
	{
		if (*(unsigned char *)&s[i] == (unsigned char)c)
			return ((void *)&s[i]);
		i++;
	}
	return (0);
}
