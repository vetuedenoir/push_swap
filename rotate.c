/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kscordel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 11:07:05 by kscordel          #+#    #+#             */
/*   Updated: 2023/01/20 18:02:38 by kscordel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_list **lst)
{
	t_list	*tmp;

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
