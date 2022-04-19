/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   leader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvidon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 12:26:58 by cvidon            #+#    #+#             */
/*   Updated: 2022/04/12 14:13:08 by cvidon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 ** Find a Leader.
 */

static void	ft_leader(t_data *data, t_lst *stack_b)
{
	t_lst	*tmp;

	stack_b->leader = ft_listmax(data->stack_a)->content;
	tmp = data->stack_a;
	while (tmp != NULL)
	{
		if (tmp->content < stack_b->leader)
			if (tmp->content > stack_b->content)
				stack_b->leader = tmp->content;
		tmp = tmp->next;
	}
}

/*
 ** Set Leaders.
 **
 ** Leader = closest value (in terms of value, not distance) between an Element
 ** in one Stack and an Element in the other Stack.
 */

void	ft_set_leaders(t_data *data)
{
	t_lst	*temp;

	temp = data->stack_b;
	while (data->stack_b)
	{
		ft_leader(data, data->stack_b);
		data->stack_b = data->stack_b->next;
	}
	data->stack_b = temp;
}
