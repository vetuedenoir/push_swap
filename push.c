/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kscordel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 11:05:54 by kscordel          #+#    #+#             */
/*   Updated: 2023/02/02 15:20:53 by kscordel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pushpm(t_list **lstplus, t_list **lstmoins, char x)
{
	t_list	*plus;
	t_list	*moins;
	t_list	*sauvegard;
	
	if (x == 'a')
			ft_putstr_fd("pa\n", 1);
		else
			ft_putstr_fd("pb\n", 1);
	if ((*lstmoins) != NULL)
	{
		moins = (*lstmoins)->next;
		/*if ((*lstplus) != NULL)
			(*lstmoins)->next = (*lstplus); // peut etre pas bon
		else
			(*lstmoins)->next = NULL;*/
		if ((*lstplus) != NULL)
			sauvegard = *lstplus;
		else
			sauvegard = NULL;
		plus = (*lstmoins);
		plus->next = sauvegard;
		(*lstmoins) = moins;
		*lstplus = plus;
	}
}



