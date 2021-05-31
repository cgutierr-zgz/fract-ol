/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgutierr <cgutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/09 14:29:28 by cgutierr          #+#    #+#             */
/*   Updated: 2021/03/08 18:13:42 by cgutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Troceado de String en varios Strings, usando [c] como delimitador
**
** ·1) Se comprueba que no de la asignación de memoria, [s] y [c] no sea
**		NULL, de ser así se devolvería NULL
** ·2) Entramos n veces en un bucle que obtenemos al saber cuantos Strings
**		hay en [s] limitándolo con [c] gracias a "ft_substrings"
** ·3) Vamos asignando memoria usando "ft_substrlen" que obtiene el tamaño de
**		un string avanzando a partir de un punto [k], hasta encontrar el
**		siguiente char [c], este malloc se le añade el + 1 para el '\0' final
** ·4) Seguimos avanzando y mientras s[k] sea [c] simplemente lo obviamos
** ·5) Mientras que s[k] no sea NULL ni igual a [c] vamos igualando
**		el string actual [i] [j++] a s[k++] y terminándolo con '\0'
** ·6) El bucle se va repitiendo con i++ hasta llegar al número de palabras
**		obtenidas con "ft_substrings"
** ·7) Se añade un último string NULL y ese array de Strings es lo que
**		se devuelve
**
*******************************************************************************
**									EJEMPLO								     **
*******************************************************************************
** Si enviamos:		char **str	=	ft_split("Hola,que,tal,estás",',')
** El resultado:	*str[0]		=	"Hola"
**					*str[1]		=	"que"
**					*str[2]		=	"tal"
**					*str[3]		=	"estás"
**					*str[4]		=	NULL
*/

static int	ef_number_str(char *s, char c)
{
	int	n_str;
	int	check;
	int	i;

	n_str = 0;
	check = 0;
	i = -1;
	if (s[0] == '\0')
		return (0);
	while (s[++i] != '\0')
	{
		if (s[i] == c)
			check = 0;
		else if (check++ == 0)
			n_str++;
	}
	return (n_str);
}

static char	**ef_free_ptr(char **ptr, int i)
{
	while (--i >= 0)
		free(ptr[i]);
	free(ptr);
	return (ptr);
}

static char	**ef_pass_values(char **ptr, char *s, char c, int n_str)
{
	int	i;
	int	j;
	int	k;

	i = -1;
	j = 0;
	while (j < n_str)
	{
		if (s[++i] != c)
		{
			k = 0;
			while (s[i] != c && s[i] != '\0')
				ptr[j][k++] = s[i++];
			ptr[j][k] = '\0';
			j++;
		}
	}
	ptr[j] = NULL;
	return (ptr);
}

static char	**ef_set_ptr(char **ptr, char *s, char c, int n_str)
{
	int	i;
	int	j;
	int	size;

	i = -1;
	j = 0;
	while (j < n_str)
	{
		if (s[++i] != c)
		{
			size = 0;
			while (s[i + size] != c && s[i + size] != '\0')
				size++;
			ptr[j] = (char *)malloc(size + 1);
			if (!ptr[j])
				return (ef_free_ptr(ptr, j));
			i += size;
			j++;
		}
	}
	ptr = ef_pass_values(ptr, s, c, n_str);
	return (ptr);
}

char	**ft_split(char const *s, char c)
{
	char	**ptr;
	int		n_str;

	if (!s)
		return (NULL);
	n_str = ef_number_str((char *)s, c);
	ptr = (char **)malloc(sizeof(char *) * (n_str + 1));
	if (!ptr)
		return (NULL);
	ptr = ef_set_ptr(ptr, (char *)s, c, n_str);
	return (ptr);
}
