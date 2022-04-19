/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smallsort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvidon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 14:21:32 by cvidon            #+#    #+#             */
/*   Updated: 2022/04/12 14:22:14 by cvidon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 ** Return the ID of the smallest Element.
 */

static int	ft_id_smallest(t_lst *stack)
{
	t_lst	*temp;

	temp = stack;
	while (ft_listmin(stack)->content != temp->content)
		temp = temp->next;
	return (temp->id);
}

/*
 ** Sort function for 3 input arguments.
 */

static void	ft_smallsort_1(t_data *data)
{
	int	id;

	if (ft_listissort(data->stack_a))
		return ;
	ft_set_ids(data->stack_a);
	id = ft_id_smallest(data->stack_a);
	if (id == 2)
	{
		if ((data->stack_a->content > data->stack_a->next->content))
			ft_swap(data->stack_a, "sa", data);
		ft_reverse_rotate(&data->stack_a, "rra", data);
	}
	else if (id == 0)
	{
		ft_swap(data->stack_a, "sa", data);
		ft_rotate(&data->stack_a, "ra", data);
	}
	else if (id == 1)
	{
		if (data->stack_a->content > data->stack_a->next->next->content)
			ft_rotate(&data->stack_a, "ra", data);
		else
			ft_swap(data->stack_a, "sa", data);
	}
}

/*
 ** Find the Stack A smallest Element and push it to the Stack B.
 */

static void	ft_smallmove(t_data *data)
{
	int	id_smallest;
	int	stack_len;
	int	smallest_content;

	stack_len = ft_set_ids(data->stack_a);
	id_smallest = ft_id_smallest(data->stack_a);
	smallest_content = ft_listmin(data->stack_a)->content;
	if (id_smallest > stack_len / 2)
	{
		while (data->stack_a->content != smallest_content)
			ft_reverse_rotate(&data->stack_a, "rra", data);
	}
	else if (id_smallest <= stack_len / 2)
	{
		while (data->stack_a->content != smallest_content)
			ft_rotate(&data->stack_a, "ra", data);
	}
	ft_push(&data->stack_b, &data->stack_a, "pb", data);
}

/*
 ** Sort function for 4 and 5 input arguments.
 */

static void	ft_smallsort_2(t_data *data)
{
	int	id;

	if (ft_listissort(data->stack_a))
		return ;
	id = ft_set_ids(data->stack_a);
	if (id == 4)
	{
		ft_smallmove(data);
		ft_smallsort_1(data);
		ft_push(&data->stack_a, &data->stack_b, "pa", data);
	}
	else if (id == 5)
	{
		ft_smallmove(data);
		ft_smallmove(data);
		ft_smallsort_1(data);
		ft_push(&data->stack_a, &data->stack_b, "pa", data);
		ft_push(&data->stack_a, &data->stack_b, "pa", data);
	}
}

/*
 ** Choose the appropriate sort function for small amount of numbers.
 */

void	ft_smallsort(t_data *data)
{
	if (ft_set_ids(data->stack_a) == 2
		&& data->stack_a->content > data->stack_a->next->content)
		ft_swap(data->stack_a, "sa", data);
	if (ft_set_ids(data->stack_a) == 3)
		ft_smallsort_1(data);
	if (ft_set_ids(data->stack_a) == 4)
		ft_smallsort_2(data);
	if (ft_set_ids(data->stack_a) == 5)
		ft_smallsort_2(data);
}
