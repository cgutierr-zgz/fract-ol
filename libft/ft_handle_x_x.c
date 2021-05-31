/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_x_x.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgutierr <cgutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 16:38:02 by cgutierr          #+#    #+#             */
/*   Updated: 2021/03/08 20:04:27 by cgutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	p_ljust(t_print *pstruct, char *str, int len)
{
	int	i;

	i = 0;
	pstruct->flags.precss -= len;
	while (pstruct->flags.precss-- > 0)
		pstruct->n += write(1, "0", 1);
	while (i < len)
		pstruct->n += write(1, &str[i++], 1);
	while (pstruct->flags.width-- > 0)
		pstruct->n += write(1, " ", 1);
}

static void	p_no_ljust2(t_print *pstruct)
{
	if (pstruct->flags.width && pstruct->flags.zero && !pstruct->flags.dot)
		while (pstruct->flags.width-- > 0)
			pstruct->n += write(1, "0", 1);
	else
	{
		while (pstruct->flags.width-- > 0)
		{
			if (!pstruct->flags.zero || pstruct->flags.dot)
				pstruct->n += write(1, " ", 1);
			else
				pstruct->n += write(1, "0", 1);
		}
	}
}

static void	p_no_ljust(t_print *pstruct, char *str, int len)
{
	int	i;

	i = 0;
	p_no_ljust2(pstruct);
	pstruct->flags.precss -= len;
	while (pstruct->flags.precss-- > 0)
		pstruct->n += write(1, "0", 1);
	while (i < len)
		pstruct->n += write(1, &str[i++], 1);
}

void	ft_handle_x_x(t_print *pstruct, char c)
{
	unsigned int	hex;
	char			*str;
	unsigned int	len;

	hex = va_arg(pstruct->ap, unsigned int);
	if (c == 'X')
		str = ft_itoa_base(hex, "0123456789ABCDEF");
	else
		str = ft_itoa_base(hex, "0123456789abcdef");
	len = ft_strlen(str);
	if (hex == 0 && pstruct->flags.dot && pstruct->flags.precss == 0)
		len = 0;
	else if (pstruct->flags.precss == 0 && pstruct->flags.dot)
		pstruct->flags.width -= len;
	else if (pstruct->flags.precss < 0)
		pstruct->flags.width -= len;
	else if (len <= (unsigned int)pstruct->flags.precss)
		pstruct->flags.width -= pstruct->flags.precss;
	else
		pstruct->flags.width -= len;
	if (!pstruct->flags.ljust)
		p_no_ljust(pstruct, str, len);
	else
		p_ljust(pstruct, str, len);
	free(str);
}
