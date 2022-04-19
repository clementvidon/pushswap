/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvidon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 14:50:38 by cvidon            #+#    #+#             */
/*   Updated: 2022/04/19 16:20:07 by cvidon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 ** Find the tab length.
 */

static size_t	ft_tablen(char	**tab)
{
	size_t	i;

	i = 0;
	while (*tab++)
		i++;
	return (i);
}

/*
 ** Split the arguments into char numbers.
 */

static char	**ft_split_numbers(int ac, char **av)
{
	int		i;
	char	*str;
	char	*temp;
	char	**tab;

	i = 0;
	str = NULL;
	while (++i < ac)
	{
		temp = str;
		if (ft_have_num(av[i]) == 0)
			return (write(2, "Error\n", 6), ft_free(temp), exit(1), NULL);
		str = ft_strjoin(str, av[i]);
		if (!str)
			return (write(2, "Error\n", 6), ft_free(temp), exit(1), NULL);
		ft_free(temp);
		temp = str;
		str = ft_strjoin(str, " ");
		if (!str)
			return (write(2, "Error\n", 6), ft_free(temp), exit(1), NULL);
		ft_free(temp);
	}
	tab = ft_split(str, ' ');
	return (ft_free(str), tab);
}

/*
 ** Check the arguments validity and convert them into numerical values.
 */

void	ft_parser(t_data *data, int ac, char **av)
{
	char		**strtab;
	char		**strtab_ptr;
	int			i;
	long int	num;

	strtab = ft_split_numbers(ac, av);
	if (!strtab)
		return (write(2, "Error\n", 6), exit(1));
	data->tab_size = ft_tablen(strtab);
	strtab_ptr = strtab;
	data->tab = malloc (sizeof (int) * (size_t)data->tab_size);
	if (!data->tab)
		return (write(2, "Error\n", 6), ft_free(strtab), exit(1));
	i = 0;
	while (i < (int)data->tab_size)
	{
		if (!ft_isnum(*strtab))
			ft_error(strtab_ptr, data->tab);
		num = ft_atol(*strtab);
		if (num > INT_MAX || num < INT_MIN || ft_duplicate(data->tab, i, num))
			ft_error(strtab_ptr, data->tab);
		data->tab[i++] = (int)num;
		strtab++;
	}
	ft_free_tab((void **)strtab_ptr);
}
