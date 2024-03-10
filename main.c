/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadamik <aadamik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 12:57:07 by aadamik           #+#    #+#             */
/*   Updated: 2024/03/10 14:36:28 by aadamik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_to_b_until_three(t_node **a, t_node **b)
{
	t_node	*curr;

	curr = *a;
	while (get_size(a) > 3 && get_size(b) < 2)
	{
		push(a, b);
		ft_printf("pb\n");
	}
	curr = *a;
	while (get_size(a) > 3)
	{
		get_values2(a, b);
		curr = *a;
		while (curr->cheapest != 1)
		{
			curr = curr->next;
		}
		do_the_best_move(a, b, curr);
		curr = *a;
	}
	return ;
}

void	push_to_a(t_node **a, t_node **b)
{
	t_node	*curr;

	if (a == NULL || b == NULL)
		return ;
	curr = *b;
	while (get_size(b) > 0)
	{
		get_target_t_node_for_b(*a, *b);
		get_index(*a);
		get_index(*b);
		get_median(*a);
		get_median(*b);
		get_cost_a(*b, *a);
		fill_cheapest(*b);
		get_the_cheapest(*b);
		while (curr->cheapest != 1)
		{
			curr = curr->next;
		}
		do_the_best_move_b(a, b, curr);
		curr = *b;
	}
}

void	put_the_smallest_first(t_node **a)
{
	t_node	*curr;
	t_node	*smallest;

	get_median(*a);
	curr = *a;
	smallest = *a;
	while (curr)
	{
		if (curr->nb < smallest->nb)
			smallest = curr;
		curr = curr->next;
	}
	while ((*a)->nb != smallest->nb)
	{
		if (smallest->above_median == 0)
		{
			rotate(a);
			ft_printf("ra\n");
		}
		else if (smallest->above_median == 1)
		{
			rev_rotate(a);
			ft_printf("rra\n");
		}
	}
}

void	sort_list(t_node **a, t_node **b)
{
	if (get_size(a) == 1)
		return ;
	else if (get_size(a) == 2)
	{
		if ((*a)->nb > (*a)->next->nb)
		{
			swap(a);
			ft_printf("sa\n");
		}
		return ;
	}
	if (get_size(a) > 3)
		push_to_b_until_three(a, b);
	if (get_size(a) == 3)
	{
		sort_three(a);
	}
	push_to_a(a, b);
	put_the_smallest_first(a);
	return ;
}

int	main(int argc, char **argv)
{
	t_node	*a;
	t_node	*b;
	char	**args;

	a = NULL;
	b = NULL;
	if (argc == 1)
		return (1);
	if (ft_iferror(argc, argv))
		return (ft_printf("Error\n"), 1);
	if (argc == 2)
		args = ft_split(argv[1], ' ');
	else
		args = argv + 1;
	make_link_list(args, &a);
	if (list_is_sorted(a))
		return (helper_main(a, argc, args));
	sort_list(&a, &b);
	free_list(a);
	if (argc == 2)
		free_array(args);
	return (0);
}
