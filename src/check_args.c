/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvidon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 14:43:26 by cvidon            #+#    #+#             */
/*   Updated: 2022/04/12 14:43:36 by cvidon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 ** Each argument has to be unique.
 */

int	ft_duplicate(int *tab, int index, long int num)
{
	int	i;

	i = 0;
	while (i < index)
	{
		if (tab[i] == num)
			return (1);
		i++;
	}
	return (0);
}

/*
 ** Each argument has to be numerical.
 */

int	ft_isnum(char *str)
{
	if ((*str == '-' || *str == '+') && ft_strlen(str) > 1)
		str++;
	while (*str)
	{
		if ((*str < '0' || *str > '9'))
			return (0);
		str++;
	}
	return (1);
}

/*
 ** Each arguments has to contain at least one digit.
 */

int	ft_have_num(char *str)
{
	while (*str)
	{
		if (ft_isdigit(*str++))
			return (1);
	}
	return (0);
}
