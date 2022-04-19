/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvidon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 12:27:36 by cvidon            #+#    #+#             */
/*   Updated: 2022/04/19 13:51:00 by cvidon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 ** Return the cheapest Cost.
 */

static int	ft_cheapest_cost(t_lst *stack)
{
	t_lst	*temp;
	int		cost;

	cost = stack->cost;
	temp = stack;
	while (temp)
	{
		if (temp->cost < cost)
			cost = temp->cost;
		temp = temp->next;
	}
	return (cost);
}

/*
 ** Return the Element with the cheapest Cost.
 */

static t_lst	*ft_cheapest(t_lst *stack)
{
	t_lst	*temp;
	int		cheapest;

	cheapest = ft_cheapest_cost(stack);
	temp = stack;
	while (temp->cost != cheapest)
		temp = temp->next;
	return (temp);
}

/*
 ** Return the ID of the Leader (from Stack A) that correspond
 ** to the cheapest Element (from Stack B).
 */

static int	ft_cheapest_leader_id(t_lst *stack_a, t_lst *stack_b)
{
	t_lst	*temp;
	int		cheapest;

	cheapest = ft_cheapest(stack_b)->leader;
	temp = stack_a;
	while (temp->content != cheapest)
		temp = temp->next;
	return (temp->id);
}

/*
 ** Move the Stack A according to the cheapest Leader position.
 */

static void	ft_move_stack_a(t_data *data)
{
	int	size_a;

	size_a = ft_set_ids(data->stack_a);
	if (ft_cheapest_leader_id(data->stack_a, data->stack_b) > size_a / 2)
		ft_reverse_rotate(&data->stack_a, "rra", data);
	else if (ft_cheapest_leader_id(data->stack_a, data->stack_b) <= size_a / 2)
		ft_rotate(&data->stack_a, "ra", data);
}

/*
 ** Send the cheapest Element from Stack A to Stack B.
 **
 ** 1. Update each Element's Costs + IDs.
 ** 2. Re-compute the cheapest Element.
 ** 3. Engage the operations.
 ** 4. Repeat.
 **
 ** We operate as much 'reverse/rotate' as needed for the wanted Element (from
 ** Stack B) and its Leader (from Stack A) be at the top of their respective
 ** Stack.
 **
 ** Then we 'push' to send the cheapest Element from Stack A to the Stack B.
 **
*/

void	ft_move_cheap(t_data *data)
{
	int	content;
	int	leader;
	int	id;

	content = ft_cheapest(data->stack_b)->content;
	leader = ft_cheapest(data->stack_b)->leader;
	id = ft_cheapest(data->stack_b)->id;
	while (data->stack_b->content != content
		|| data->stack_a->content != leader)
	{
		if (data->stack_b->content != content)
		{
			if (id > ft_set_ids(data->stack_b) / 2)
				ft_reverse_rotate(&data->stack_b, "rrb", data);
			else if (id <= ft_set_ids(data->stack_b) / 2)
				ft_rotate(&data->stack_b, "rb", data);
		}
		if (data->stack_a->content != leader)
			ft_move_stack_a(data);
		if (data->stack_b->content == content
			&& data->stack_a->content == leader)
			break ;
	}
	ft_push(&data->stack_a, &data->stack_b, "pa", data);
}
