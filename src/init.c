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

#include "../push_swap.h"

t_data	init_data(t_list *a, t_list *b, t_list *node)
{
	t_data	data;

	data.sizea = ft_lstsize(a);
	data.sizeb = ft_lstsize(b);
	data.posa = ft_pos(a, majorant(a, node));
	data.posb = ft_pos(b, node);
	return (data);
}

t_index	init_index(void)
{
	t_index	index;

	index.i = 0;
	index.j = 0;
	index.k = 0;
	return (index);
}
