/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kscordel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 19:02:32 by kscordel          #+#    #+#             */
/*   Updated: 2023/01/20 18:27:36 by kscordel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/libft.h"
# include <stdio.h>
# include <limits.h>
# include <stdlib.h>

t_list	*ft_all_check(char **argument, int argc);
int		ft_check_doublons(t_list *lst);
t_list	*ft_transfo(char **argument);
int		*ft_convert(const char *str);
int		ft_check_nbr(char **argument);
void	*free_tt(char **ts);
void	free_lc(t_list *lst);
long	ft_atol(const char *str);
void	ft_print_lst(t_list *lst);
void	print_pile_ab(t_list *a, t_list *b);

void	swap(t_list *list);
void	sswap(t_list *a, t_list *b);

void	pushpm(t_list **lstplus, t_list **lstmoins);

void	rotate(t_list **lst);
void	rrotate(t_list **a, t_list **b);

void	reverse_rotate(t_list **lst);
void	rreverse_rrotate(t_list **a, t_list **b);

#endif
