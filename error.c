/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadamik <aadamik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 16:37:54 by aadamik           #+#    #+#             */
/*   Updated: 2024/03/07 17:58:20 by aadamik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_ifdigitarr(char **argv)
{
	while (*argv)
	{
		if (!ft_ifdigitstr(*argv))
			return (0);
		argv++;
	}
	return (1);
}

t_node	*create_t_node(int curr_val, t_node *repeats)
{
	t_node	*t_node;

	t_node = malloc(sizeof(t_node));
	if (t_node == NULL)
	{
		free_list(repeats);
		ft_printf("Error\n");
		exit(1);
	}
	t_node->nb = curr_val;
	t_node->next = repeats;
	return (t_node);
}

int	check_duplicate(t_node *repeats, int curr_val)
{
	t_node	*t_node;

	t_node = repeats;
	while (t_node)
	{
		if (t_node->nb == curr_val)
			return (1);
		t_node = t_node->next;
	}
	return (0);
}

int	ft_ifduparr(char **argv)
{
	char	**arr;
	t_node	*node;
	t_node	*repeats;
	int		curr_val;

	arr = argv;
	repeats = NULL;
	while (*arr)
	{
		curr_val = ft_atoi(*arr);
		node = repeats;
		if (check_duplicate(repeats, curr_val))
			return (free_list(repeats), 1);
		node = malloc(sizeof(t_node));
		node->nb = curr_val;
		node->next = repeats;
		if (repeats != NULL)
			repeats->prev = node;
		repeats = node;
		arr++;
	}
	free_list(repeats);
	return (0);
}

int	ft_ifintnbr(char *argv)
{
	long long	num;

	num = ft_atoi(argv);
	if (num > 2147483647 || num < -2147483648)
		return (0);
	return (1);
}
