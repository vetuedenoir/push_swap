/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kscordel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 19:02:32 by kscordel          #+#    #+#             */
/*   Updated: 2023/01/18 19:42:21 by kscordel         ###   ########.fr       */
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

void	swap(t_list *list);
void	push(t_list *lstplus, t_list *lstmoins);

#endif
