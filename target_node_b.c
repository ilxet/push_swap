/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   target_node_b.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadamik <aadamik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 17:50:07 by aadamik           #+#    #+#             */
/*   Updated: 2024/03/10 14:30:05 by aadamik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_target_t_node_for_b(t_node *a, t_node *b)
{
	t_node	*curr_a;
	t_node	*target_t_node;
	int		current_higher_nb;

	while (b)
	{
		curr_a = a;
		current_higher_nb = 2147483647;
		while (curr_a)
		{
			if (curr_a->nb < current_higher_nb && curr_a->nb > b->nb)
			{
				current_higher_nb = curr_a->nb;
				target_t_node = curr_a;
			}
			curr_a = curr_a->next;
		}
		if (current_higher_nb == 2147483647)
			b->target_t_node = find_lowest(a);
		else
			b->target_t_node = target_t_node;
		b = b->next;
	}
}

int	helper_main(t_node *a, int argc, char **args)
{
	if (argc == 2)
		free_array(args);
	return (free_list(a), 0);
}
