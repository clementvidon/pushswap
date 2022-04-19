/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvidon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 14:37:29 by cvidon            #+#    #+#             */
/*   Updated: 2022/04/12 15:11:10 by cvidon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 ** Update each Element's attributes (ID, Leader, Cost).
 */

static void	ft_update_elements(t_data *data)
{
	data->size_a = ft_set_ids(data->stack_a);
	data->size_b = ft_set_ids(data->stack_b);
	ft_set_leaders(data);
	ft_set_cost(data);
}

/*
 ** Return 1 if the Stack 2 top Elements are sorted (smaller upper).
 */

static int	ft_check_order(t_lst *stack)
{
	if (stack && stack->next && (stack->content < stack->next->content))
		return (1);
	return (0);
}

/*
 ** 1. Check if we have 2 Elements left in Stack A otherwise -> pre-sort.
 ** 2. Check if the Stack 2 top Elemts are sorted otherwise -> swap/double_swap.
 ** 3. While B is not empty we update all Stack B Elements attributes and we
 **    move the cheapest Stack B Element above its Stack A Leader.
 ** 4. When Stack B is empty we reset the IDs of Stack A.
 ** 5. If the smaller Element of Stack A is located
 **    		in the Stack <= half -> rotate
 **    		in the Stack >  half -> reverse_rotate
 */

void	ft_sort(t_data *data)
{
	while (ft_set_ids(data->stack_a) > 2)
		ft_pre_sort(data);
	if (ft_check_order(data->stack_a) == 0
		&& ft_check_order(data->stack_b) == 1)
		ft_ss(data);
	else if (ft_check_order(data->stack_a) == 0)
		ft_swap(data->stack_a, "sa", data);
	else if (ft_check_order(data->stack_b) == 1)
		ft_swap(data->stack_b, "sb", data);
	while (ft_set_ids(data->stack_b))
	{
		ft_update_elements(data);
		ft_move_cheap(data);
	}
	ft_set_ids(data->stack_a);
	if (ft_listmin(data->stack_a)->id > ft_set_ids(data->stack_a) / 2)
		while (data->stack_a->content != ft_listmin(data->stack_a)->content)
			ft_reverse_rotate(&data->stack_a, "rra", data);
	else if (ft_listmin(data->stack_a)->id <= ft_set_ids(data->stack_a) / 2)
		while (data->stack_a->content != ft_listmin(data->stack_a)->content)
			ft_rotate(&data->stack_a, "ra", data);
}
