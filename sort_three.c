/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadamik <aadamik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 17:29:15 by aadamik           #+#    #+#             */
/*   Updated: 2024/03/07 01:53:56 by aadamik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three_helper(t_node **a)
{
	swap(a);
	ft_printf("sa\n");
	rev_rotate(a);
	ft_printf("rra\n");
}

void	sort_three_helper_2(t_node **a)
{
	swap(a);
	ft_printf("sa\n");
	rotate(a);
	ft_printf("ra\n");
}

void	sort_three(t_node **a)
{
	if ((*a)->nb > (*a)->next->nb && (*a)->nb < (*a)->next->next->nb)
	{
		swap(a);
		ft_printf("sa\n");
	}
	else if ((*a)->next->nb > (*a)->next->next->nb && (*a)->next->nb < (*a)->nb)
		sort_three_helper(a);
	else if ((*a)->nb > (*a)->next->next->nb && (*a)->nb < (*a)->next->nb)
	{
		rev_rotate(a);
		ft_printf("rra\n");
	}
	else if ((*a)->nb < (*a)->next->next->nb
		&& (*a)->next->nb > (*a)->next->next->nb)
		sort_three_helper_2(a);
	else if ((*a)->nb > (*a)->next->next->nb
		&& (*a)->next->nb < (*a)->next->next->nb)
	{
		rotate(a);
		ft_printf("ra\n");
	}
	return ;
}

t_node	*find_highest(t_node *b)
{
	t_node	*curr;
	t_node	*highest;

	curr = b;
	highest = b;
	while (curr)
	{
		if (curr->nb > highest->nb)
			highest = curr;
		curr = curr->next;
	}
	return (highest);
}

void	fill_cheapest(t_node *a)
{
	t_node	*curr;

	curr = a;
	while (curr)
	{
		curr->cheapest = 0;
		curr = curr->next;
	}
}
