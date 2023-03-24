/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fusion.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kscordel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 14:31:35 by kscordel          #+#    #+#             */
/*   Updated: 2023/01/24 19:42:52 by kscordel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	icopy(int *dest, const int *src, int index, int n)
{
	int	i;

	i = 0;
	while (index <= n)
	{
		dest[i] = src[index];
		index++;
		i++;
	}
}

static void	fusion(int *tab, int debut, int milieu, int fin)
{
	t_index	index;
	int		*x;
	int		*v;

	index.i = 0;
	index.j = 0;
	index.k = debut;
	x = malloc(sizeof(int) * ((milieu - debut) + 1));
	v = malloc(sizeof(int) * (fin - milieu));
	if (!x || !v)
		return ;
	icopy(x, tab, debut, milieu);
	icopy(v, tab, milieu + 1, fin);
	while (index.i < (milieu - debut + 1) && index.j < (fin - milieu))
	{
		if (x[index.i] <= v[index.j])
			tab[index.k++] = x[index.i++];
		else
			tab[index.k++] = v[index.j++];
	}
	icopy(&tab[index.k], x, index.i, (milieu - debut + 1) - 1);
	icopy(&tab[index.k], v, index.j, (milieu - fin) - 1);
	free(x);
	free(v);
}

void	trifusion(int *tab, int debut, int fin)
{
	int	m;

	m = 0;
	if (debut < fin)
	{
		m = (debut + fin) / 2;
		trifusion(tab, debut, m);
		trifusion(tab, m + 1, fin);
		fusion(tab, debut, m, fin);
	}
}
