/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listutils_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvidon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 14:55:19 by cvidon            #+#    #+#             */
/*   Updated: 2022/04/12 14:56:17 by cvidon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 ** Print a list. (dev)
 */

void	ft_listprint_int(t_lst *lst)
{
	t_lst	*temp;

	temp = lst;
	while (temp)
	{
		ft_printf(" [ cn %i, id %i, sp %i, cs %i ] ->\n",
			temp->content,
			temp->id,
			temp->leader,
			temp->cost
			);
		temp = temp->next;
	}
	ft_printf(" NULL (back)\n");
	ft_printf("\n");
}

/*
 ** Delete the first Element of a list.
 */

void	ft_listdelfirst(t_lst **lst, void (*del)(void *))
{
	t_lst	*temp;

	temp = *lst;
	if (!temp)
		return ;
	if (!temp->next)
	{
		ft_listdelone(temp, del);
		return ;
	}
	*lst = (*lst)->next;
	ft_listdelone(temp, del);
}

/*
 ** Add an Element to the back of the list.
 */

void	ft_listadd_back(t_lst **alst, t_lst *new)
{
	t_lst	*cpy;

	if (!new)
		return ;
	if (!*alst)
	{
		*alst = new;
		return ;
	}
	cpy = *alst;
	while (cpy->next)
		cpy = cpy->next;
	cpy->next = new;
}

/*
 ** Add an Element to the front of the list.
 */

void	ft_listadd_front(t_lst **alst, t_lst *new)
{
	if (!alst || !new)
		return ;
	new->next = *alst;
	*alst = new;
}
