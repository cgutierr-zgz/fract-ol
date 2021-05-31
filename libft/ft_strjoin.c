/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgutierr <cgutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/02 17:14:30 by cgutierr          #+#    #+#             */
/*   Updated: 2021/03/08 18:12:50 by cgutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Asignación de memoria y concatenación de Strings
**
** ·1) Comprobamos que [s1] o [s2] no sean NULL, de ser así se devuelve NULL
** ·2) Almacenamos memoria para el nuevo String haciendo uso de "ft_strlen"
**		para [s1] y [s2] y "malloc", añadimos un byte final para el último '\0'
** ·3) Habiendo asignado la memoria vamos recorriendo [s1] y asignando a
**		[str] el valor de [s1]
** ·4) Repetimos el proceso anterior pero con [s2]
** ·5) Añadimos un último '\0' y devolvemos el resultado
**
** ·!) Hacemos uso de la función "malloc" gracias a la librería <stdlib.h>
*/

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	i;

	if (!s1 || !s2)
		return (NULL);
	str = (char *)malloc(sizeof(*str) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!(str))
		return (NULL);
	i = 0;
	while (*s1)
	{
		str[i] = *s1;
		i++;
		s1++;
	}
	while (*s2)
	{
		str[i] = *s2;
		i++;
		s2++;
	}
	str[i] = '\0';
	return (str);
}
