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

#include "./checker.h"

void	rotate(t_list **lst)
{
	t_list	*node;

	if (*lst == NULL || (*lst)->next == NULL)
		return ;
	node = *lst;
	while (node->next != NULL)
	{
		node = node->next;
	}
	node->next = *lst;
	*lst = (*lst)->next;
	node->next->next = NULL;
}

void	rrotate(t_list **a, t_list **b)
{
	rotate(a);
	rotate(b);
}
