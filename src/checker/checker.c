/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvidon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 15:53:11 by cvidon            #+#    #+#             */
/*   Updated: 2022/04/19 15:53:13 by cvidon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

/*
 ** Parse each push_swap output line into its corresponding operation.
 */

static void	ft_get_operations(t_data *data, char *op)
{
	if (ft_strncmp(op, "sa\n", 3) == 0)
		ft_swap(data->stack_a, "sa", data);
	else if (ft_strncmp(op, "sb\n", 3) == 0)
		ft_swap(data->stack_b, "sb", data);
	else if (ft_strncmp(op, "ss\n", 3) == 0)
		ft_ss(data);
	else if (ft_strncmp(op, "pa\n", 3) == 0)
		ft_push(&data->stack_a, &data->stack_b, "pa", data);
	else if (ft_strncmp(op, "pb\n", 3) == 0)
		ft_push(&data->stack_b, &data->stack_a, "pb", data);
	else if (ft_strncmp(op, "ra\n", 3) == 0)
		ft_rotate(&data->stack_a, "ra", data);
	else if (ft_strncmp(op, "rb\n", 3) == 0)
		ft_rotate(&data->stack_b, "rb", data);
	else if (ft_strncmp(op, "rr\n", 3) == 0)
		ft_rr(data);
	else if (ft_strncmp(op, "rra\n", 4) == 0)
		ft_reverse_rotate(&data->stack_a, "rra", data);
	else if (ft_strncmp(op, "rrb\n", 4) == 0)
		ft_reverse_rotate(&data->stack_b, "rrb", data);
	else if (ft_strncmp(op, "rrr\n", 4) == 0)
		ft_rrr(data);
	else
		return (write(2, "Error\n", 6),
			free(op), ft_clear_exit(data, EXIT_FAILURE));
}

/*
 ** Read and execute push_swap operations one by one.
 */

void	ft_read_operations(t_data *data)
{
	char	*op;

	while (1)
	{
		op = get_next_line(0);
		if (!op)
			break ;
		ft_get_operations(data, op);
		free(op);
	}
	if (ft_listissort(data->stack_a) && ft_listsize(data->stack_b) == 0)
	{
		ft_putstr_fd("OK\n", 1);
		ft_clear_exit(data, EXIT_SUCCESS);
	}
	ft_putstr_fd("KO\n", 1);
	ft_clear_exit(data, EXIT_FAILURE);
}
