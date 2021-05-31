/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgutierr <cgutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/30 11:40:00 by cgutierr          #+#    #+#             */
/*   Updated: 2021/03/08 18:16:23 by cgutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Asignamos memoria a un array con [count] elementos de tamaño [size] cada uno
**
** ·1) Devolvemos un puntero a la memoria almacenada.
** ·2) Esta se pone a 0
**
** ·!) Si [count] o [size] es igual a 0, se devuelve o NULL o un puntero que
**		posteriormente pueda ser free()
**
** ·!) Hacemos uso de la función "malloc" gracias a la librería <stdlib.h>
*/

void	*ft_calloc(size_t count, size_t size)
{
	void	*result;
	size_t	i;

	result = (void *)malloc(size * count);
	if (!(result))
		return (NULL);
	i = 0;
	while (i < count * size)
	{
		((char *)result)[i] = 0;
		i++;
	}
	return (result);
}
