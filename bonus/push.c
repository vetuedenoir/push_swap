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

#include "./checker.h"

void	pushpm(t_list **lstplus, t_list **lstmoins)
{
	t_list	*tmp;

	if (*lstmoins)
	{
		tmp = *lstmoins;
		*lstmoins = (*lstmoins)->next;
		tmp->next = *lstplus;
		*lstplus = tmp;
	}
}
