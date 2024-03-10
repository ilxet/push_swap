/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadamik <aadamik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 23:05:56 by aadamik           #+#    #+#             */
/*   Updated: 2024/03/07 18:16:19 by aadamik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	insert_beginning(int value, t_node **tail)
{
	t_node	*new_t_node;

	new_t_node = malloc(sizeof(t_node));
	if (new_t_node == NULL)
		return ;
	new_t_node->nb = value;
	new_t_node->prev = NULL;
	new_t_node->next = *tail;
	new_t_node->index = 0;
	new_t_node->above_median = 0;
	if (*tail != NULL)
		(*tail)->prev = new_t_node;
	*tail = new_t_node;
	return ;
}

void	make_link_list(char **args, t_node **a)
{
	int	i;

	i = 0;
	while (args[i])
		i++;
	i--;
	while (i >= 0)
	{
		insert_beginning(ft_atoi(args[i]), a);
		i--;
	}
	return ;
}

void	rotate(t_node **tail)
{
	insert_end((*tail)->nb, tail);
	del_first(tail);
}

void	rev_rotate(t_node **tail)
{
	t_node	*last;
	t_node	*second_to_last;

	if (*tail == NULL || (*tail)->next == NULL)
		return ;
	last = *tail;
	while (last->next != NULL)
	{
		second_to_last = last;
		last = last->next;
	}
	second_to_last->next = NULL;
	last->next = *tail;
	*tail = last;
}

void	push(t_node **a, t_node **b)
{
	insert_beginning((*a)->nb, b);
	del_first(a);
}
