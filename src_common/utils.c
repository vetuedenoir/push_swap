/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kscordel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 17:20:46 by kscordel          #+#    #+#             */
/*   Updated: 2023/02/04 19:15:20 by kscordel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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

void	ft_erreur(t_list **a, t_list **b, char *line)
{
	free_lc(a);
	free_lc(b);
	if (line)
		free(line);
	ft_putstr_fd("Error\n", 2);
	exit (0);
}

void	*free_tt(char **ts)
{
	int	x;

	x = 0;
	while (ts[x])
		free(ts[x++]);
	free(ts);
	return (NULL);
}

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
	while (nptr[i] >= '0' && nptr[i] <= '9' && s < 19)
	{
		nbr = nbr * 10 + (nptr[i] - 48);
		i++;
		s++;
	}
	return (nbr * signe);
}
