/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubble_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgutierr <cgutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 19:07:40 by cgutierr          #+#    #+#             */
/*   Updated: 2021/04/23 09:37:10 by cgutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

/*
** Function to insert a node at the beginning of a linked list
*/

void	ft_lst_insert_begin(t_list **start_ref, void *data)
{
	t_list	*ptr1;

	ptr1 = (t_list *)malloc(sizeof(t_list));
	ptr1->content = data;
	ptr1->next = *start_ref;
	*start_ref = ptr1;
}

/*
** Function to print nodes in a given linked list
*/

void	printlist(t_list *start)
{
	t_list		*temp;
	t_sprite	*sopa;

	temp = start;
	printf("\n");
	while (temp != NULL)
	{
		sopa = temp->content;
		printf("[%f]\n", sopa->dist);
		temp = temp->next;
	}
	printf("\n\n");
}

/*
** Function to swap data of two nodes a and b
*/

static void	swap(t_list *a, t_list *b)
{
	void	*temp;

	temp = a->content;
	a->content = b->content;
	b->content = temp;
}

/*
** Bubble sort the given linked list
*/
static void
	sopa(t_list **ptr1, t_sprite **sprite1, t_sprite **sprite2, int *swapped)
{
	*sprite1 = (*ptr1)->content;
	*sprite2 = (*ptr1)->next->content;
	if ((*sprite1)->dist < (*sprite2)->dist)
	{
		swap(*ptr1, (*ptr1)->next);
		*swapped = 1;
	}
	*ptr1 = (*ptr1)->next;
}

void	bubble_sort(t_list *start)
{
	int			swapped;
	t_list		*ptr1;
	t_list		*lptr;
	t_sprite	*sprite1;
	t_sprite	*sprite2;

	lptr = NULL;
	if (start == NULL)
		return ;
	swapped = 0;
	ptr1 = start;
	while (ptr1->next != lptr)
	{
		sopa(&ptr1, &sprite1, &sprite2, &swapped);
	}
	while (swapped)
	{
		swapped = 0;
		ptr1 = start;
		while (ptr1->next != lptr)
		{
			sopa(&ptr1, &sprite1, &sprite2, &swapped);
		}
	}
}
