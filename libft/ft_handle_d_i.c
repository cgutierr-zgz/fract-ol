/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_d_i.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgutierr <cgutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 16:38:02 by cgutierr          #+#    #+#             */
/*   Updated: 2021/03/08 20:01:41 by cgutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	d_i_ljust(t_print *pstruct, char *str, int len, int num)
{
	int	i;

	i = 0;
	if (num < 0)
		pstruct->n += write(1, "-", 1);
	pstruct->flags.precss -= len;
	while (pstruct->flags.precss-- > 0)
		pstruct->n += write(1, "0", 1);
	while (i < len)
		pstruct->n += write(1, &str[i++], 1);
	while (pstruct->flags.width-- > 0)
		pstruct->n += write(1, " ", 1);
}

static void	d_i_no_ljust2(t_print *pstruct, int num)
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
		if (num < 0)
			pstruct->n += write(1, "-", 1);
	}
}

static void	d_i_no_ljust(t_print *pstruct, char *str, int len, int num)
{
	int	i;

	i = 0;
	d_i_no_ljust2(pstruct, num);
	pstruct->flags.precss -= len;
	while (pstruct->flags.precss-- > 0)
		pstruct->n += write(1, "0", 1);
	while (i < len)
		pstruct->n += write(1, &str[i++], 1);
}

static void	ft_handle_d_i2(t_print *pstruct, char *str, int len, int num)
{
	if (num < 0)
		pstruct->flags.width--;
	if (len <= pstruct->flags.precss)
		pstruct->flags.width -= pstruct->flags.precss;
	else
		pstruct->flags.width -= len;
	if (!pstruct->flags.ljust)
		d_i_no_ljust(pstruct, str, len, num);
	else
		d_i_ljust(pstruct, str, len, num);
}

void	ft_handle_d_i(t_print *pstruct)
{
	int				num;
	int				len;
	char			*str;
	unsigned int	nn;

	num = va_arg(pstruct->ap, int);
	if (num < 0)
		nn = num * -1;
	else
		nn = num;
	if (num == (-2147483648))
		str = "2147483648";
	else
		str = ft_itoa(nn);
	len = ft_strlen(str);
	if (num == 0 && pstruct->flags.dot && pstruct->flags.precss == 0)
		while (pstruct->flags.width-- > 0)
			pstruct->n += write(1, " ", 1);
	else
		ft_handle_d_i2(pstruct, str, len, num);
	if (num != (-2147483648))
		free(str);
}
