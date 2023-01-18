/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kscordel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 11:05:54 by kscordel          #+#    #+#             */
/*   Updated: 2023/01/18 19:32:34 by kscordel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_list *lstplus, t_list *lstmoins)
{
	t_list	tmp;

	if (lstmoins)
	{
		tmp = lstmoins->next;
		lstmoins = lstplus;
		lstmoins = tmp;
	}
}



