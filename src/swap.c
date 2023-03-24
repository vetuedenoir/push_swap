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

#include "../push_swap.h"

void	swap(t_list **lst, char x)
{
	t_list	*premier;
	t_list	*second;

	if (*lst == NULL || (*lst)->next == NULL)
		return ;
	premier = (*lst)->next;
	second = premier->next;
	premier->next = *lst;
	(*lst)->next = second;
	*lst = premier;
	if (x == 'a')
		write(1, "sa\n", 3);
	if (x == 'b')
		write(1, "sb\n", 3);
}

void	sswap(t_list **a, t_list **b)
{
	swap(a, 'x');
	swap(b, 'x');
	write(1, "ss\n", 3);
}
