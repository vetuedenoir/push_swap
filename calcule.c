/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcule.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kscordel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 16:16:45 by kscordel          #+#    #+#             */
/*   Updated: 2023/02/28 16:16:52 by kscordel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.c"

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

t_mouvement	sub_calcule1(int nba, int nbb, t_data data, int inversex)
{
	t_mouvement mouv;

	init(mouv);
	if (inversex < nba + nbb)
	{
		if (inversex == data.sizea - nba)
		{
			mouv.rrr = nbb;
			mouv.ra = data.sizea - nba - nbb;
		}
		if (inversex == data.sizeb - nbb)
		{
			mouv.rr = nba;
			mouv.rb = data.sizeb - nbb - nba;
		}
	}
	else
	{
		mouv.ra = nba;
		mouv.rrb = nbb;
	}
	return (mouv);
}

t_mouvement	sub_calcule2(int nba, int nbb, t_data data, int inversex)
{
	t_mouvement mouv;

	init(mouv);
	if (inversex < nba + nbb)
	{
		if (inversex == data.sizea - nba)
		{
			mouv.rr = nbb;
			mouv.ra = data.sizea - nba - nbb;
		}
		if (inversex == data.sizeb - nbb)
		{
			mouv.rrr = nba;
			mouv.rb = data.sizeb - nbb - nba;
		}
	}
	else
	{
		mouv.ra = nba;
		mouv.rrb = nbb;
	}
	return (mouv);
}

t_mouvement	ft_calcule3(int nba, int nbb, t_data data, char x)
{
	int	inversex;

	inversex = 0;
	if (data.sizea - nba > data.sizeb - nbb)
		inversex = data.sizeb - nbb;
	else if (data.sizea - nba <= data.sizeb - nbb)
		inversex = data.sizea - nba;
	if (x = '1')
		return (sub_calcule1(nba, nbb, data, inversex));
	if (x = '2')
		return (sub_calcule2(nba, nbb, data, inversex));
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
		return (ft_calcule2(coup.sizea - coup.posa + 1, coup.sizeb - coup.posb + 1));
	}
	else if (coup.sizea / 2 >= coup.posa - 1 && coup.sizeb / 2 < coup.posb - 1)
	{
		nbcoupa = coup.posa - 1;				// rotate
		nbcoupb = coup.sizeb - coup.posb + 1;	// reverse_rotate
		return (ft_calcule3(coup.posa - 1, coup.sizeb - coup.posb + 1, coup, '1'));
	}
	else if (coup.sizea / 2 < coup.posa - 1 && coup.sizeb / 2 >= coup.posb - 1)
	{
		nbcoupa = coup.sizea - coup.posa + 1;	// reverse_rotate
		nbcoupb = coup.posb - 1;				// rotate;
		return (ft_calcule3(coup.sizea - coup.posa + 1, coup.posb - 1, coup, '2'));
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
