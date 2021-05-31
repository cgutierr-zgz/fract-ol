/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgutierr <cgutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 14:47:46 by cgutierr          #+#    #+#             */
/*   Updated: 2021/03/04 14:33:27 by cgutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Conversión de minúsculas a mayúsculas
**
** ·1) Comprobamos que [c] se encuentre entre 'a'-'z'
**		Si es así, se devuelve [c]-=32, en caso contrario devolvemos [c]
**
*******************************************************************************
**									EJEMPLO								     **
*******************************************************************************
** Si enviamos:		int n	=	ft_toupper('a')
** El resultado:	n		=	65 == 'A'
*/

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		return (c -= 32);
	return (c);
}
