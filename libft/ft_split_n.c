/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_n.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgutierr <cgutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/09 14:29:28 by cgutierr          #+#    #+#             */
/*   Updated: 2021/03/11 21:36:38 by cgutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Troceado de String en varios Strings, usando [c] como delimitador
**
** ·1) Se comprueba que no de la asignación de memoria, [s] y [c] no sea
**		NULL, de ser así se devolvería NULL
** ·2) Entramos n veces en un bucle que obtenemos al saber cuantos Strings
**		hay en [s] limitándolo con [c] gracias a "ft_substrings"
** ·3) Vamos asignando memoria usando "ft_substrlen" que obtiene el tamaño de
**		un string avanzando a partir de un punto [k], hasta encontrar el
**		siguiente char [c], este malloc se le añade el + 1 para el '\0' final
** ·4) Seguimos avanzando y mientras s[k] sea [c] simplemente lo obviamos
** ·5) Mientras que s[k] no sea NULL ni igual a [c] vamos igualando
**		el string actual [i] [j++] a s[k++] y terminándolo con '\0'
** ·6) El bucle se va repitiendo con i++ hasta llegar al número de palabras
**		obtenidas con "ft_substrings"
** ·7) Se añade un último string NULL y ese array de Strings es lo que
**		se devuelve
**
*******************************************************************************
**									EJEMPLO								     **
*******************************************************************************
** Si enviamos:		char **str	=	ft_split("Hola,que,tal,estás",',')
** El resultado:	*str[0]		=	"Hola"
**					*str[1]		=	"que"
**					*str[2]		=	"tal"
**					*str[3]		=	"estás"
**					*str[4]		=	NULL
*/

static int	ef_number_str(char *s, char c)
{
	int	n_str;
	int	check;
	int	i;

	n_str = 0;
	check = 0;
	i = -1;
	if (s[0] == '\0')
		return (0);
	while (s[++i] != '\0')
	{
		if (s[i] == c)
			check = 0;
		else if (check++ == 0)
			n_str++;
	}
	return (n_str);
}

int	ft_split_n(char const *s, char c)
{
	if (!s)
		return (0);
	return (ef_number_str((char *)s, c));
}
