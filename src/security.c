/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   security.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvidon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 14:57:04 by cvidon            #+#    #+#             */
/*   Updated: 2022/04/12 14:58:19 by cvidon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 ** Free and set to NULL.
 */

void	ft_free(void *ptr)
{
	if (ptr)
	{
		free(ptr);
		ptr = NULL;
	}
}

/*
 ** Free NULL terminated a 2D tab.
 */

void	ft_free_tab(void **tab)
{
	void	**ptr;

	ptr = tab;
	while (*tab)
	{
		free(*tab);
		*tab = NULL;
		tab++;
	}
	free (ptr);
	ptr = NULL;
}

/*
 ** Parsing error function.
 */

void	ft_error(char **strtab, int *numtab)
{
	ft_free_tab((void **)strtab);
	free(numtab);
	ft_putstr_fd("Error\n", 2);
	exit (EXIT_FAILURE);
}

/*
 ** Clear memory and terminate.
 */

void	ft_clear_exit(t_data *data, int status)
{
	ft_free(data->tab);
	if (data->stack_a)
		ft_listclear(&data->stack_a, free);
	if (data->stack_b)
		ft_listclear(&data->stack_b, free);
	if (data->oplist)
		ft_char_listclear(&data->oplist, free);
	exit(status);
}
