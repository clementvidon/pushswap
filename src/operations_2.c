/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvidon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 14:54:20 by cvidon            #+#    #+#             */
/*   Updated: 2022/04/15 15:14:31 by cvidon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 ** ra, rb
 */

void	ft_rotate(t_lst **stack, char *r, t_data *data)
{
	t_lst	*newhead;
	t_lst	*temp;

	if ((*stack) && (*stack)->next)
	{
		temp = *stack;
		newhead = (*stack)->next;
		while ((*stack)->next)
			*stack = (*stack)->next;
		(*stack)->next = temp;
		temp->next = NULL;
		*stack = newhead;
		if (r)
			ft_add_op(r, data);
	}
}

/*
 ** rr
 */

void	ft_rr(t_data *data)
{
	ft_rotate(&data->stack_a, NULL, data);
	ft_rotate(&data->stack_b, NULL, data);
	ft_add_op("rr", data);
}

/*
 ** rra, rrb
 */

void	ft_reverse_rotate(t_lst **stack, char *rr, t_data *data)
{
	t_lst	*newhead;
	t_lst	*temp;

	if ((*stack) && (*stack)->next)
	{
		temp = *stack;
		while ((*stack)->next->next)
			*stack = (*stack)->next;
		newhead = (*stack)->next;
		(*stack)->next = NULL;
		newhead->next = temp;
		*stack = newhead;
		if (rr)
			ft_add_op(rr, data);
	}
}

/*
 ** rrr
 */

void	ft_rrr(t_data *data)
{
	ft_reverse_rotate (&data->stack_a, NULL, data);
	ft_reverse_rotate (&data->stack_b, NULL, data);
	ft_add_op("rrr", data);
}
