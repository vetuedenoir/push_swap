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

#include "./checker.h"

void	swap(t_list **lst)
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
}

void	sswap(t_list **a, t_list **b)
{
	swap(a);
	swap(b);
}
