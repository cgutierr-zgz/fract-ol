/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgutierr <cgutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/03 17:46:05 by cgutierr          #+#    #+#             */
/*   Updated: 2021/03/08 18:07:32 by cgutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Limpieza de los extremos de una cadena
**
** ·1) Protegemos la función comprobando que no nos pasen nada NULL
** ·2) Vamos avanzando en el String por el principio encontrando
**		coincidencias para adivinar a partir de que punto empieza
**		el String sin el [set] de chars que no queremos
** ·3) Hacemos lo mismo pero desde el final
** ·4) Alocamos Memoria del tamaño ([end]-[start]+1) para '\0'
** ·5) Vamos asignando a [str] los chars de [s1] hasta llegar al final
**		dónde añadimos el '\0' final y lo devolvemos
**
** ·!) Hacemos uso de la función "malloc" gracias a la librería <stdlib.h>
**
*******************************************************************************
**									EJEMPLO								     **
*******************************************************************************
** Si enviamos:		char *str	=	ft_strtrim("Zapato de cheesepaZ", "Zap"))
** El resultado:	str			=	"to de cheese"
*/

static int	ft_char_in_set(char c, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	size_t	i;
	size_t	start;
	size_t	end;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	while (s1[start] && ft_char_in_set(s1[start], set))
		start++;
	end = ft_strlen(s1);
	while (end > start && ft_char_in_set(s1[end - 1], set))
		end--;
	str = (char *)malloc(sizeof(*s1) * (end - start + 1));
	if (!(str))
		return (NULL);
	i = 0;
	while (start < end)
		str[i++] = s1[start++];
	str[i] = '\0';
	return (str);
}
