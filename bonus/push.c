/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kscordel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 14:36:30 by kscordel          #+#    #+#             */
/*   Updated: 2023/03/04 14:36:32 by kscordel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void    pushpm(t_list **lstplus, t_list **lstmoins, char x)
{
    t_list    *tmp;

    if (*lstmoins)
    {
        tmp = *lstmoins;
        *lstmoins = (*lstmoins)->next;
        tmp->next = *lstplus;
        *lstplus = tmp;
    }
	if (x == 'a')
		write(1, "pa\n", 3);
	if (x == 'b')
		write(1, "pb\n", 3);
}