/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvidon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 14:51:34 by cvidon            #+#    #+#             */
/*   Updated: 2022/04/12 15:07:06 by cvidon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 ** sa, sb
 */

void	ft_swap(t_lst *stack, char *s, t_data *data)
{
	int	temp;

	if (!stack || !stack->next)
		return ;
	temp = stack->content;
	stack->content = stack->next->content;
	stack->next->content = temp;
	if (s)
		ft_add_op(s, data);
}

/*
 ** ss
 */

void	ft_ss(t_data *data)
{
	ft_swap(data->stack_a, NULL, data);
	ft_swap(data->stack_b, NULL, data);
	ft_add_op("ss", data);
}

/*
 ** pa, pb
 */

void	ft_push(t_lst **stack_bot, t_lst **stack_top, char *p, t_data *data)
{
	t_lst	*temp;

	if ((*stack_top))
	{
		temp = (*stack_top);
		(*stack_top) = temp->next;
		temp->next = (*stack_bot);
		(*stack_bot) = temp;
	}
	if (p)
		ft_add_op(p, data);
}

/*
 ** Add each operation to a list.
 **
 ** TODO demander à @mdavid si les if check des protection malloc sont
 ** pertinentes.
 */

void	ft_add_op(char *str, t_data *data)
{
	t_op	*new;
	t_op	*temp;

	new = malloc(sizeof(t_op));
	if (!new)
		ft_clear_exit(data, EXIT_FAILURE);
	new->operation = str;
	new->next = NULL;
	if (!data->oplist)
	{
		data->oplist = new;
		return ;
	}
	temp = data->oplist;
	while (temp->next)
		temp = temp->next;
	temp->next = new;
}

/*
 ** Display, or factorize and then display the operations.
 */

void	ft_print_op(t_data *data)
{
	t_op	*temp;

	temp = data->oplist;
	while (temp && temp->next)
	{
		if (ft_strncmp(temp->operation, "rra", 3) == 0
			&& ft_strncmp(temp->next->operation, "rrb", 3) == 0)
			temp = (ft_printf("rrr\n"), temp->next->next);
		else if (ft_strncmp(temp->operation, "rrb", 3) == 0
			&& ft_strncmp(temp->next->operation, "rra", 3) == 0)
			temp = (ft_printf("rrr\n"), temp->next->next);
		else if (ft_strncmp(temp->operation, "ra", 2) == 0
			&& ft_strncmp(temp->next->operation, "rb", 2) == 0)
			temp = (ft_printf("rr\n"), temp->next->next);
		else if (ft_strncmp(temp->operation, "rb", 2) == 0
			&& ft_strncmp(temp->next->operation, "ra", 2) == 0)
			temp = (ft_printf("rr\n"), temp->next->next);
		else
			temp = (ft_printf("%s\n", temp->operation), temp->next);
	}
	if (temp)
		ft_printf("%s\n", temp->operation);
}
