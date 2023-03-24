/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kscordel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 20:02:53 by kscordel          #+#    #+#             */
/*   Updated: 2023/03/17 20:03:02 by kscordel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_list	*majorant(t_list *a, t_list *node)
{
	int		difference;
	t_list	*majorant;

	majorant = a;
	difference = *(int *)(a->content) - *(int *)(node->content);
	if (difference < 0)
		difference = INT_MAX;
	while (a != NULL && difference != 1)
	{
		if (*(int *)(a->content) > *(int *)(node->content)
			&& *(int *)(a->content) - *(int *)(node->content) < difference)
		{
			difference = *(int *)(a->content) - *(int *)(node->content);
			majorant = a;
		}
		a = a->next;
	}
	return (majorant);
}

int	ft_pos(t_list *lst, t_list *node)
{
	int	i;

	i = 1;
	while (lst != node && lst->next != NULL)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

void	ft_pretri(t_list **a, t_list **b, int bigest)
{
	int	mediane;
	int	i;
	int	x;

	i = 0;
	x = 0;
	mediane = ft_mediane(*a);
	while (*a != NULL)
	{
		if (*(int *)((*a)->content) != bigest)
		{
			pushpm(b, a, 'b');
			if (*(int *)((*b)->content) < mediane && i)
				rotate(b, 'b');
			i++;
		}
		else if (x++ == 0)
			rotate(a, 'a');
		else
			break ;
	}
}

void	ft_push_swap(t_list **a, t_list **b, int size)
{
	int	bigest;

	if (size == 2)
		swap(a, 'a');
	else if (size == 3)
		ft_algothree(a);
	else if (size > 3 && size < 6)
		ft_algofive(a, b, size);
	else if (size > 5)
	{
		bigest = ft_bigest(*a);
		ft_pretri(a, b, bigest);
		while (*b != NULL)
			the_chosen_one(a, b);
		finish(a, bigest, size);
	}
}
