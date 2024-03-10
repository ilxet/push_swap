/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_single_b.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadamik <aadamik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 16:05:24 by aadamik           #+#    #+#             */
/*   Updated: 2024/03/06 22:13:08 by aadamik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_single_b_helper(t_node **b, t_node *curr)
{
	while (curr->index > 0)
	{
		ft_printf("rb\n");
		rotate(b);
		get_index(*b);
	}
}

void	rotate_single_helper_b_2(t_node **b, t_node *curr)
{
	while (curr->index != 0)
	{
		ft_printf("rrb\n");
		rev_rotate(b);
		get_index(*b);
	}
}

void	rotate_single_b(t_node **a, t_node **b, t_node *curr)
{
	if (curr->above_median == 0)
		rotate_single_b_helper(b, curr);
	else if (curr->above_median == 1)
		rotate_single_helper_b_2(b, curr);
	if (curr->target_t_node->above_median == 0)
	{
		while (curr->target_t_node->index > 0)
		{
			ft_printf("ra\n");
			rotate(a);
			get_index(*a);
		}
	}
	else if (curr->target_t_node->above_median == 1)
	{
		while (curr->target_t_node->index != 0)
		{
			ft_printf("rra\n");
			rev_rotate(a);
			get_index(*a);
		}
	}
}
