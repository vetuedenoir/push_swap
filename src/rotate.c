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

#include "../push_swap.h"

void	rotate(t_list **lst, char x)
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
	if (x == 'a')
		write(1, "ra\n", 3);
	if (x == 'b')
		write(1, "rb\n", 3);
}

void	rrotate(t_list **a, t_list **b)
{
	rotate(a, 'x');
	rotate(b, 'x');
	write(1, "rr\n", 3);
}
