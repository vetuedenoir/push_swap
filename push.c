/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kscordel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 11:05:54 by kscordel          #+#    #+#             */
/*   Updated: 2023/01/20 13:39:31 by kscordel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pushpm(t_list **lstplus, t_list **lstmoins)
{
	t_list	*tmp;

	if ((*lstmoins) != NULL)
	{
		tmp = (*lstmoins)->next;
		if ((*lstplus) != NULL)
			(*lstmoins)->next = (*lstplus);
		else
			(*lstmoins)->next = NULL;
		(*lstplus) = (*lstmoins);
		(*lstmoins) = tmp;
	}
}



