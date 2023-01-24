/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kscordel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 11:25:00 by kscordel          #+#    #+#             */
/*   Updated: 2023/01/24 19:30:05 by kscordel         ###   ########.fr       */
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

void	ft_pretri(t_list **a, t_list **b)
{
	int	mediane;

	mediane = ft_mediane(*a);
	mediane = ft_mediane(*b);

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
	if (one > two && two > three)
	{
		swap(*a, 'a');
		reverse_rotate(a, 'a');
	}
	else if (one > two && one > three)
		rotate(a, 'a');
	else if (three < one && three < two)
		reverse_rotate(a, 'a');
	else if (one > two && one < three)
		swap(*a, 'a');
}

void	ft_push_swap(t_list **a, t_list **b, int size)
{
	if (size == 2)
		swap(*a, 'a');
	if (size == 3)
		ft_algothree(a);
	
	if (size > 100)
		ft_pretri(a, b);


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
		ft_putstr_fd("Error", 2);
	if (ft_veriftri(a))
		exit (0);
	size = ft_lstsize(a);
	ft_push_swap(&a, &b, size);
	/*
	ft_putstr_fd("\t        Init\n", 1);
	print_pile_ab(a, b);
	pushpm(&b, &a);
	ft_putstr_fd("\t        pb\n", 1);
	print_pile_ab(a, b);
	pushpm(&b, &a);
	ft_putstr_fd("\t        pb\n", 1);
	print_pile_ab(a, b);
	pushpm(&b, &a);
	ft_putstr_fd("\t        pb\n", 1);
	print_pile_ab(a, b);
	pushpm(&b, &a);
	ft_putstr_fd("\t        pb\n", 1);
	print_pile_ab(a, b);
	rrotate(&a, &b);
	ft_putstr_fd("\t        rr\n", 1);
	print_pile_ab(a, b);
	sswap(a, b);
	ft_putstr_fd("\t        ss\n", 1);
	print_pile_ab(a, b);
	rreverse_rrotate(&a, &b);
	ft_putstr_fd("\t       rrr\n", 1);
	print_pile_ab(a, b);
	*/
	exit (0);
}
