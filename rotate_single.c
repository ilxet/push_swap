/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_single.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadamik <aadamik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 15:46:18 by aadamik           #+#    #+#             */
/*   Updated: 2024/03/06 22:09:03 by aadamik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_single_helper(t_node **a, t_node *curr)
{
	while (curr->index > 0)
	{
		ft_printf("ra\n");
		rotate(a);
		get_index(*a);
	}
}

void	rotate_single_helper_2(t_node **a, t_node *curr)
{
	while (curr->index != 0)
	{
		ft_printf("rra\n");
		rev_rotate(a);
		get_index(*a);
	}
}

void	rotate_single(t_node **a, t_node **b, t_node *curr)
{
	if (curr->above_median == 0)
		rotate_single_helper(a, curr);
	else if (curr->above_median == 1)
		rotate_single_helper_2(a, curr);
	if (curr->target_t_node->above_median == 0)
	{
		while (curr->target_t_node->index > 0)
		{
			ft_printf("rb\n");
			rotate(b);
			get_index(*b);
		}
	}
	else if (curr->target_t_node->above_median == 1)
	{
		while (curr->target_t_node->index != 0)
		{
			ft_printf("rrb\n");
			rev_rotate(b);
			get_index(*b);
		}
	}
}
