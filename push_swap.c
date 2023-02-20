/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kscordel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 11:25:00 by kscordel          #+#    #+#             */
/*   Updated: 2023/02/02 16:42:42 by kscordel         ###   ########.fr       */
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
	int	bigest;
	int	i;
	int	x;

	i = 0;
	x = 0;
	print_pile_ab(*a, *b);
	mediane = ft_mediane(*a);
	bigest = ft_bigest(*a);
	//while (*a != NULL)
	while (*(int *)((*a)->content) != bigest)
	{
		if (*(int *)((*a)->content) != bigest)
		{
			pushpm(b, a, 'b');
			print_pile_ab(*a, *b);
			if (*(int *)((*b)->content) < mediane && i)
			{
				rotate(b, 'b');
				print_pile_ab(*a, *b);
			}
					i++;
		}
		else
		{
			if (!x)
			{
				rotate(a, 'a');
				print_pile_ab(*a, *b);
			}
			else
				break ;
			x++;
		}
	}}


/*
void    ft_pretri(t_list **list_a, t_list **list_b)
{
    t_list    *node;
    t_list    *max_node;
    int        max_value;
    int		mediane;
    

	mediane = ft_mediane(*list_a);
    node = *list_a;
    max_node = node;
    max_value = *(int *)node->content;
    while (node != NULL)
    // On parcourt la liste jusqu'à trouver l'élément ayant la valeur maximale
    {
        if (*(int *)node->content > max_value)
        {
            max_node = node;
            max_value = *(int *)node->content;
        }
        node = node->next;
    }
    node = *list_a; //reset

    while (*list_a != NULL)
       {
        if (*list_a != max_node)
        {
            pushpm(list_b, list_a, 'b');
	    print_pile_ab(*list_a, *list_b);
            if (*(int *)(*list_b)->content < mediane)
            {
	    	rotate(list_b, 'b');
		print_pile_ab(*list_a, *list_b);
	    }
        }
        else
            break ;
    }
    *list_a = max_node;
    // On remet l'élément ayant la valeur maximale en tête de list_a
    rotate(list_a, 'a');
    print_pile_ab(*list_a, *list_b);
}
*/


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

void	ft_push_swap(t_list **a, t_list **b, int size)
{
	if (size == 2)
		swap(a, 'a');
	if (size == 3)
		ft_algothree(a);
	if (size >= 4)
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
		return (free_lc(&a), 1);
	size = ft_lstsize(a);
	ft_push_swap(&a, &b, size);
	print_pile_ab(a, b);
	free_lc(&a);
	exit (0);
}
