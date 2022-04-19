/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvidon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 14:58:46 by cvidon            #+#    #+#             */
/*   Updated: 2022/04/12 15:11:22 by cvidon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

/*
 ** =========[ Includes ]==========
 */

# include "libft.h"

# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

/*
 ** =========[ Structures ]========
 */

typedef struct s_lst
{
	struct s_lst	*next;
	int				content;
	int				id;
	int				leader;
	int				cost;
}	t_lst;

typedef struct s_op
{
	struct s_op		*next;
	char			*operation;
}	t_op;

typedef struct s_data
{
	int			*tab;
	size_t		tab_size;
	t_lst		*stack_a;
	t_lst		*stack_b;
	t_op		*oplist;
	int			size_a;
	int			size_b;
}	t_data;

/*
 ** =========[ Prototypes ]========
 **
 ** Commented = static.
 */

/*
 ** [ SECURITY.C ]
 */

void	ft_free(void *ptr);
void	ft_free_tab(void **tab);
void	ft_exit(char *msg);
void	ft_error(char **strtab, int *numtab);
void	ft_clear_exit(t_data *data, int status);

/*
 ** [ CHAR_LISTUTILS.C ]
 */

void	ft_char_listdelone(t_op *oplist, void (*del)(void *));
void	ft_char_listdelfirst(t_op **oplist, void (*del)(void *));
t_op	*ft_char_listnew(char *operation, t_data *data);
void	ft_char_listclear(t_op **oplist, void (*del)(void *));

/*
 ** [ LISTUTILS_3.C ]
 */

int		ft_listissort(t_lst *lst);
t_lst	*ft_listmin(t_lst *lst);
t_lst	*ft_listmax(t_lst *lst);

/*
 ** [ LISTUTILS_2.C ]
 */

void	ft_listprint_int(t_lst *lst);
void	ft_listdelfirst(t_lst **lst, void (*del)(void *));
void	ft_listadd_back(t_lst **alst, t_lst *new);
void	ft_listadd_front(t_lst **alst, t_lst *new);

/*
 ** [ LISTUTILS_1.C ]
 */

void	ft_listclear(t_lst **lst, void (*del)(void *));
void	ft_listdelone(t_lst *lst, void (*del)(void *));
t_lst	*ft_listlast(t_lst *lst);
t_lst	*ft_listnew(int content, t_data *data);
int		ft_listsize(t_lst *lst);

/*
 ** [ OPERATIONS_2.C ]
 */

void	ft_rotate(t_lst **stack, char *r, t_data *data);
void	ft_rr(t_data *data);
void	ft_reverse_rotate(t_lst **stack, char *rr, t_data *data);
void	ft_rrr(t_data *data);

/*
 ** [ OPERATIONS_1.C ]
 */

void	ft_swap(t_lst *stack, char *s, t_data *data);
void	ft_ss(t_data *data);
void	ft_push(t_lst **stack_bot, t_lst **stack_top, char *p, t_data *data);
void	ft_add_op(char *str, t_data *data);
void	ft_print_op(t_data *data);

/*
 ** [ COSTS.C ]
 */

/* static int  ft_dist(int size, int id) */
/* static int  ft_comp(int id_a, int id_b, int size_a, int size_b) */
/* static int  ft_cost(int id_a, int id_b, int size_a, int size_b) */
void	ft_set_cost(t_data *data);

/*
 ** [ LEADER.C ]
 */

/* static void	ft_leader(t_data *data, t_lst *stack_b) */
void	ft_set_leaders(t_data *data);

/*
 ** [ ID.C ]
 */

int		ft_set_ids(t_lst *stack);

/*
 ** [ SMALLSORT.C ]
 */

/* static int  ft_id_smallest(t_lst *stack) */
/* static void    ft_smallmove(t_data *data) */
/* static void    ft_smallsort_2(t_data *data) */
/* static void  ft_smallsort_1(t_data *data) */
void	ft_smallsort(t_data *data);

/*
 ** [ SORT.C ]
 */

/* static void	ft_update_elements(t_data *data); */
/* static int	ft_check_order(t_lst stack) */
void	ft_sort(t_data *data);

/*
 ** [ MOVES.C ]
 */

/* static int  ft_cheapest_cost(t_lst *stack); */
/* static t_lst    *ft_cheapest(t_lst *stack); */
/* static int  ft_cheapest_leader_id(t_lst *stack_a, t_lst *stack_b); */
/* static void ft_move_stack_a(t_data *data); */
void	ft_move_cheap(t_data *data);

/*
 ** [ PRE_SORT.C ]
 */

/* static void>ft_sort_tab(int *tab, int size); */
/* static int ft_find_median(int *tab, int size); */
/* static void>ft_update_tab(t_data *data); */
void	ft_pre_sort(t_data *data);

/*
 ** [ CHECK_ARGS.C ]
 */

int		ft_duplicate(int *tab, int id, long int num);
int		ft_isnum(char *str);
int		ft_have_num(char *str);

/*
 ** [ PARSE_ARGS.C ]
 */

/* size_t	ft_tablen(char	**tab) */
/* char	**ft_split_numbers(int ac, char **av); */
void	ft_parser(t_data *data, int ac, char **av);

/*
 ** [ MAIN.C ]
 */

/* void	ft_init_list_a(t_data *data) */
int		main(int ac, char **av);

#endif
