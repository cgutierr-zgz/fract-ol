/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgutierr <cgutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 10:10:54 by cgutierr          #+#    #+#             */
/*   Updated: 2020/07/11 22:36:56 by cgutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Escribimos el número [n] en el directorio [fd]
**
** ·1) Creamos un array de chars con tamaño 10
**		(Max+Int = 2147483648 | Max-Int = -2147483648)
** ·2) Comprobamos que [n] no sea 0 o Max-Int, de ser así escribimos esos
**		casos en particular a mano
** ·3) Posteriormente si no se ha dado el caso anterior, se comprueba que
**		[n] no sea negativo, de ser así, de nuevo, escribimos '-' a mano
** ·4) Ahora ya vamos avanzando siempre que [n] sea mayor que 0
**		Lo que hacemos es asignar a ese array de chars el valor del
**		último número (123)->c[0] = 3, c[1] = 2, c[0] = 1
** ·5) Luego vamos imprimiendo la cadena inversamente, gracias a tener [i]
**		en el final de la cadena, tansolo vamos restando y retrocediendo
*/

void	ft_putnbr_fd(int n, int fd)
{
	int		i;
	char	c[10];

	if (n == 0)
		return (ft_putchar_fd('0', fd));
	if (n == -2147483648)
		return (ft_putstr_fd("-2147483648", fd));
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n *= -1;
	}
	i = 0;
	while (n > 0)
	{
		c[i] = n % 10 + '0';
		n /= 10;
		i++;
	}
	i--;
	while (i >= 0)
		ft_putchar_fd(c[i--], fd);
}
