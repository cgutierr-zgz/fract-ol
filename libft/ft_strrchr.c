/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgutierr <cgutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 15:53:35 by cgutierr          #+#    #+#             */
/*   Updated: 2021/03/08 18:07:46 by cgutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Localizar el último char [c] en [s]
**
** ·1) Hacemos uso de "ft_strlen" para obtener el tamaño de la cadena
** ·1) Vamos retrocediendo en la cadena [s] buscando [c]
** ·2) Si encontramos una coincidencia devolvemos un puntero a [s]
**		si no, se devuelve NULL
**
*******************************************************************************
**									EJEMPLO								     **
*******************************************************************************
** Si enviamos:		char *str	=	ft_strrchr("Zapato!DeQueso",'!')
** El resultado:	str			=	"!DeQueso"
*/

char	*ft_strrchr(const char *s, int c)
{
	size_t	len;

	len = ft_strlen(s);
	while (len != 0 && s[len] != c)
		len--;
	if (s[len] == c)
		return ((char *)&s[len]);
	return (NULL);
}
