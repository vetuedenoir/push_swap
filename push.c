/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kscordel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 11:05:54 by kscordel          #+#    #+#             */
/*   Updated: 2023/01/27 15:18:45 by kscordel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pushpm(t_list **lstplus, t_list **lstmoins, char x)
{
	t_list	*tmp;
	t_list	*sauvegard;
	
	if (x == 'a')
			ft_putstr_fd("pa\n", 1);
		else
			ft_putstr_fd("pb\n", 1);
	if ((*lstmoins) != NULL)
	{
		tmp = (*lstmoins)->next;
		/*if ((*lstplus) != NULL)
			(*lstmoins)->next = (*lstplus); // peut etre pas bon
		else
			(*lstmoins)->next = NULL;*/
		if ((*lstplus) != NULL)
			sauvegard = *lstplus;
		else
			sauvegard = NULL;
		(*lstplus) = (*lstmoins);
		(*lstplus)->next = sauvegard;
		(*lstmoins) = tmp;
	}
}



