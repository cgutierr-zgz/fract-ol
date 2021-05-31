/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgutierr <cgutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/28 19:33:44 by cgutierr          #+#    #+#             */
/*   Updated: 2021/03/08 18:17:20 by cgutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	number_digit(long n, int number_base)
{
	if (n < number_base)
		return (1);
	else
		return (1 + (number_digit(n / number_base, number_base)));
}

static char	*build_str(long num, char *str, char *base, int n_digit)
{
	int		i;
	long	div;

	div = ft_strlen(base);
	i = n_digit - 1;
	while (num >= div)
	{
		str[i--] = base[num % div];
		num /= div;
	}
	str[i] = base[num];
	str[n_digit] = '\0';
	return (str);
}

char	*ft_itoa_base(unsigned long long num, char *base)
{
	char	*str;
	size_t	size_base;
	int		n_digit;

	str = NULL;
	size_base = ft_strlen(base);
	if (!size_base)
		return (str);
	if (num < 0)
		num *= -1;
	n_digit = number_digit(num, size_base);
	str = (char *)malloc(n_digit + 1);
	if (!str)
		return (NULL);
	str = build_str(num, str, base, n_digit);
	return (str);
}
