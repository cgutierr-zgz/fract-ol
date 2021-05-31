/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgutierr <cgutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 14:35:36 by cgutierr          #+#    #+#             */
/*   Updated: 2021/03/04 16:02:30 by cgutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Comprobación de si el int [c] recibido es ASCII
**
** ·1) Comprobamos que [c] se encuentre entre 0 y 127->'NULL'-'DEL'
**		Si es así, se devuelve 1, en caso contrario devolvemos 0
**
*******************************************************************************
**									EJEMPLO								     **
*******************************************************************************
** Si enviamos:		int n	=	ft_isascii('A')
** El resultado:	n		=	1
*/

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	return (0);
}
