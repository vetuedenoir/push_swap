/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kscordel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 14:37:29 by kscordel          #+#    #+#             */
/*   Updated: 2023/03/04 14:37:31 by kscordel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	free_lc(t_list **lst)
{
	t_list	*tmp;

	if (!lst)
		return ;
	while (*lst != NULL)
	{
		tmp = (*lst)->next;
		if ((*lst)->content != NULL)
			free((*lst)->content);
		free(*lst);
		*lst = tmp;
	}
}

long	ft_atol(const char *nptr)
{
	int		i;
	int		s;
	long	signe;
	long	nbr;

	i = 0;
	signe = 1;
	nbr = 0;
	s = 0;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == 32)
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			signe *= -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9' && s < 15 )
	{
		nbr = nbr * 10 + (nptr[i] - 48);
		i++;
		s++;
	}
	return (nbr * signe);
}

void    ft_erreur(t_list **a, t_list **b)
{
    free_lc(a);
    free_lc(b);
    ft_putstr_fd("Error\n", 2);
    exit (0);
}

int	ft_veriftri(t_list *lst)
{
	int	r;

	while (lst)
	{
		r = *(int *)(lst->content);
		lst = lst->next;
		if (lst == NULL)
			break ;
		if (r > *(int *)(lst->content))
			return (0);
	}
	return (1);
}