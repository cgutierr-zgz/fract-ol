/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countchar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgutierr <cgutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 17:42:04 by cgutierr          #+#    #+#             */
/*   Updated: 2021/03/16 18:13:58 by cgutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_countchar(char *str, char c)
{
	int	chars;

	chars = 0;
	while (*str)
	{
		if (*str == c)
			chars++;
		str++;
	}
	return (chars);
}
