/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_c_pct.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgutierr <cgutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 16:38:02 by cgutierr          #+#    #+#             */
/*   Updated: 2021/03/08 20:01:39 by cgutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	c_pct_ljust(t_print *pstruct, char x)
{
	pstruct->n += write(1, &x, 1);
	if (pstruct->flags.width)
		while (--pstruct->flags.width > 0)
			pstruct->n += write(1, " ", 1);
}

static void	c_pct_no_ljust(t_print *pstruct, char x)
{
	if (pstruct->flags.width)
	{
		while (--pstruct->flags.width > 0)
		{
			if (pstruct->flags.zero && x)
				pstruct->n += write(1, "0", 1);
			else
				pstruct->n += write(1, " ", 1);
		}
	}
	pstruct->n += write(1, &x, 1);
}

void	ft_handle_c_pct(t_print *pstruct, char c)
{
	char	x;

	if (c == '%')
		x = '%';
	else
		x = va_arg(pstruct->ap, int);
	if (!x)
		x = '\0';
	if (!pstruct->flags.ljust)
		c_pct_no_ljust(pstruct, x);
	else
		c_pct_ljust(pstruct, x);
}
