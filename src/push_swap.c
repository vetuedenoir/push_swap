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

	difference =  *(int *)(a->content) - *(int *)(node->content);
	if (difference < 0)
		difference = INT_MAX;
	while (a != NULL ||	difference == 1)
	{
		if (*(int *)(a->content) > *(int *)(node->content) 
			&& *(int *)(a->content) - *(int *)(node->content) < difference)
			difference =  *(int *)(a->content) - *(int *)(node->content);
		a = a->next;
	}
	return (a);
}

int		ft_pos(t_list *lst, t_list *node)
{
	int	i;

	i = 0;
	while (lst != node)
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
		while (b != NULL)
			the_chosen_one(a, b);
		//finish(a, b);
	}
}

int	main(int argc, char *argv[])
{
	t_list	*a;
	t_list	*b;
	int	size;

	a = NULL;
	b = NULL;
	if (argc == 1)
		exit (0);
	a = ft_all_check(argv, argc);
	if (!a)
		ft_putstr_fd("Error\n", 2);
	if (ft_veriftri(a))
		return (free_lc(&a), 1);
	size = ft_lstsize(a);
	ft_push_swap(&a, &b, size);
	print_pile_ab(a, b);
	free_lc(&a);
	exit (0);
}
