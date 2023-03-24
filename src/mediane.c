/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mediane.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kscordel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 20:03:16 by kscordel          #+#    #+#             */
/*   Updated: 2023/01/26 16:48:32 by kscordel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_mediane(t_list *lst)
{
	t_index	index;
	int		*tab;
	int		mediane;

	index.i = 0;
	index.k = ft_lstsize(lst);
	tab = malloc(sizeof(int) * (index.k + 1));
	if (!tab)
		exit(0);
	while (lst)
	{
		tab[index.i++] = *(int *)(lst->content);
		lst = lst->next;
	}
	tab[index.i] = 0;
	trifusion(tab, 0, index.k);
	if (index.k % 2 == 0)
		mediane = (tab[index.k / 2] + tab[index.k / 2 + 1]) / 2;
	else
		mediane = tab[index.k / 2 + 1];
	free(tab);
	return (mediane);
}

int	ft_bigest(t_list *lst)
{
	int	bigest;

	bigest = *(int *)lst->content;
	while (lst)
	{
		if (bigest < *(int *)lst->content)
			bigest = *(int *)lst->content;
		lst = lst->next;
	}
	return (bigest);
}
