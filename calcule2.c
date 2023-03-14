/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcule2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kscordel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 17:29:07 by kscordel          #+#    #+#             */
/*   Updated: 2023/03/03 17:29:12 by kscordel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	if (coup.posa > 1 && coup.posb > 1)
    {	//printf("passer par 1\n");
	if (mida >= coup.posa - 1 && midb >= coup.posb - 1)
		m = ft_calcule1(coup.posa - 1, coup.posb - 1);

	else if (mida < coup.posa - 1 && midb < coup.posb - 1)
			m = ft_calcule2(coup.sizea - coup.posa + 1, coup.sizeb - coup.posb + 1);
	
	else if (mida >= coup.posa - 1 && midb < coup.posb - 1)
		m = ft_calcule3(coup.posa - 1, coup.sizeb - coup.posb + 1, coup, '1');

	else if (mida < coup.posa - 1 && midb >= coup.posb - 1)
		m = ft_calcule3(coup.sizea - coup.posa + 1, coup.posb - 1, coup, '2');
    
	}

	if (coup.posa == 1 && coup.posb > 1)
	{//printf("passer par 2\n");
		coup.posa += 1;
	if (mida >= coup.posa - 1 && midb >= coup.posb - 1)
		m = ft_calcule1(coup.posa - 2, coup.posb - 1);

	else if (mida < coup.posa - 1 && midb < coup.posb - 1)
			m = ft_calcule2(coup.sizea - coup.posa - 1, coup.sizeb - coup.posb + 1);
	
	else if (mida >= coup.posa - 1 && midb < coup.posb - 1)
		m = ft_calcule3(coup.posa - 2, coup.sizeb - coup.posb + 1, coup, '1');

	else if (mida < coup.posa - 1 && midb >= coup.posb - 1)
		m = ft_calcule3(coup.sizea - coup.posa - 1, coup.posb - 1, coup, '2');
	
	}

	else if (coup.posa > 1 && coup.posb == 1)
	{//printf("passer par 3\n");
		coup.posb += 1;
		if (mida >= coup.posa - 1 && midb >= coup.posb - 1)
		m = ft_calcule1(coup.posa - 1, coup.posb - 2);

	else if (mida < coup.posa - 1 && midb < coup.posb - 1)
			m = ft_calcule2(coup.sizea - coup.posa + 1, coup.sizeb - coup.posb - 1);
	
	else if (mida >= coup.posa - 1 && midb < coup.posb - 1)
		m = ft_calcule3(coup.posa - 1, coup.sizeb - coup.posb - 1, coup, '1');

	else if (mida < coup.posa - 1 && midb >= coup.posb - 1)
		m = ft_calcule3(coup.sizea - coup.posa + 1, coup.posb - 2, coup, '2');
	
	}

	else if (coup.posa == 1 && coup.posb == 1)
	{//printf("passer par 4\n");
		coup.posa += 1;
		coup.posb += 1;
	if (mida >= coup.posa - 1 && midb >= coup.posb - 1)
		m = ft_calcule1(coup.posa - 2, coup.posb - 2);

	else if (mida < coup.posa - 1 && midb < coup.posb - 1)
			m = ft_calcule2(coup.sizea - coup.posa - 1, coup.sizeb - coup.posb - 1);
	
	else if (mida >= coup.posa - 1 && midb < coup.posb - 1)
		m = ft_calcule3(coup.posa - 2, coup.sizeb - coup.posb - 1, coup, '1');

	else if (mida < coup.posa - 1 && midb >= coup.posb - 1)
		m = ft_calcule3(coup.sizea - coup.posa - 1, coup.posb - 2, coup, '2');
	
	}

    //ft_printf("rrr = %d\nrr = %d \nra = %d \n rb = %d\nrra = %d\nrrb = %d\n\n", m.rrr, m.rr, m.ra, m.rb, m.rra, m.rrb );
	return (m);
}
/*
t_mouvement sub1_nbcoup(t_data coup)
{

}


t_mouvement sub2_nbcoup(t_data coup)
{

}
*/