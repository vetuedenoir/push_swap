/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kscordel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 14:41:29 by kscordel          #+#    #+#             */
/*   Updated: 2023/03/02 14:51:32 by kscordel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_mouvement init_mouvement(void)
{
	t_mouvement mouv;

	mouv.ra = 0;
	mouv.rr = 0;
	mouv.rrr = 0;
	mouv.rb = 0;
	mouv.rra = 0;
	mouv.rrb = 0;
	mouv.total = 0;
	return (mouv);
}

t_data	init_data(t_list *a, t_list *b, t_list *node)
{
	t_data	data;

	data.sizea = ft_lstsize(a);
	data.sizeb = ft_lstsize(b);
	data.posa = ft_pos(a, majorant(a, b));
	data.posb = ft_pos(b, node);
	return (data);
}

t_index	init_index(void)
{
	t_index index;

	index.i = 0;
	index.j = 0;
	index.k = 0;
	return (index);
}
