/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvidon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 14:16:00 by cvidon            #+#    #+#             */
/*   Updated: 2022/04/19 13:49:27 by cvidon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 ** Update tab between each pre_sort.
 */

static void	ft_update_tab(t_data *data)
{
	int		i;
	t_lst	*temp;

	free(data->tab);
	temp = data->stack_a;
	data->tab = malloc(sizeof(int) * data->tab_size);
	if (!data->tab)
		ft_clear_exit(data, EXIT_FAILURE);
	i = 0;
	while (temp)
	{
		data->tab[i] = temp->content;
		i++;
		temp = temp->next;
	}
}

/*
 ** Find the median value of an int tab.
 */

static int	ft_find_median(int *tab, int size)

{
	if (size % 2 == 0)
		return (tab[size / 2 - 1]);
	else
		return (tab[size / 2]);
}

/*
 ** Basic "ft_sort_int_tab" from Libft.
 */

static void	ft_sort_tab(int *tab, int size)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	while (i < size)
	{
		j = i;
		while (j < size)
		{
			if (tab[i] > tab[j])
			{
				temp = tab[i];
				tab[i] = tab[j];
				tab[j] = temp;
			}
			j ++;
		}
		i++;
	}
}

/*
 ** Sort the tab, find its median.
 ** Send each value < median to Stack B.
 ** Update tab.
 ** Repeat.
 */

void	ft_pre_sort(t_data *data)
{
	int		median;
	int		i;

	ft_sort_tab(data->tab, (int)data->tab_size);
	median = ft_find_median(data->tab, (int)data->tab_size);
	i = 0;
	while (i < (int)data->tab_size)
	{
		if (data->stack_a->content < median)
			ft_push(&data->stack_b, &data->stack_a, "pb", data);
		else
			ft_rotate(&data->stack_a, "ra", data);
		i++;
	}
	data->tab_size = (size_t)ft_listsize(data->stack_a);
	ft_update_tab(data);
}
