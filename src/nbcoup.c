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

#include "../push_swap.h"

static	t_mouvement	nbcoup1(t_data coup, int mida, int midb)
{
	t_mouvement	m;

	ft_memset(&m, 0, sizeof(t_mouvement));
	if (mida >= coup.posa - 1 && midb >= coup.posb - 1)
		m = ft_calcule1(coup.posa - 1, coup.posb - 1);
	else if (mida < coup.posa - 1 && midb < coup.posb - 1)
		m = ft_calcule2(coup.sizea - coup.posa + 1, coup.sizeb - coup.posb + 1);
	else if (mida >= coup.posa - 1 && midb < coup.posb - 1)
		m = ft_calcule3(coup.posa - 1, coup.sizeb - coup.posb + 1, '1');
	else if (mida < coup.posa - 1 && midb >= coup.posb - 1)
		m = ft_calcule3(coup.sizea - coup.posa + 1, coup.posb - 1, '2');
	return (m);
}

static	t_mouvement	nbcoup2(t_data coup, int mida, int midb)
{
	t_mouvement	m;

	ft_memset(&m, 0, sizeof(t_mouvement));
	coup.posa += 1;
	if (mida >= coup.posa - 1 && midb >= coup.posb - 1)
		m = ft_calcule1(coup.posa - 2, coup.posb - 1);
	else if (mida < coup.posa - 1 && midb < coup.posb - 1)
		m = ft_calcule2(coup.sizea - coup.posa - 1, coup.sizeb - coup.posb + 1);
	else if (mida >= coup.posa - 1 && midb < coup.posb - 1)
		m = ft_calcule3(coup.posa - 2, coup.sizeb - coup.posb + 1, '1');
	else if (mida < coup.posa - 1 && midb >= coup.posb - 1)
		m = ft_calcule3(coup.sizea - coup.posa - 1, coup.posb - 1, '2');
	return (m);
}

static	t_mouvement	nbcoup3(t_data coup, int mida, int midb)
{
	t_mouvement	m;

	ft_memset(&m, 0, sizeof(t_mouvement));
	coup.posb += 1;
	if (mida >= coup.posa - 1 && midb >= coup.posb - 1)
		m = ft_calcule1(coup.posa - 1, coup.posb - 2);
	else if (mida < coup.posa - 1 && midb < coup.posb - 1)
		m = ft_calcule2(coup.sizea - coup.posa + 1, coup.sizeb - coup.posb - 1);
	else if (mida >= coup.posa - 1 && midb < coup.posb - 1)
		m = ft_calcule3(coup.posa - 1, coup.sizeb - coup.posb - 1, '1');
	else if (mida < coup.posa - 1 && midb >= coup.posb - 1)
		m = ft_calcule3(coup.sizea - coup.posa + 1, coup.posb - 2, '2');
	return (m);
}

static	t_mouvement	nbcoup4(t_data coup, int mida, int midb)
{
	t_mouvement	m;

	ft_memset(&m, 0, sizeof(t_mouvement));
	coup.posa += 1;
	coup.posb += 1;
	if (mida >= coup.posa - 1 && midb >= coup.posb - 1)
		m = ft_calcule1(coup.posa - 2, coup.posb - 2);
	else if (mida < coup.posa - 1 && midb < coup.posb - 1)
		m = ft_calcule2(coup.sizea - coup.posa - 1, coup.sizeb - coup.posb - 1);
	else if (mida >= coup.posa - 1 && midb < coup.posb - 1)
		m = ft_calcule3(coup.posa - 2, coup.sizeb - coup.posb - 1, '1');
	else if (mida < coup.posa - 1 && midb >= coup.posb - 1)
		m = ft_calcule3(coup.sizea - coup.posa - 1, coup.posb - 2, '2');
	return (m);
}

t_mouvement	ft_nbcoup(t_data coup)
{
	t_mouvement	m;
	int			mida;
	int			midb;

	mida = coup.sizea / 2;
	midb = coup.sizeb / 2;
	if (mida == 0)
		mida = 1;
	if (midb == 0)
		midb = 1;
	ft_memset(&m, 0, sizeof(t_mouvement));
	if (coup.posa > 1 && coup.posb > 1)
		m = nbcoup1(coup, mida, midb);
	else if (coup.posa == 1 && coup.posb > 1)
		m = nbcoup2(coup, mida, midb);
	else if (coup.posa > 1 && coup.posb == 1)
		m = nbcoup3(coup, mida, midb);
	else if (coup.posa == 1 && coup.posb == 1)
		m = nbcoup4(coup, mida, midb);
	return (m);
}
