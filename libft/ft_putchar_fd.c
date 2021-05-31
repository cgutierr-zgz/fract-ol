/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgutierr <cgutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 10:00:36 by cgutierr          #+#    #+#             */
/*   Updated: 2020/07/10 14:44:07 by cgutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Escribimos el char [c] en el directorio [fd]
**
** ·!) Hacemos uso de la función "write" gracias a la librería <unistd.h>
*/

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
