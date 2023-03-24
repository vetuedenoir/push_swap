/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kscordel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 14:39:47 by kscordel          #+#    #+#             */
/*   Updated: 2023/03/04 14:44:53 by kscordel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "../libft/libft.h"
# include <stdio.h>
# include <limits.h>
# include <stdlib.h>

# define RED	"\x1b[31m"
# define GREEN	"\x1b[32m"
# define RESET	"\x1b[0m"

t_list	*ft_all_check(char **argument, int argc);
int		ft_check_doublons(t_list *lst);
t_list	*ft_transfo(char **argument);
int		*ft_convert(const char *str);
int		ft_check_nbr(char **argument);

void	free_lc(t_list **lst);
long	ft_atol(const char *str);
void	ft_erreur(t_list **a, t_list **b, char *line);
int		ft_veriftri(t_list *lst);

void	swap(t_list **list);
void	sswap(t_list **a, t_list **b);

void	pushpm(t_list **lstplus, t_list **lstmoins);

void	rotate(t_list **lst);
void	rrotate(t_list **a, t_list **b);

void	reverse_rotate(t_list **lst);
void	rreverse_rrotate(t_list **a, t_list **b);

void	putstr_color(char *color, char *s);

#endif
