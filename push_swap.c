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

int		majorant(t_list *a, t_list *b)
{
	int	difference;

	difference =  *(int *)(a->content) - *(int *)(b->content);
	if (difference < 0)
		difference = INT_MAX;
	while (a != NULL ||	difference == 1)
	{
		if (*(int *)(a->content) > *(int *)(b->content) 
			&& *(int *)(a->content) - *(int *)(b->content) < difference)
			difference =  *(int *)(a->content) - *(int *)(b->content);
		a = a->next;
	}
	return (*(int *)(a->content));
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
}

t_mouvement	ft_calcule1(int nba, int nbb)
{
	t_mouvement mouv;

	init(mouv);
	if (nba > nbb)
	{
		mouv.rr = nbb;
		mouv.ra = nba - nbb;
		mouv.total = mouv.rr + mouv.ra;
	}
	else if (nba <= nbb)
	{
		mouv.rr = nbb;
		mouv.rb = nbb - nba;
		mouv.total = mouv.rr + mouv.rb;
	}
	return (mouv);
}

t_mouvement	ft_calcule2(int nba, int nbb)
{
	t_mouvement	mouv;

	init(mouv);
	if (nba > nbb)
	{
		mouv.rrr = nbb;
		mouv.rra = nba - nbb;
		mouv.total = mouv.rrr + mouv.rra;
	}
	else if (nba <= nbb)
	{
		mouv.rrr = nbb;
		mouv.rrb = nbb - nba;
		mouv.total = mouv.rrr + mouv.rrb;
	}
	return (mouv);
}

t_mouvement	ft_calcule3(int nba, int nbb, t_data data)
{
	t_mouvement mouv;

	init(mouv);
}

t_mouvement	ft_nbcoup(t_list *a, t_list *b, t_data coup, t_list *node)
{
	int	nbcoupa;
	int	nbcoupb;

	if (coup.sizea / 2 >= coup.posa - 1 && coup.sizeb / 2 >= coup.posb - 1)
	{
		nbcoupa = coup.posa - 1; 				// rotate
		nbcoupb = coup.posb - 1; 				// rotate
		return (ft_calcule1(coup.posa - 1, coup.posb - 1));
	}
	else if (coup.sizea / 2 < coup.posa - 1 && coup.sizeb / 2 < coup.posb - 1)
	{
		nbcoupa = coup.sizea - coup.posa + 1;	// reverse_rotate
		nbcoupb = coup.sizeb - coup.posb + 1;	// reverse_rotate
	}
	else if (coup.sizea / 2 >= coup.posa - 1 && coup.sizeb / 2 < coup.posb - 1)
	{
		nbcoupa = coup.posa - 1;				// rotate
		nbcoupb = coup.sizeb - coup.posb + 1;	// reverse_rotate
	}
	else if (coup.sizea / 2 < coup.posa - 1 && coup.sizeb / 2 >= coup.posb - 1)
	{
		nbcoupa = coup.sizea - coup.posa + 1;	// reverse_rotate
		nbcoupb = coup.posb - 1;				// rotate;
	}
}

t_list	the_chosen_one(t_list **a, t_list **b)
{
	t_list		*bx;
	t_list		*chosen;
	t_mouvement	action;
	t_mouvement	tmp;
	t_data		data;

	bx = *b;
	data.sizea = lstsize(*a);
	data.sizeb = lstsize(*b);
	data.posa = ft_pos(*a, majorant(*a, *b));
	data.posb = ft_pos(*b, bx);
	action = ft_nbcoup(*a, *b, data, bx);
	while (bx != NULL || action.total == 0)
	{	
		data.posa = ft_pos(*a, majorant(*a, *b));
		data.posb = ft_pos(*b, bx);
		tmp = ft_nbcoup(*a, *b, data, bx);
		if (tmp.total < action.total )
		{
			action = tmp;
			chosen = bx;
		}
		bx = bx->next;
	}
	ft_action(a, b , action);
}

void	to_the_top(t_list **a, t_list *majorant)
{
	int	i;
	t_list	*node;

	i = 0;
	node = *a;
	while (node != majorant)
	{
		node = node->next;
		i++;
	}
	if (lst_size(*a) / 2 >= i - 1)
	{
		while (*a != majorant)
			rotate(a, 'a');
	}
	else
	{
		while (*a != majorant)
			reverse_rotate(a, 'a');
	}
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


void	ft_push_swap(t_list **a, t_list **b, int size)
{
	if (size == 2)
		swap(a, 'a');
	if (size == 3)
		ft_algothree(a);
	if (size >= 4)
	{
		ft_pretri(a, b);
		
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
		ft_putstr_fd("Error", 2);
	if (ft_veriftri(a))
		return (free_lc(&a), 1);
	size = ft_lstsize(a);
	ft_push_swap(&a, &b, size);
	print_pile_ab(a, b);
	free_lc(&a);
	exit (0);
}
