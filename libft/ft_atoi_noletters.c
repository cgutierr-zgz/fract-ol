/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_noletters.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgutierr <cgutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 14:57:29 by cgutierr          #+#    #+#             */
/*   Updated: 2021/04/19 17:35:38 by cgutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Conversión de una cadena de Chars a un Int
**
** ·1) Comprobamos y descartamos cualquier char isspace (man isspace) mientras
** 		avanzamos por la cadena
** ·2) Comprobamos que el siguiente char sea '-' o '+' y en función de lo que
**		nos encontremos convertimos [isnegative] en 1 o en -1
** ·3) Tras haber descartado esos chars pervios vamos avanzando en la cadena
**		siempre que esta esté comprendida entre '0' y '9', multiplicando
**		nuestro int [x] * 10 y sumándole el char actual - '0'->(48) para así
**		convertir ese valor ASCII en el número real
** ·4) Al final devolvemos el número [x] obtenido y lo multiplicamos por
**		[isnegative] para tener el símbolo correcto en nuestro Int
**
*******************************************************************************
**									EJEMPLO								     **
*******************************************************************************
** Si enviamos:		int n	=	ft_atoi("-12345")
** El resultado:	n		=	-12345
*/

static int	return_function(const char *str, int x, int isnegative)
{
	if (*str != '\0')
		return (-1);
	return (x * isnegative);
}

int	ft_atoi_noletters(const char *str)
{
	int	x;
	int	isnegative;

	x = 0;
	isnegative = 1;
	while (*str == ' ' || *str == '\f' || *str == '\n' || *str == '\r'
		|| *str == '\t' || *str == '\v')
		str++;
	if (*str == '-')
	{
		isnegative *= -1;
		str++;
	}
	else if (*str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		x = x * 10 + (*str - '0');
		str++;
	}
	while (*str == ' ' || *str == '\f' || *str == '\n' || *str == '\r'
		|| *str == '\t' || *str == '\v')
		str++;
	return (return_function(str, x, isnegative));
}
