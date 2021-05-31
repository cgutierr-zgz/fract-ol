/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgutierr <cgutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/09 11:19:25 by cgutierr          #+#    #+#             */
/*   Updated: 2021/03/08 18:11:26 by cgutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Aplicación de una función consecutivamente a cada índice de una cadena
**
** ·1) Se comprueba que la cadena no sea NULL, de ser así se devuelve NULL
** ·2) Se obtiene la longitud de [s] gracias a "ft_strlen" y se Asigna
**		memoria gracias a "malloc", si la asignación de memoria falla
**		se devuelve NULL
** ·3) Vamos avanzando en la cadena y aplicando [f] a cada índice de [s]
** ·4) Terminamos la cadena con '\0' y el valor a devolver es la cadena
**		resultante tras la aplicación de la función a cada índice
**
** ·!) Hacemos uso de la función "malloc" gracias a la librería <stdlib.h>
*/

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	size_t	len;
	char	*str;

	i = 0;
	if (!s)
		return (NULL);
	len = ft_strlen(s);
	str = ((char *)malloc(sizeof(char) * len + 1));
	if ((str))
	{
		while (i < len)
		{
			str[i] = f(i, s[i]);
			i++;
		}
		str[i] = '\0';
	}
	return (str);
}
