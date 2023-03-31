/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kscordel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 11:35:55 by kscordel          #+#    #+#             */
/*   Updated: 2023/01/28 19:24:11 by kscordel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_check_doublons(t_list *lst)
{
	t_list	*tmp2;

	while (lst)
	{
		tmp2 = lst->next;
		while (tmp2)
		{
			if (*(int *)(lst->content) == *(int *)(tmp2->content))
				return (0);
			tmp2 = tmp2->next;
		}
		lst = lst->next;
	}
	return (1);
}

int	*ft_convert(const char *str)
{
	long	l;
	int		*nbr;
	int		i;

	if (str == NULL)
		return (NULL);
	i = 0;
	while (str[i] == '0')
		i++;
	l = ft_atol(&str[i]);
	if (l < INT_MIN || l > INT_MAX)
		return (NULL);
	nbr = malloc(sizeof(int) * 1);
	if (!nbr)
		return (NULL);
	*nbr = l;
	return (nbr);
}

t_list	*ft_transfo(char **argument)
{
	int		x;
	int		*nbr;
	t_list	*first;
	t_list	*tmp;

	x = 0;
	nbr = ft_convert(argument[x]);
	if (!nbr)
		return (NULL);
	first = ft_lstnew(nbr);
	if (!first)
		return (free(nbr), NULL);
	tmp = first;
	while (argument[++x])
	{
		nbr = ft_convert(argument[x]);
		if (!nbr)
			return (free_lc(&first), NULL);
		tmp->next = ft_lstnew(nbr);
		if (!tmp->next)
			return (free_lc(&first), NULL);
		tmp = tmp->next;
	}
	return (first);
}

int	ft_check_nbr(char **argument)
{
	int	x;
	int	y;

	x = 0;
	if (!argument[x])
		return (0);
	while (argument[x])
	{
		y = 0;
		if ((argument[x][y] == '-' || argument[x][y] == '+')
			&& argument[x][y + 1] && ft_isdigit(argument[x][y + 1]))
			y++;
		while (argument[x][y])
		{
			if (!ft_isdigit(argument[x][y]))
				return (0);
			y++;
		}
		x++;
	}
	return (1);
}

t_list	*ft_all_check(char **argument, int argc)
{
	char	**taba;
	t_list	*a;

	if (argc == 2)
	{
		taba = ft_split(argument[1], ' ');
		if (!taba)
			return (NULL);
		if (!ft_check_nbr(taba))
			return (free_tt(taba));
		a = ft_transfo(taba);
		free_tt(taba);
	}
	else
	{
		if (!ft_check_nbr(&argument[1]))
			return (NULL);
		a = ft_transfo(&argument[1]);
	}
	if (!a)
		return (NULL);
	if (!ft_check_doublons(a))
		return (free_lc(&a), NULL);
	return (a);
}
