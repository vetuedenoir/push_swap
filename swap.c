/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kscordel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 19:02:48 by kscordel          #+#    #+#             */
/*   Updated: 2023/01/18 19:03:17 by kscordel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

 void	swap(t_list *lst)
 {
 	t_list	*next;
	int	*data;	

	if (lst->next)
	{
		next = lst->next;
		data = lst->content;
		lst->content = next->content;
		next->content = data;
	}
 }
 
 void	sswap(t_list *lsta, t_list *lstb)
 {
 	t_list	*next;
	int	*data;	

	if (lsta->next)
	{
		next = lsta->next;
		data = lsta->content;
		lsta->content = next->content;
		next->content = data;
	}
	if (lstb->next)
	{
		next = lstb->next;
		data = lstb->content;
		lstb->content = next->content;
		next->content = data;
	}
 }
