/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgutierr <cgutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 16:38:02 by cgutierr          #+#    #+#             */
/*   Updated: 2021/03/08 20:04:44 by cgutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	p_ljust(t_print *pstruct, char *str, int len)
{
	int	i;

	i = 0;
	pstruct->n += write(1, "0x", 2);
	pstruct->flags.precss -= len;
	while (pstruct->flags.precss-- > 0)
		pstruct->n += write(1, "0", 1);
	while (i < len)
		pstruct->n += write(1, &str[i++], 1);
	while (pstruct->flags.width-- > 0)
		pstruct->n += write(1, " ", 1);
}

static void	p_cerox(t_print *pstruct)
{
	pstruct->n += write(1, "0x", 2);
	pstruct->flags.cerox = 1;
}

static void	p_no_ljust2(t_print *pstruct)
{
	if (pstruct->flags.width && pstruct->flags.zero && !pstruct->flags.dot)
	{
		if (!pstruct->flags.cerox)
			p_cerox(pstruct);
		while (pstruct->flags.width-- > 0)
			pstruct->n += write(1, "0", 1);
	}
	else
	{
		while (pstruct->flags.width-- > 0)
		{
			if (!pstruct->flags.zero || pstruct->flags.dot)
				pstruct->n += write(1, " ", 1);
			else
			{
				if (!pstruct->flags.cerox)
					p_cerox(pstruct);
				pstruct->n += write(1, "0", 1);
			}
		}
	}
}

static void	p_no_ljust(t_print *pstruct, char *str, int len)
{
	int	i;

	i = 0;
	p_no_ljust2(pstruct);
	pstruct->flags.precss -= len;
	if (!pstruct->flags.cerox)
		p_cerox(pstruct);
	while (pstruct->flags.precss-- > 0)
		pstruct->n += write(1, "0", 1);
	while (i < len)
		pstruct->n += write(1, &str[i++], 1);
}

void	ft_handle_p(t_print *pstruct)
{
	unsigned long long	p;
	char				*str;
	unsigned int		len;

	p = va_arg(pstruct->ap, unsigned long long);
	str = ft_itoa_base(p, "0123456789abcdef");
	len = ft_strlen(str);
	pstruct->flags.cerox = 0;
	if (pstruct->flags.precss < 0)
		pstruct->flags.width -= len + 2;
	else if (len <= (unsigned int)pstruct->flags.precss)
		pstruct->flags.width -= pstruct->flags.precss + 2;
	else
		pstruct->flags.width -= len + 2;
	if (!pstruct->flags.ljust)
		p_no_ljust(pstruct, str, len);
	else
		p_ljust(pstruct, str, len);
	free(str);
}
