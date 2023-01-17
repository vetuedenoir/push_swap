/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kscordel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 17:20:46 by kscordel          #+#    #+#             */
/*   Updated: 2023/01/17 19:58:58 by kscordel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*free_all(char **ts, int x)
{
	while (x-- >= 0)
		free(ts[x]);
	free(ts);
	return (NULL);
}

long	ft_atol(const char *str)
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

t_list	*ft_init(int *tab, int argc)
{
	int	i;
	t_list	*first;
	t_list	*tmp;

	i = 0;
	first = ft_lstnew(tab[i++]);
	tmp = first;
	while (i < argc)
	{
		tmp->next = ft_lstnew(tab[i++]);
		if (!tmp->next)
			break ;
		tmp = tmp->next;
	}
	free(tab);
	return (first);
}

// faire une fonction pour free la list chaine lol :')
