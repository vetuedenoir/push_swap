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
	//return (NULL);
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

void	ft_print_lst(t_list *lst)
{
	while (lst)
	{
		ft_printf("%d\n", *(int *)(lst->content));
		lst = lst->next;
	}
}

static t_list	*printbig(t_list *big, int t)
{
	while (t && big)
	{
		if (*(int *)(big->content) > 9999999 || *(int *)(big->content) < -999999)
			ft_printf("\n%d\t| \n", *(int *)(big->content));
		else
			ft_printf("\n%d\t\t| \n", *(int *)(big->content));
		big = big->next;
		t--;
	}
	return (big);
}

void	print_pile_ab(t_list *a, t_list *b)
{
	int	ta;
	int	tb;

	ta = ft_lstsize(a);
	tb = ft_lstsize(b);
	if (ta - tb > 0)
		a = printbig(a, ta - tb); 
	else if (tb - ta > 0)
		b = printbig(b, tb - ta);
	while (a && b)
	{
		if (*(int *)(a->content) > 9999999 || *(int *)(a->content) < -999999)
			printf("\n%d\t| %d\n", *(int *)(a->content), *(int *)(b->content));
		else
			printf("\n%d\t\t| %d\n", *(int *)(a->content), *(int *)(b->content));
		a = a->next;
		b = b->next;
	}
	ft_printf("\nPile a\t\t| Pile b\n");
	ft_printf("-----------------------------------------\n\n");
}
