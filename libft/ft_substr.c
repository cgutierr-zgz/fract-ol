/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgutierr <cgutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 09:51:37 by cgutierr          #+#    #+#             */
/*   Updated: 2021/03/08 20:11:26 by cgutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Creacion un String de longitud [len] partiendo de [s] iniciando en [start]
**
** ·1) Se comprueba que [s] no sea NULL, de ser así se devolverá NULL
** ·2) Si el tamaño de [s] obtenido con "ft_strlen" es menor que el
**		inicio de la cadena [start] se devuelve un String vacío con
**		terminación '\0', siempre que la asignación de memoria con
**		"malloc" funcione, si no, NULL
** ·3) Si no, vamos asignando al creado String [str] la información
**		que vamos obteniendo al recorrer [s] a partir de [start]
**		terminamos el String en '\0' y este es el valor de retorno
**
** ·!) Hacemos uso de la función "malloc" gracias a la librería <stdlib.h>
**
*******************************************************************************
**									EJEMPLO								     **
*******************************************************************************
** Si enviamos:		char *str	=	ft_substr("Zapato de cheese", 4, 14)
** El resultado:	str			=	"to de cheese"
*/

static char	*substr_aux(char **str)
{
	*str = (char *)malloc(sizeof(char) * 1);
	if (!(*str))
		return (NULL);
	*str[0] = '\0';
	return (*str);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	unsigned int	strlen;
	char			*str;

	if (!s)
		return (NULL);
	strlen = ft_strlen(s);
	if (strlen < start)
		substr_aux(&str);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!(str))
		return (NULL);
	i = 0;
	while (i < len)
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
