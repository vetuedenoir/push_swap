/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kscordel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 19:02:32 by kscordel          #+#    #+#             */
/*   Updated: 2023/01/28 18:50:49 by kscordel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <stdio.h>
# include <limits.h>
# include <stdlib.h>

typedef struct s_index
{
	int	i;
	int	j;
	int	k;
}			t_index;

typedef struct s_data
{
	int	posa;
	int	posb;
	int	sizea;
	int	sizeb;
}			t_data;

typedef struct s_mouvement
{
	int	ra;
	int	rr;
	int	rrr;
	int	rb;
	int	rra;
	int	rrb;
	int	total;
}			t_mouvement;

t_list		*ft_all_check(char **argument, int argc);
int			ft_check_doublons(t_list *lst);
t_list		*ft_transfo(char **argument);
int			*ft_convert(const char *str);
int			ft_check_nbr(char **argument);

void		*free_tt(char **ts);
void		free_lc(t_list **lst);
long		ft_atol(const char *str);
void		ft_print_lst(t_list *lst);
void		print_pile_ab(t_list *a, t_list *b);

void		swap(t_list **list, char x);
void		sswap(t_list **a, t_list **b);

void		pushpm(t_list **lstplus, t_list **lstmoins, char x);

void		rotate(t_list **lst, char x);
void		rrotate(t_list **a, t_list **b);

void		reverse_rotate(t_list **lst, char x);
void		rreverse_rrotate(t_list **a, t_list **b);

void		trifusion(int *tab, int debut, int fin);

int			ft_mediane(t_list *lst);
int			ft_bigest(t_list *lst);

t_list		*majorant(t_list *a, t_list *node);
int			ft_pos(t_list *lst, t_list *node);
void		ft_pretri(t_list **a, t_list **b, int bigest);
void		ft_push_swap(t_list **a, t_list **b, int size);

void		ft_algothree(t_list **a);
void		ft_algofive(t_list**a, t_list **b, int size);
int			ft_veriftri(t_list *lst);

void		the_chosen_one(t_list **a, t_list **b);
void		ft_action(t_list **a, t_list **b, t_mouvement action);

t_mouvement	ft_nbcoup(t_data coup);

t_mouvement	ft_calcule1(int nba, int nbb);
t_mouvement	ft_calcule2(int nba, int nbb);
t_mouvement	ft_calcule3(int nba, int nbb, char x);

t_mouvement	init_mouvement(void);
t_data		init_data(t_list *a, t_list *b, t_list *node);
t_index		init_index(void);

void		finish(t_list **a, int bigest, int size);

#endif
