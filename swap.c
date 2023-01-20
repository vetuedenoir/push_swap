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
 
 void	sswap(t_list *a, t_list *b)
 {
 	t_list	*next;
	int	*data;	

	if (a->next)
	{
		next = a->next;
		data = a->content;
		a->content = next->content;
		next->content = data;
	}
	if (b->next)
	{
		next = b->next;
		data = b->content;
		b->content = next->content;
		next->content = data;
	}
 }
