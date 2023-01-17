/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kscordel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 11:25:00 by kscordel          #+#    #+#             */
/*   Updated: 2023/01/17 19:58:52 by kscordel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_check_nbr(char **argument)
{
	int	x;
	int	y;

	x = 0;
	while (argument[x])
	{
		y = 0;
		if (argument[x][y] == '-')
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

int	*ft_convert(const char *str)
{
	long	l;

	l = ft_atol(argument[x++]);
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
	int	x;
	int	*nbr;
	t_list	*fisrt;
	t_list	*tmp;

	x = 1;
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
			return (NULL);
		tmp->next = ft_convert(argument[x]);
		if (!tmp->next)
			return (free(nbr), NULL);
		tmp = tmp->next;
	}
	return (first);
}

t_list	*ft_check_doublons(t_list lst, int argc) // la refaire pour liste chaine
{
	int	i;
	int	y;

	i = 0;
	while (i < argc)
	{
		y = i + 1;
		while (y < argc)
		{
			if (tab[i] == tab[y])
				return (0);
			y++;
		}
		i++;
	}
	return (1);
}

t_list	*ft_all_check(char **argument, int argc, t_list *a)
{
	char	**taba;

	if (argc == 2)
	{
		taba = ft_split(argument);
		if (!taba)
			return (NULL);
		if (!ft_check_nbr(taba));
			return (ft_free_tab(taba, argc));
		a = ft_transfo(taba);
	}
	else
	{
		ft_check_nbr(argument);
		if (!ft_check_nbr(argument));		// check si les argument sont des nombres
			return (NULL);
		a = ft_transfo(argument);		// passe tout en int avec atoi + check si c est des int
	}
	if(!tab)
		return (NULL);
	if (!ft_check_doublons(a))		// regarde si il n y a pas de doublons;
		return (NULL);
	return (a);		// renvoie la liste chaine si tout les teste sont bon
}

int	main(int argc, char *argv[])
{
	t_list	a;
	t_list	b;
	char	error;
	char	**taba;

	error = 0;
	if (argc == 1)
		return (0);
	a = ft_all_check(argv, argc);
	if (!a)
		ft_putstr_fd("Error", 2);
	else
		ft_algo(a, b);
	return (0);
}
