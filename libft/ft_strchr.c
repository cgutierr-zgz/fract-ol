/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgutierr <cgutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 17:18:27 by cgutierr          #+#    #+#             */
/*   Updated: 2021/03/08 18:13:15 by cgutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Localizar el primer char [c] en [s]
**
** ·1) Vamos avanzando en la cadena [s] buscando [c]
** ·2) Si encontramos una coincidencia devolvemos un puntero a [s]
**		si no, se devuelve NULL
**
*******************************************************************************
**									EJEMPLO								     **
*******************************************************************************
** Si enviamos:		char *str	=	ft_strchr("Zapato!DeQueso!",'!')
** El resultado:	str			=	"!DeQueso!"
*/

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == c)
			return ((char *)s);
		s++;
	}
	if (*s == c)
		return ((char *)s);
	return (NULL);
}
