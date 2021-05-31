/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgutierr <cgutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 14:48:38 by cgutierr          #+#    #+#             */
/*   Updated: 2021/03/08 20:01:30 by cgutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
*****************IDENTIFICADORES [cspdiuxX%]*****************
**  d+i	=	Signed decimal integer
**  u	=	Unsigned decimal integer
**  x	=	Unsigned hexadecimal integer (Lowercase)
**  X	=	Unsigned hexadecimal integer (Uppercase)
**  c	=	Char
**  s	=	String of Chars
**  p	=	Pointer address
**  %	=	Followed by another % will just print a single %
*************************FLAGS [-0.*]************************
**  -		=	Left Justification instead of right
**  0		=	Zeros instead of space
**  .		=	Precission
**  N or *	=	Width
**
** printf("\n\nIDENTIFICADOR=%c", fmt[pstruct.i]);
** printf("\n\nFlags:\nHas Dot=%d\nWidth=%d\nprecss=%d\nHas Zero=%d\nLeftJustify
** =%d\n\n", pstruct.flags.dot, pstruct.flags.width, pstruct.flags.precss, pstru
** ct.flags.zero, pstruct.flags.ljust);
*/

static void	ft_print(const char *fmt, t_print *pstruct)
{
	if (fmt[pstruct->i] == 'd' || fmt[pstruct->i] == 'i')
		ft_handle_d_i(pstruct);
	else if (fmt[pstruct->i] == 'c' || fmt[pstruct->i] == '%')
		ft_handle_c_pct(pstruct, fmt[pstruct->i]);
	else if (fmt[pstruct->i] == 's')
		ft_handle_s(pstruct);
	else if (fmt[pstruct->i] == 'p')
		ft_handle_p(pstruct);
	else if (fmt[pstruct->i] == 'u')
		ft_handle_u(pstruct);
	else if (fmt[pstruct->i] == 'x' || fmt[pstruct->i] == 'X')
		ft_handle_x_x(pstruct, fmt[pstruct->i]);
	else if (fmt[pstruct->i] == 'n')
		ft_handle_n(pstruct);
}

int	ft_printf(const char *fmt, ...)
{
	t_print	pstruct;

	ft_bzero(&pstruct, sizeof(t_print));
	va_start(pstruct.ap, fmt);
	while (fmt[pstruct.i])
	{
		if (fmt[pstruct.i] != '%')
			pstruct.n += write(1, &fmt[pstruct.i], 1);
		else if (fmt[pstruct.i] == '%')
		{
			pstruct.i++;
			ft_bzero(&pstruct.flags, sizeof(t_flags));
			if (!ft_strchr(SPECIFIER, fmt[pstruct.i]))
				ft_flags(fmt, &pstruct);
			if (!ft_strchr(SPECIFIER, fmt[pstruct.i]))
				pstruct.n += write(1, &fmt[pstruct.i], 1);
			ft_print(fmt, &pstruct);
		}
		pstruct.i++;
	}
	va_end(pstruct.ap);
	return (pstruct.n);
}
