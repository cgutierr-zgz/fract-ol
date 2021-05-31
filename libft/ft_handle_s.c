/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgutierr <cgutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 16:38:02 by cgutierr          #+#    #+#             */
/*   Updated: 2021/03/08 20:01:46 by cgutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	s_ljust(t_print *pstruct, char *str, int len)
{
	pstruct->n += write(1, str, len);
	while (pstruct->flags.width > len)
	{
		pstruct->n += write(1, " ", 1);
		pstruct->flags.width--;
	}
}

static void	s_no_ljust(t_print *pstruct, char *str, int len)
{
	if (pstruct->flags.width > len)
	{
		while ((pstruct->flags.width - len) > 0)
		{
			if (pstruct->flags.zero)
				pstruct->n += write(1, "0", 1);
			else
				pstruct->n += write(1, " ", 1);
			pstruct->flags.width--;
		}
	}
	pstruct->n += write(1, str, len);
}

void	ft_handle_s(t_print *pstruct)
{
	char	*str;
	int		len;

	str = va_arg(pstruct->ap, char *);
	if (!str)
		str = "(null)";
	len = ft_strlen(str);
	if (pstruct->flags.dot && len > pstruct->flags.precss)
		len = pstruct->flags.precss;
	if (pstruct->flags.ljust)
		s_ljust(pstruct, str, len);
	else
		s_no_ljust(pstruct, str, len);
}
