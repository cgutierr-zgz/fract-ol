/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgutierr <cgutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 10:08:12 by cgutierr          #+#    #+#             */
/*   Updated: 2020/07/10 17:11:17 by cgutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Escribimos el la cadena [s] en el directorio [fd]
**
** ·1) Vamos avanzando en la cadena [s] hasta llegar al final '\0'
**		y vamos escribiendo s[i] en fd haciendo uso de "ft_putstr_fd"
** ·2) Finalmente hacemos uso de "ft_putchar_fd" para añadir el salto de
**		linea final '\n' en el directorio [fd]
*/

void	ft_putendl_fd(char *s, int fd)
{
	ft_putstr_fd(s, fd);
	ft_putchar_fd('\n', fd);
}
