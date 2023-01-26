/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kscordel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 11:07:05 by kscordel          #+#    #+#             */
/*   Updated: 2023/01/23 15:19:18 by kscordel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_list **lst, char x)
{
	t_list	*tmp;
	
	if (x == 'a')
		ft_putstr_fd("ra\n", 1);
	else
		ft_putstr_fd("rb\n", 1);
	if ((*lst) != NULL)
	{
		tmp = (*lst)->next;
		(*lst)->next = NULL;
		ft_lstadd_back(&tmp, (*lst));
		(*lst) = tmp;
	}
}

void	rrotate(t_list **a, t_list **b)
{
	t_list	*tmpa;
	t_list	*tmpb;

	ft_putstr_fd("rr\n", 1);
	if ((*a) != NULL)
	{
		tmpa = (*a)->next;
		(*a)->next = NULL;
		ft_lstadd_back(&tmpa, (*a));
		(*a) = tmpa;
	}
	if ((*b) != NULL)
	{
		tmpb = (*b)->next;
		(*b)->next = NULL;
		ft_lstadd_back(&tmpb, (*b));
		(*b) = tmpb;
	}
}
