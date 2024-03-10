/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadamik <aadamik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 13:26:10 by aadamik           #+#    #+#             */
/*   Updated: 2024/03/10 14:36:18 by aadamik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ft_printf/ft_printf.h"
# include "ft_printf/libft/libft.h"

typedef struct node
{
	int			nb;
	int			index;
	int			cost;
	int			above_median;
	int			cheapest;
	struct node	*target_t_node;
	struct node	*prev;
	struct node	*next;
}	t_node;

int			get_size(t_node **tail);
void		swap(t_node **tail);
void		del_last(t_node **tail);
void		del_first(t_node **tail);
void		insert_end(int value, t_node **tail);
void		insert_beginning(int value, t_node **tail);
void		make_link_list(char **args, t_node **a);
void		rotate(t_node **tail);
void		rev_rotate(t_node **tail);
void		push(t_node **a, t_node **b);
void		get_target_t_node(t_node *a, t_node *b);
void		get_index(t_node *a);
void		get_median(t_node *a);
void		get_cost_a(t_node *a, t_node *b);
void		get_the_cheapest(t_node *a);
void		rotate_single_helper(t_node **a, t_node *curr);
void		rotate_single_helper_2(t_node **a, t_node *curr);
void		rotate_single(t_node **a, t_node **b, t_node *curr);
void		rotate_single_b_helper(t_node **b, t_node *curr);
void		rotate_single_b_helper_2(t_node **b, t_node *curr);
void		rotate_single_b(t_node **a, t_node **b, t_node *curr);
void		rotate_both_helper(t_node **a, t_node **b);
void		rotate_both(t_node **a, t_node **b, t_node *curr);
void		do_the_best_move(t_node **a, t_node **b, t_node *curr);
void		do_the_best_move_b(t_node **a, t_node **b, t_node *curr);
int			ft_ifdigitarr(char **argv);
t_node		*create_t_node(int curr_val, t_node *repeats);
int			check_duplicate(t_node *repeats, int curr_val);
int			ft_ifduparr(char **argv);
int			ft_ifintnbr(char *argv);
int			ft_ifdigitstr(char *argv);
t_node		*create_node(int curr_val, t_node *repeats);
int			ft_ifdupstr(char *argv);
int			ft_ifintarr(char **argv);
int			ft_iferror(int argc, char **argv);
void		sort_three_helper(t_node **a);
void		sort_three_helper_2(t_node **a);
void		sort_three(t_node **a);
t_node		*find_highest(t_node *b);
void		fill_cheapest(t_node *a);
t_node		*find_lowest(t_node	*a);
int			list_is_sorted(t_node *a);
void		free_list(t_node *node);
void		free_array(char **arr);
void		get_target_t_node_for_b(t_node *a, t_node *b);
void		get_values2(t_node **a, t_node **b);
void		rotate_both_helper3(t_node *curr, t_node **a, t_node **b);
int			helper_main(t_node *a, int argc, char **args);

#endif