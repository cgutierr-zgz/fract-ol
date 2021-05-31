/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_trimmedstr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgutierr <cgutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 18:53:36 by cgutierr          #+#    #+#             */
/*   Updated: 2021/03/12 12:02:55 by cgutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	aux(char *new, char *str)
{
	int	i;

	i = 0;
	while (*str)
	{
		if (!ft_isspace(*str))
		{
			new[i] = *str;
			i++;
		}
		str++;
	}
	new[i] = '\0';
}

char	*ft_trimmedstr(char *str)
{
	char	*new;
	int		len;
	int		i;

	i = 0;
	len = 0;
	while (str[i])
	{
		if (!ft_isspace(str[i]))
			len++;
		i++;
	}
	new = (char *)malloc(sizeof(char) * len + 1);
	if (!new)
		return (NULL);
	aux(new, str);
	return (new);
}
