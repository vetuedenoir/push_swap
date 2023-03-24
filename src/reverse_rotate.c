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

#include "../push_swap.h"

void	reverse_rotate(t_list **lst, char x)
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
	if (x == 'a')
		write(1, "rra\n", 4);
	if (x == 'b')
		write(1, "rrb\n", 4);
}

void	rreverse_rrotate(t_list **a, t_list **b)
{
	reverse_rotate(a, 'x');
	reverse_rotate(b, 'x');
	write(1, "rrr\n", 4);
}
