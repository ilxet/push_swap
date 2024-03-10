/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_values.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadamik <aadamik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 15:32:05 by aadamik           #+#    #+#             */
/*   Updated: 2024/03/07 19:17:07 by aadamik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_target_t_node(t_node *a, t_node *b)
{
	t_node	*curr_b;
	t_node	*target_t_node;
	int		current_lower_nb;

	while (a)
	{
		curr_b = b;
		current_lower_nb = -2147483648;
		while (curr_b)
		{
			if (curr_b->nb > current_lower_nb && curr_b->nb < a->nb)
			{
				current_lower_nb = curr_b->nb;
				target_t_node = curr_b;
			}
			curr_b = curr_b->next;
		}
		if (current_lower_nb == -2147483648)
			a->target_t_node = find_highest(b);
		else
			a->target_t_node = target_t_node;
		a = a->next;
	}
	return ;
}

void	get_index(t_node *a)
{
	t_node	*curr;
	int		pos;

	pos = 0;
	curr = a;
	while (curr)
	{
		curr->index = pos;
		pos++;
		curr = curr->next;
	}
	return ;
}

void	get_median(t_node *a)
{
	t_node	*curr;
	int		size;

	size = get_size(&a);
	curr = a;
	while (curr)
	{
		if (curr->index + 1 <= size / 2)
			curr->above_median = 0;
		else
			curr->above_median = 1;
		curr = curr->next;
	}
	return ;
}

void	get_cost_a(t_node *a, t_node *b)
{
	int	lena;
	int	lenb;

	if (a == NULL || b == NULL)
		return ;
	lena = get_size(&a);
	lenb = get_size(&b);
	while (a)
	{
		a->cost = a->index;
		if (a->above_median == 1)
			a->cost = lena - a->index;
		if (a->target_t_node->above_median == 1)
			a->cost += lenb - a->target_t_node->index;
		else
			a->cost += a->target_t_node->index;
		a = a->next;
	}
}

void	get_the_cheapest(t_node *a)
{
	t_node	*curr;
	int		cheapest;

	curr = a;
	cheapest = 2147483647;
	while (curr)
	{
		if (curr->cost < cheapest)
			cheapest = curr->cost;
		curr = curr->next;
	}
	curr = a;
	while (curr)
	{
		if (curr->cost == cheapest)
		{
			curr->cheapest = 1;
			return ;
		}
		curr = curr->next;
	}
}
