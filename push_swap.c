/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   by: kscordel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 11:25:00 by kscordel          #+#    #+#             */
/*   Updated: 2023/02/27 19:37:01 by kscordel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list		*majorant(t_list *a, t_list *node)
{
	int	difference;
	t_list	*majorant;

	majorant = a;
	difference =  *(int *)(a->content) - *(int *)(node->content);
	if (difference < 0)
		difference = INT_MAX;
	while (a != NULL &&	difference != 1)
	{
		if (*(int *)(a->content) > *(int *)(node->content) 
			&& *(int *)(a->content) - *(int *)(node->content) < difference)
		{
			difference =  *(int *)(a->content) - *(int *)(node->content);
			majorant = a; 
		}
		a = a->next;
	}
	/*if (majorant != NULL && node != NULL)
	*///	printf("majorant = %d et node = %d \n\n", *(int *)(majorant->content) ,*(int *)(node->content));
	return (majorant);
}

int		ft_pos(t_list *lst, t_list *node)
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

void	ft_pretri(t_list **a, t_list **b)
{
	int	mediane;
	int	bigest;
	int	i;
	int	x;

	i = 0;
	x = 0;
	mediane = ft_mediane(*a);
	bigest = ft_bigest(*a);
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

/*
void	finish(t_list **a, t_list **b)
{

}
*/
void	ft_push_swap(t_list **a, t_list **b, int size)
{
	if (size == 2)
		swap(a, 'a');
	if (size == 3)
		ft_algothree(a);
	if (size >= 4)
	{
		ft_pretri(a, b);
		while (*b != NULL)
			the_chosen_one(a, b);
		//finish(a, b);
	}
}
