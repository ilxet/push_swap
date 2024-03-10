/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_issort_flowest.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadamik <aadamik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 17:38:20 by aadamik           #+#    #+#             */
/*   Updated: 2024/03/07 02:01:48 by aadamik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*find_lowest(t_node	*a)
{
	t_node	*curr;
	t_node	*lowest;

	curr = a;
	lowest = a;
	while (curr)
	{
		if (curr->nb < lowest->nb)
			lowest = curr;
		curr = curr->next;
	}
	return (lowest);
}

int	list_is_sorted(t_node *a)
{
	t_node	*curr;

	curr = a;
	while (curr->next)
	{
		if (curr->nb > curr->next->nb)
			return (0);
		curr = curr->next;
	}
	return (1);
}

void	free_list(t_node *node)
{
	t_node	*next;

	while (node)
	{
		next = node->next;
		free(node);
		node = next;
	}
}

void	free_array(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}
