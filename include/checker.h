/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvidon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 15:52:28 by cvidon            #+#    #+#             */
/*   Updated: 2022/04/19 15:52:28 by cvidon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

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

void	ft_char_listdelone(t_op *op, void (*del)(void *));
void	ft_char_listdelfirst(t_op **op, void (*del)(void *));
void	ft_char_listclear(t_op **op, void (*del)(void *));
t_op	*ft_char_listnew(char *operation, t_data *data);

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
 ** [ CHECKER/CHECKER.C ]
 */

/* static void ft_get_operations(t_data *data, char *op); */
void	ft_read_operations(t_data *data);

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
 ** [ CHECKER/MAIN.C ]
 */

/* void	ft_init_list_a(t_data *data) */
int		main(int ac, char **av);

#endif
