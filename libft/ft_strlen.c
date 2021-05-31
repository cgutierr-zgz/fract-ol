/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgutierr <cgutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 17:32:47 by cgutierr          #+#    #+#             */
/*   Updated: 2021/03/08 18:11:33 by cgutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Obtención del tamaño de una cadena
**
** ·1) Se va avanzando en la cadena hasta llegar al valor '\0' que define
**		el final de la misma y devolvemos el número obtenido
**
*******************************************************************************
**									EJEMPLO								     **
*******************************************************************************
** Si enviamos:		size_t n	=	ft_strlen("Zapato")
** El resultado:	n			=	6
*/

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}
