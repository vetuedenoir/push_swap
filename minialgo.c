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

#include "push_swap.h"


int	ft_veriftri(t_list *lst)
{
	int	r;

	while (lst)
	{
		r = *(int *)(lst->content);
		lst = lst->next;
		if (lst == NULL)
			break ;
		if (r > *(int *)(lst->content))
			return (0);
	}
	return (1);
}

static void	three_operation(t_list **a, int one, int two, int three)
{
	if (one > two && two > three)
	{
		swap(a, 'a');
		reverse_rotate(a, 'a');
	}
	else if (one < two && one < three && three < two)
	{
		swap(a, 'a');
		rotate(a, 'a');
	}
	else if (one > two && one > three)
		rotate(a, 'a');
	else if (three < one && three < two)
		reverse_rotate(a, 'a');
	else if (one > two && one < three)
		swap(a, 'a');
}

void	ft_algothree(t_list **a)
{
	int	one;
	int	two;
	int	three;
	t_list	*first;

	first = *a;
	one = *(int *)((*a)->content);
	*a = (*a)->next;
	two = *(int *)((*a)->content);
	*a = (*a)->next;
	three = *(int *)((*a)->content);
	*a = first;
	three_operation(a, one, two, three);
}