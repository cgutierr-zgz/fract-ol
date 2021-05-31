/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgutierr <cgutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 14:27:06 by cgutierr          #+#    #+#             */
/*   Updated: 2021/03/04 16:03:07 by cgutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Comprobación de si el int [c] recibido es un Dígito
**
** ·1) Comprobamos que [c] se encuentre entre '0'-'9'
**		Si es así, se devuelve 1, en caso contrario devolvemos 0
**
*******************************************************************************
**									EJEMPLO								     **
*******************************************************************************
** Si enviamos:		int n	=	ft_isdigit('0')
** El resultado:	n		=	1
*/

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}
