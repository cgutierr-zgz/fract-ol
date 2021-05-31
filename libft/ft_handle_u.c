/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgutierr <cgutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 20:08:14 by cgutierr          #+#    #+#             */
/*   Updated: 2021/03/08 20:01:48 by cgutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	u_ljust(t_print *pstruct, char *str, int len, unsigned int num)
{
	int	i;

	i = 0;
	pstruct->flags.precss -= len;
	while (pstruct->flags.precss-- > 0)
		pstruct->n += write(1, "0", 1);
	if (num == 4294967295u)
		pstruct->n += write(1, "4294967295", 10);
	else
		while (i < len)
			pstruct->n += write(1, &str[i++], 1);
	while (pstruct->flags.width-- > 0)
		pstruct->n += write(1, " ", 1);
}

static void	u_no_ljust2(t_print *pstruct, char *str, int len, unsigned int num)
{
	int	i;

	i = 0;
	pstruct->flags.precss -= len;
	while (pstruct->flags.precss-- > 0)
		pstruct->n += write(1, "0", 1);
	if (num == 4294967295u)
		pstruct->n += write(1, "4294967295", 10);
	else
		while (i < len)
			pstruct->n += write(1, &str[i++], 1);
}

static void	u_no_ljust(t_print *pstruct, char *str, int len, unsigned int num)
{
	if (pstruct->flags.width && pstruct->flags.zero && !pstruct->flags.dot)
	{
		if (num < 0)
			pstruct->n += write(1, "-", 1);
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
				pstruct->n += write(1, "0", 1);
		}
	}
	u_no_ljust2(pstruct, str, len, num);
}

void	ft_handle_u(t_print *pstruct)
{
	unsigned int	num;
	int				len;
	char			*str;

	num = va_arg(pstruct->ap, unsigned int);
	str = ft_itoa_u(num);
	len = ft_strlen(str);
	if (num == 0 && pstruct->flags.dot && pstruct->flags.precss == 0)
		while (pstruct->flags.width-- > 0)
			pstruct->n += write(1, " ", 1);
	else
	{
		if (num < 0)
			pstruct->flags.width--;
		if (len <= pstruct->flags.precss)
			pstruct->flags.width -= pstruct->flags.precss;
		else
			pstruct->flags.width -= len;
		if (!pstruct->flags.ljust)
			u_no_ljust(pstruct, str, len, num);
		else
			u_ljust(pstruct, str, len, num);
	}
	free(str);
}
