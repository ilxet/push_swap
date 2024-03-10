/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_the_best_move.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadamik <aadamik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 16:20:02 by aadamik           #+#    #+#             */
/*   Updated: 2024/03/07 01:04:54 by aadamik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_both_helper3(t_node *curr, t_node **a, t_node **b)
{
	while (curr->index > 0 && curr->target_t_node->index > 0)
	{
		ft_printf("rr\n");
		rotate(a);
		rotate(b);
		get_index(*a);
		get_index(*b);
	}
}

void	rotate_both(t_node **a, t_node **b, t_node *curr)
{
	int	lena;
	int	lenb;

	lena = get_size(a);
	lenb = get_size(b);
	if (((curr->above_median == 0 && curr->target_t_node->above_median == 0)
			|| (curr->above_median == 0
				&& curr->target_t_node->index <= curr->index))
		&& (curr->index > 0 && curr->target_t_node->index > 0))
		rotate_both_helper3(curr, a, b);
	else if ((curr->above_median == 1 && curr->target_t_node->above_median == 1)
		|| (curr->above_median == 1
			&& lenb - curr->target_t_node->index <= lena - curr->index))
	{
		while (curr->index != 0 && curr->target_t_node->index != 0)
		{
			ft_printf("rrr\n");
			rev_rotate(a);
			rev_rotate(b);
			get_index(*a);
			get_index(*b);
		}
	}
}

void	do_the_best_move(t_node **a, t_node **b, t_node *curr)
{
	rotate_both(a, b, curr);
	rotate_single(a, b, curr);
	ft_printf("pb\n");
	push(a, b);
}

void	do_the_best_move_b(t_node **a, t_node **b, t_node *curr)
{
	rotate_both(a, b, curr);
	rotate_single_b(a, b, curr);
	ft_printf("pa\n");
	push(b, a);
}

void	get_values2(t_node **a, t_node **b)
{
	get_target_t_node(*a, *b);
	get_index(*a);
	get_index(*b);
	get_median(*a);
	get_median(*b);
	get_cost_a(*a, *b);
	fill_cheapest(*a);
	get_the_cheapest(*a);
}
