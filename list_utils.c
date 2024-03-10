/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadamik <aadamik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 22:56:39 by aadamik           #+#    #+#             */
/*   Updated: 2024/03/06 22:02:01 by aadamik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_size(t_node **tail)
{
	t_node	*curr;
	int		size;

	size = 0;
	curr = *tail;
	while (curr)
	{
		size++;
		curr = curr->next;
	}
	return (size);
}

void	swap(t_node **tail)
{
	t_node	*temp;

	if (*tail == NULL || (*tail)->next == NULL)
		return ;
	temp = *tail;
	*tail = (*tail)->next;
	temp->next = (*tail)->next;
	(*tail)->next = temp;
	(*tail)->prev = NULL;
	(*tail)->next->prev = *tail;
	if (temp->next != NULL)
		temp->next->prev = temp;
	return ;
}

void	del_last(t_node **tail)
{
	t_node	*temp;

	if (*tail == NULL)
		return ;
	if ((*tail)->next == NULL)
	{
		free(*tail);
		*tail = NULL;
		return ;
	}
	else
	{
		temp = *tail;
		while (temp->next != NULL)
			temp = temp->next;
		if (temp->prev != NULL)
			temp->prev->next = NULL;
		free(temp);
		temp = NULL;
		return ;
	}
}

void	del_first(t_node **tail)
{
	t_node	*temp;

	if (*tail == NULL)
		return ;
	temp = *tail;
	if ((*tail)->next == NULL)
	{
		free(*tail);
		*tail = NULL;
		return ;
	}
	*tail = (*tail)->next;
	free(temp);
	temp = NULL;
	if (*tail != NULL)
		(*tail)->prev = NULL;
	return ;
}

void	insert_end(int value, t_node **tail)
{
	t_node	*new_t_node;
	t_node	*last;

	new_t_node = malloc(sizeof(t_node));
	if (new_t_node == NULL)
		return ;
	new_t_node->nb = value;
	new_t_node->next = NULL;
	new_t_node->index = 0;
	new_t_node->above_median = 0;
	if (*tail == NULL)
	{
		new_t_node->prev = NULL;
		*tail = new_t_node;
		return ;
	}
	last = *tail;
	while (last->next != NULL)
		last = last->next;
	last->next = new_t_node;
	new_t_node->prev = last;
	return ;
}
