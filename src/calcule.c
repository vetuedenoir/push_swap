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

#include "../push_swap.h"

t_mouvement	ft_calcule1(int nba, int nbb)
{
	t_mouvement	mouv;

	ft_memset(&mouv, 0, sizeof(t_mouvement));
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

	ft_memset(&mouv, 0, sizeof(t_mouvement));
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

t_mouvement	ft_calcule3(int nba, int nbb, char x)
{
	t_mouvement	m;

	ft_memset(&m, 0, sizeof(t_mouvement));
	if (x == '1')
	{
		m.total = nba + nbb;
		m.ra = nba;
		m.rrb = nbb;
	}
	if (x == '2')
	{
		m.total = nba + nbb;
		m.rra = nba;
		m.rb = nbb;
	}
	return (m);
}
