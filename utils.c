/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kscordel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 17:20:46 by kscordel          #+#    #+#             */
/*   Updated: 2023/01/18 18:17:13 by kscordel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	*free_tt(char **ts)
{
	int	x;

	x = 0;
	while (ts[x])
		free(ts[x++]);
	free(ts);
	return (NULL);
}

void	free_lc(t_list *lst)
{
	t_list	*tmp;

	tmp = NULL;
	while (lst != NULL)
	{
		lst->next = tmp;
		if (lst->content)
			free(lst->content);
		free(lst);
		lst = tmp;
	}
	//return (NULL);
}

long	ft_atol(const char *nptr)
{
	int		i;
	long	signe;
	long	nbr;

	i = 0;
	signe = 1;
	nbr = 0;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == 32)
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			signe *= -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		nbr = nbr * 10 + (nptr[i] - 48);
		i++;
	}
	return (nbr * signe);
}

void	ft_print_lst(t_list *lst)
{
	while (lst)
	{
		printf("%d\n", *(int *)(lst->content));
		lst = lst->next;
	}
}
