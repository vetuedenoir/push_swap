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

#include "push_swap.h"

t_mouvement	ft_calcule1(int nba, int nbb)
{
	t_mouvement mouv;

	//ft_printf("calcule 1 : nba = %d et nbb = %d\n\n", nba, nbb);
	mouv = init_mouvement();
	if (nba > nbb)
	{
		mouv.rr = nbb;
		mouv.ra = nba - nbb;
		mouv.total = mouv.rr + mouv.ra;
	}
	else if (nba <= nbb)
	{
		mouv.rr = nba;
		mouv.rb = nbb - nba;
		mouv.total = mouv.rr + mouv.rb;
	}
	return (mouv);
}

t_mouvement	ft_calcule2(int nba, int nbb)
{
	t_mouvement	mouv;

	//ft_printf("calcule 2 : nba = %d et nbb = %d\n\n", nba, nbb);
	mouv = init_mouvement();
	if (nba > nbb)
	{
		mouv.rrr = nbb;
		mouv.rra = nba - nbb;
		mouv.total = mouv.rrr + mouv.rra;
	}
	else if (nba <= nbb)
	{
		mouv.rrr = nba;
		mouv.rrb = nbb - nba;
		mouv.total = mouv.rrr + mouv.rrb;
	}
	return (mouv);
}

t_mouvement	sub_calcule1(int nba, int nbb, t_data data, int inversex)
{
	t_mouvement mouv;

	//ft_printf("nba = %d et nbb = %d\n", nba, nbb);
	mouv = init_mouvement();
	if (inversex < nba + nbb)
	{
		if (inversex == data.sizea - nba)
		{
			mouv.rrr = nbb;
			mouv.ra = data.sizea - nba - nbb;
			mouv.total = mouv.rrr + mouv.ra;
		}
		if (inversex == data.sizeb - nbb)
		{
			mouv.rr = nba;
			mouv.rb = data.sizeb - nbb - nba;
			mouv.total = mouv.rr + mouv.rb;
		}
	}
	else
	{
		mouv.ra = nba;
		mouv.rrb = nbb;
		mouv.total = mouv.ra + mouv.rrb;
	}
	return (mouv);
}

t_mouvement	sub_calcule2(int nba, int nbb, t_data data, int inversex)
{
	t_mouvement mouv;

	//ft_printf("nba = %d et nbb = %d\n", nba, nbb);
	mouv = init_mouvement();
	if (inversex < nba + nbb)
	{
		if (inversex == data.sizea - nba)
		{
			mouv.rr = nbb;
			mouv.ra = data.sizea - nba - nbb;
			mouv.total = mouv.rr + mouv.ra;
		}
		if (inversex == data.sizeb - nbb)
		{
			mouv.rrr = nba;
			mouv.rb = data.sizeb - nbb - nba;
			mouv.total = mouv.rrr + mouv.rb;
		}
	}
	else
	{
		mouv.rra = nba;
		mouv.rb = nbb;
		mouv.total = mouv.rra + mouv.rb;
	}
	return (mouv);
}

t_mouvement	ft_calcule3(int nba, int nbb, t_data data, char x)
{
	int	inversex;
	t_mouvement m;
	inversex = 0;
	//ft_printf("calcule 3 nba = %d et nbb = %d\t", nba, nbb);
//pour les testes
	m = init_mouvement();
	if (x == '1')
	{
		//ft_printf("x = 1\n\n");
		m.total = nba + nbb;
		m.ra = nba;
		m.rrb = nbb;
	}
	if (x == '2')
	{

		//ft_printf("x = 2\n\n");
		m.total = nba + nbb;
		m.rra = nba;
		m.rb = nbb;
	}
	inversex = data.posa;
	return (m);
/*
	if (data.sizea - nba > data.sizeb - nbb)
		inversex = data.sizeb - nbb;
	else if (data.sizea - nba <= data.sizeb - nbb)
		inversex = data.sizea - nba;
	if (x == '1')
		return (sub_calcule1(nba, nbb, data, inversex));
	if (x == '2')
		return (sub_calcule2(nba, nbb, data, inversex));
	else 
		return (init_mouvement());
	*/
}
