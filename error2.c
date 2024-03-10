/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadamik <aadamik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 16:50:19 by aadamik           #+#    #+#             */
/*   Updated: 2024/03/07 17:22:07 by aadamik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_ifdigitstr(char *argv)
{
	if (!*argv)
		return (0);
	while (*argv)
	{
		if (ft_isdigit(*argv) || *argv == ' '
			|| (*argv == '-' && ft_isdigit(*(argv + 1))))
			argv++;
		else
			return (0);
	}
	return (1);
}

t_node	*create_node(int curr_val, t_node *repeats)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (node == NULL)
	{
		ft_printf("Error\n");
		exit(1);
	}
	if (node == NULL)
	{
		ft_printf("Error\n");
		exit(1);
	}
	node->nb = curr_val;
	node->next = repeats;
	return (node);
}

int	ft_ifdupstr(char *argv)
{
	char	**arr;
	char	**arr_iter;
	t_node	*repeats;
	int		curr_val;

	arr = ft_split(argv, ' ');
	arr_iter = arr;
	repeats = NULL;
	while (*arr_iter)
	{
		curr_val = ft_atoi(*arr_iter);
		if (check_duplicate(repeats, curr_val))
			return (free_list(repeats), free_array(arr), 1);
		repeats = create_node(curr_val, repeats);
		arr_iter++;
	}
	free_list(repeats);
	free_array(arr);
	return (0);
}

int	ft_ifintarr(char **argv)
{
	while (*argv)
	{
		if (!ft_ifintnbr(*argv))
			return (0);
		argv++;
	}
	return (1);
}

int	ft_iferror(int argc, char **argv)
{
	if (argc < 2)
		return (0);
	if (argc == 2 && (!ft_ifdigitstr(argv[1])
			|| ft_ifdupstr(argv[1]) || !ft_ifintnbr(argv[1])))
		return (1);
	if (argc > 2 && (!ft_ifdigitarr(argv + 1)
			|| ft_ifduparr(argv + 1) || !ft_ifintarr(argv + 1)))
		return (1);
	return (0);
}
