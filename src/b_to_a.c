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

#include "../push_swap.h"

void	ft_action(t_list **a, t_list **b, t_mouvement action)
{
	while (action.rrr-- > 0)
		rreverse_rrotate(a, b);
	while (action.rr-- > 0)
		rrotate(a, b);
	while (action.ra-- > 0)
		rotate(a, 'a');
	while (action.rb-- > 0)
		rotate(b, 'b');
	while (action.rra-- > 0)
		reverse_rotate(a, 'a');
	while (action.rrb-- > 0)
		reverse_rotate(b, 'b');
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
		if (tmp.total < action.total)
			action = tmp;
		bx = bx->next;
	}
	ft_action(a, b, action);
}
