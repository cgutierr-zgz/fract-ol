/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bits.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgutierr <cgutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 13:49:28 by cgutierr          #+#    #+#             */
/*   Updated: 2021/03/26 12:40:34 by cgutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

int	set_bit(int value, int index)
{
	return (value | index);
}

int	reset_bit(int value, int index)
{
	return (value & ~index);
}

int	is_bit_set(int value, int bitindex)
{
	return ((value & bitindex) == bitindex);
}
