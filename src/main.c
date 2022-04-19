/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvidon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 14:48:34 by cvidon            #+#    #+#             */
/*   Updated: 2022/04/12 14:48:35 by cvidon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 ** Initialize Stack A and Stack B.
 */

static void	ft_init_stacks(t_data *data)
{
	int	i;
	int	*tab_ptr;

	data->stack_b = NULL;
	tab_ptr = data->tab;
	data->stack_a = ft_listnew(*(data)->tab++, data);
	i = 0;
	while (i++ < (int)data->tab_size - 1)
		ft_listadd_back(&data->stack_a, ft_listnew(*(data)->tab++, data));
	data->tab = tab_ptr;
	data->oplist = NULL;
}

int	main(int ac, char **av)
{
	t_data	data;

	if (ac > 1)
	{
		ft_parser(&data, ac, av);
		if (!data.tab)
			return (ft_putstr_fd("Error\n", 2), 1);
		ft_init_stacks(&data);
		if (!ft_listissort(data.stack_a))
		{
			if (data.tab_size <= 5)
				ft_smallsort(&data);
			else
				ft_sort(&data);
		}
		ft_print_op(&data);
		ft_listclear(&data.stack_a, free);
		ft_listclear(&data.stack_b, free);
		ft_free(data.tab);
		ft_char_listclear(&data.oplist, free);
	}
	return (0);
}
