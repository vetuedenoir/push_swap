/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minialgo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kscordel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 12:44:09 by kscordel          #+#    #+#             */
/*   Updated: 2023/02/25 12:44:14 by kscordel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	posmax(t_list *a)
{
	t_list	*node;
	t_list	*tmp;

	node = a;
	tmp = a;
	while (tmp != NULL)
	{
		if (*(int *)((tmp)->content) > *(int *)((node)->content))
			node = tmp;
		tmp = tmp->next;
	}
	return (ft_pos(a, node));
}

static int	posmin(t_list *a)
{
	t_list	*node;
	t_list	*tmp;

	node = a;
	tmp = a;
	while (tmp != NULL)
	{
		if (*(int *)((tmp)->content) < *(int *)((node)->content))
			node = tmp;
		tmp = tmp->next;
	}
	return (ft_pos(a, node));
}

void	ft_algothree(t_list **a)
{
	int	max;

	max = posmax(*a);
	if (max == 1)
		rotate(a, 'a');
	else if (max == 2)
		reverse_rotate(a, 'a');
	if (posmin(*a) == 2)
		swap(a, 'a');
}

void	ft_algofive(t_list **a, t_list **b, int size)
{
	int	i;

	while (size > 3)
	{
		i = posmin(*a);
		if (i <= (size / 2) + 1)
		{
			while (i-- > 1)
				rotate(a, 'a');
		}
		else
		{
			while (i++ <= size)
				reverse_rotate(a, 'a');
		}
		pushpm(b, a, 'b');
		size--;
	}
	ft_algothree(a);
	pushpm(a, b, 'a');
	pushpm(a, b, 'a');
}
