/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spain.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgutierr <cgutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 12:40:20 by cgutierr          #+#    #+#             */
/*   Updated: 2021/04/01 17:20:32 by cgutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	spain_text(void)
{
	printf("\t\t _  __   _______   ___     ");
	printf("___ ___ ___  _    /\\/|  _     _ \n");
	printf("\t\t(_) \\ \\ / /_ _\\ \\ / /_\\");
	printf("   | __/ __| _ \\/_\\  |/\\/  /_");
	printf("\\   | |\n");
	printf("\t\t| |  \\ V / | | \\ V / _ \\  ");
	printf("| _|\\__ \\  _/ _ \\| \\| |/ _ \\  |_|\n");
	printf("\t\t|_|   \\_/ |___| \\_/_/ \\_\\ ");
	printf("|___|___/_|/_/ \\_\\_|\\_/_/ \\_\\ (_)\n");
}

void	spain(void)
{
	int	z;

	spain_text();
	z = 0;
	while (z < 5)
	{
		printf(W_B_RED "\t                                      " RESET);
		printf(W_B_RED "                                      " RESET "\n");
		z++;
	}
	z = 0;
	while (z < 7)
	{
		printf(W_B_YELLOW "\t                                      " RESET);
		printf(W_B_YELLOW "                                      " RESET "\n");
		z++;
	}
	z = 0;
	while (z < 5)
	{
		printf(W_B_RED "\t                                      " RESET);
		printf(W_B_RED "                                      " RESET "\n");
		z++;
	}
}
