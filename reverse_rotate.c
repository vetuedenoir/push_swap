/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kscordel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 11:06:35 by kscordel          #+#    #+#             */
/*   Updated: 2023/01/20 18:01:10 by kscordel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	minuslist(t_list *lst, t_list *last)
{
	while (lst->next != last)
		lst = lst->next;
	lst->next = NULL;
}

void	reverse_rotate(t_list **lst, char x)
{
	t_list	*tmp;

	if (x == 'a')
		ft_putstr_fd("rra\n", 1);
	else
		ft_putstr_fd("rrb\n", 1);
	if ((*lst) != NULL)
	{
		if ((*lst)->next != NULL)
		{
			tmp = ft_lstlast((*lst));
			minuslist((*lst), tmp);
			ft_lstadd_front(lst, tmp);
			
		}
	}
}

void	rreverse_rrotate(t_list **a, t_list **b)
{
	t_list	*tmpa;
	t_list	*tmpb;

	ft_putstr_fd("rrr\n", 1);
	if ((*a) != NULL)
	{
		if ((*a)->next != NULL)
		{
			tmpa = ft_lstlast((*a));
			minuslist((*a), tmpa);
			ft_lstadd_front(a, tmpa);
		}
	}
	if ((*b) != NULL)
	{
		if ((*b)->next != NULL)
		{
			tmpb = ft_lstlast((*b));
			minuslist((*b), tmpb);
			ft_lstadd_front(b, tmpb);
		}
	}
}
