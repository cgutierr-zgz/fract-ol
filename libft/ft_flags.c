/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgutierr <cgutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 20:10:48 by cgutierr          #+#    #+#             */
/*   Updated: 2021/03/09 19:18:41 by cgutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_flags_precision(const char *fmt, t_print *pstruct, int star)
{
	pstruct->flags.precss = 0;
	if (star == 0)
	{
		while (fmt[pstruct->i] >= '0' && fmt[pstruct->i] <= '9')
		{
			pstruct->flags.precss = pstruct->flags.precss
				* 10 + (fmt[pstruct->i] - '0');
			pstruct->i++;
		}
	}
	if (star == 1)
	{
		pstruct->flags.precss = va_arg(pstruct->ap, int);
		pstruct->i++;
		if (pstruct->flags.precss < 0)
			pstruct->flags.dot = 0;
	}
}

static void	ft_flags_width(const char *fmt, t_print *pstruct, int star)
{
	pstruct->flags.width = 0;
	if (star == 0)
	{
		while (fmt[pstruct->i] >= '0' && fmt[pstruct->i] <= '9')
		{
			pstruct->flags.width = pstruct->flags.width
				* 10 + (fmt[pstruct->i] - '0');
			pstruct->i++;
		}
	}
	if (star == 1)
	{
		pstruct->flags.width = va_arg(pstruct->ap, int);
		pstruct->i++;
		if (pstruct->flags.width < 0)
		{
			pstruct->flags.width *= -1;
			pstruct->flags.ljust = 1;
		}
	}
}

static void	ft_flags_dot(const char *fmt, t_print *pstruct)
{
	pstruct->flags.dot = 1;
	pstruct->i++;
	if (fmt[pstruct->i] == '*')
		ft_flags_precision(fmt, pstruct, 1);
	else
		ft_flags_precision(fmt, pstruct, 0);
}

void	ft_flags(const char *fmt, t_print *pstruct)
{
	while (!ft_strchr(SPECIFIER, fmt[pstruct->i]))
	{
		if (fmt[pstruct->i] == '0')
		{
			pstruct->flags.zero = 1;
			pstruct->i++;
		}
		if (fmt[pstruct->i] == '-')
		{
			pstruct->flags.ljust = 1;
			pstruct->i++;
			if (fmt[pstruct->i] == '0')
				pstruct->i++;
		}
		if (fmt[pstruct->i] == '*')
			ft_flags_width(fmt, pstruct, 1);
		else if (fmt[pstruct->i] > '0' && fmt[pstruct->i] <= '9')
			ft_flags_width(fmt, pstruct, 0);
		if (fmt[pstruct->i] == '.')
			ft_flags_dot(fmt, pstruct);
		if (!ft_strchr(FLAGS, fmt[pstruct->i]))
			break ;
	}
}
