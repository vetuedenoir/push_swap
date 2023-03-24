/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finish.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kscordel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 19:54:29 by kscordel          #+#    #+#             */
/*   Updated: 2023/03/17 19:54:37 by kscordel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	finish(t_list **a, int bigest, int size)
{
	t_list	*node;
	int		i;

	i = 1;
	node = *a;
	while (*(int *)(node->content) != bigest)
	{
		i++;
		node = node->next;
	}
	if (i <= size / 2)
	{
		while (i-- != 0)
			rotate(a, 'a');
	}
	else
	{
		while ((size - i++) != 0)
			reverse_rotate(a, 'a');
	}
}
