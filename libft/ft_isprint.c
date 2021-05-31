/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgutierr <cgutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 14:44:34 by cgutierr          #+#    #+#             */
/*   Updated: 2021/03/04 16:03:25 by cgutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Comprobación de si el int [c] recibido es un Imprimible
**
** ·1) Comprobamos que [c] se encuentre entre 32 y 126->' '-'~'
**		Si es así, se devuelve 1, en caso contrario devolvemos 0
**
*******************************************************************************
**									EJEMPLO								     **
*******************************************************************************
** Si enviamos:		int n	=	ft_isprint(' ')
** El resultado:	n		=	1
*/

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (1);
	return (0);
}
