/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_to_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kscordel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 15:06:45 by kscordel          #+#    #+#             */
/*   Updated: 2023/03/02 15:06:54 by kscordel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/*
t_mouvement	ft_nbcoup(t_data coup)
{
	t_mouvement	m;
	int	mida;
	int	midb;

	mida = coup.sizea / 2;
	midb = coup.sizeb / 2;
	if (mida == 0)
		mida = 1;
	if (midb == 0)
		midb = 1;
	m = init_mouvement();
	
	if (mida >= coup.posa - 1 && midb >= coup.posb - 1)
		m = ft_calcule1(coup.posa - 1, coup.posb - 1);

	else if (coup.sizea / 2 < coup.posa - 1 && coup.sizeb / 2 < coup.posb - 1)
			m = ft_calcule2(coup.sizea - coup.posa + 1, coup.sizeb - coup.posb + 1);

	else if (coup.sizea / 2 >= coup.posa - 1 && coup.sizeb / 2 < coup.posb - 1)
		m = ft_calcule3(coup.posa - 1, coup.sizeb - coup.posb + 1, coup, '1');

	else if (coup.sizea / 2 < coup.posa - 1 && coup.sizeb / 2 >= coup.posb - 1)
		m = ft_calcule3(coup.sizea - coup.posa + 1, coup.posb - 1, coup, '2');
	if (coup.posa == 1 && coup.posb > 1)
	{
		coup.posa += 1;
	if (coup.sizea / 2 >= coup.posa - 1 && coup.sizeb / 2 >= coup.posb - 1)
		m = ft_calcule1(coup.posa - 1, coup.posb - 1);

	else if (coup.sizea / 2 < coup.posa - 1 && coup.sizeb / 2 < coup.posb - 1)
			m = ft_calcule2(coup.sizea - coup.posa, coup.sizeb - coup.posb + 1);

	else if (coup.sizea / 2 >= coup.posa - 1 && coup.sizeb / 2 < coup.posb - 1)
		m = ft_calcule3(coup.posa - 1, coup.sizeb - coup.posb + 1, coup, '1');

	else if (coup.sizea / 2 < coup.posa - 1 && coup.sizeb / 2 >= coup.posb - 1)
		m = ft_calcule3(coup.sizea - coup.posa, coup.posb - 1, coup, '2');
	}
	else if (coup.posb == 1 && coup.posa > 1)
	{
		coup.posb += 1;
		if (coup.sizea / 2 >= coup.posa - 1 && coup.sizeb / 2 >= coup.posb - 1)
		m = ft_calcule1(coup.posa - 1, coup.posb - 1);

	else if (coup.sizea / 2 < coup.posa - 1 && coup.sizeb / 2 < coup.posb - 1)
			m = ft_calcule2(coup.sizea - coup.posa + 1, coup.sizeb - coup.posb);

	else if (coup.sizea / 2 >= coup.posa - 1 && coup.sizeb / 2 < coup.posb - 1)
		m = ft_calcule3(coup.posa - 1, coup.sizeb - coup.posb, coup, '1');

	else if (coup.sizea / 2 < coup.posa - 1 && coup.sizeb / 2 >= coup.posb - 1)
		m = ft_calcule3(coup.sizea - coup.posa + 1, coup.posb - 1, coup, '2');
	}
	else if (coup.posb == 1 && coup.posa == 1)
	{
		coup.posa += 1;
		coup.posb += 1;
	if (coup.sizea / 2 >= coup.posa - 1 && coup.sizeb / 2 >= coup.posb - 1)
		m = ft_calcule1(coup.posa - 1, coup.posb - 1);

	else if (coup.sizea / 2 < coup.posa - 1 && coup.sizeb / 2 < coup.posb - 1)
			m = ft_calcule2(coup.sizea - coup.posa, coup.sizeb - coup.posb);

	else if (coup.sizea / 2 >= coup.posa - 1 && coup.sizeb / 2 < coup.posb - 1)
		m = ft_calcule3(coup.posa - 1, coup.sizeb - coup.posb, coup, '1');

	else if (coup.sizea / 2 < coup.posa - 1 && coup.sizeb / 2 >= coup.posb - 1)
		m = ft_calcule3(coup.sizea - coup.posa, coup.posb - 1, coup, '2');
	}

    //ft_printf("rrr = %d\nrr = %d \nra = %d \n rb = %d\nrra = %d\nrrb = %d\n\n", m.rrr, m.rr, m.ra, m.rb, m.rra, m.rrb );
	return (m);
}*/

void    ft_action(t_list **a, t_list **b, t_mouvement action)
{
	//ft_printf("rrr = %d\nrr = %d \nra = %d \n rb = %d\nrra = %d\nrrb = %d\n", action.rrr, action.rr, action.ra, action.rb, action.rra, action.rrb );
    while (action.rrr-- > 0 )
        rreverse_rrotate(a, b);
    while (action.rr-- > 0)
	{	//ft_printf("rrr = %d\nrr = %d \nra = %d \n rb = %d\nrra = %d\nrrb = %d\n", action.rrr, action.rr, action.ra, action.rb, action.rra, action.rrb );
		rrotate(a, b);
	}  
    while (action.ra-- > 0)
        rotate(a, 'a');
    while (action.rb-- > 0)
        rotate(b, 'b');
    while (action.rra-- > 0)
        reverse_rotate(a, 'a');
    while (action.rrb-- > 0)
	{
		reverse_rotate(b, 'b');
	}
	pushpm(a, b, 'a');
}

void	the_chosen_one(t_list **a, t_list **b)
{
	t_list		*bx;
	t_mouvement	action;
	t_mouvement	tmp;
	t_data		data;

	bx = *b;
	data = init_data(*a, *b, bx);
	action = ft_nbcoup(data);
	while (bx != NULL)
	{	
		data.posa = ft_pos(*a, majorant(*a, bx));
		data.posb = ft_pos(*b, bx);
		tmp = ft_nbcoup(data);
		//printf("posa = %d \n posb = %d \n sizea = %d \n sizeb = %d \n\n", data.posa, data.posb, data.sizea, data.sizeb);
		//ft_printf("rrr = %d\nrr = %d \nra = %d \n rb = %d\nrra = %d\nrrb = %d\n\n", tmp.rrr, tmp.rr, tmp.ra, tmp.rb, tmp.rra, tmp.rrb );
		if (tmp.total < action.total)
			action = tmp;
		bx = bx->next;
	}
	//printf("posa = %d \n posb = %d \n sizea = %d \n sizeb = %d \n\n", data.posa, data.posb, data.sizea, data.sizeb);
	//ft_printf("rrr = %d\nrr = %d \nra = %d \n rb = %d\nrra = %d\nrrb = %d\n", action.rrr, action.rr, action.ra, action.rb, action.rra, action.rrb );
	ft_action(a, b , action);
}
