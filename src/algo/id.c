/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   id.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvidon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 12:26:28 by cvidon            #+#    #+#             */
/*   Updated: 2022/04/12 14:12:37 by cvidon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 ** Set the Stack Elements IDs.
 ** Return the Stack len.
 */

int	ft_set_ids(t_lst *stack)
{
	int		i;
	t_lst	*temp;

	i = 0;
	if (!stack)
		return (0);
	temp = stack;
	while (temp && temp->next)
	{
		temp->id = i++;
		temp = temp->next;
	}
	temp->id = i;
	return (i + 1);
}
