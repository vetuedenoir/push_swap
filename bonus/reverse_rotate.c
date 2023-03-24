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

#include "./checker.h"

void	reverse_rotate(t_list **lst)
{
	t_list	*node;

	if (*lst == NULL || (*lst)->next == NULL)
		return ;
	node = *lst;
	while (node->next->next != NULL)
	{
		node = node->next;
	}
	node->next->next = *lst;
	*lst = node->next;
	node->next = NULL;
}

void	rreverse_rrotate(t_list **a, t_list **b)
{
	reverse_rotate(a);
	reverse_rotate(b);
}
