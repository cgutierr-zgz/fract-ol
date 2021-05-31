/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgutierr <cgutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 15:16:56 by cgutierr          #+#    #+#             */
/*   Updated: 2021/03/08 18:10:33 by cgutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Localización de un Sub-String en un String
**
** ·1) Se comprueba que [needle] no sea NULL, de ser así se devuelve un
**		puntero a [str]
** ·2) Vamos avanzando en [str] siempre y cuando no superemos [len]
** ·3) Si encontramos una coincidencia devolvemos un puntero a esa posición
**		de [str]
**
*******************************************************************************
**									EJEMPLO								     **
*******************************************************************************
** Si enviamos:		char *str	=	ft_strnstr("Zapato de queso!","de", 16)
** El resultado:	str			=	"de queso!"
*/

char	*ft_strnstr(const char *str, const char *needle, size_t len)
{
	size_t	i;
	size_t	i2;

	if (!*needle)
		return ((char *)str);
	i = 0;
	while (str[i] != '\0' && i < len)
	{
		if (str[i] == needle[0])
		{
			i2 = 1;
			while (needle[i2] && str[i + i2]
				== needle[i2] && (i + i2) < len)
				++i2;
			if (needle[i2] == '\0')
				return ((char *)&str[i]);
		}
		i++;
	}
	return (0);
}
