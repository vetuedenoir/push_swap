/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kscordel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 19:38:32 by kscordel          #+#    #+#             */
/*   Updated: 2023/03/02 19:38:38 by kscordel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	main(int argc, char *argv[])
{
	t_list	*a;
	t_list	*b;
	int		size;

	a = NULL;
	b = NULL;
	if (argc == 1)
		exit (0);
	a = ft_all_check(argv, argc);
	if (!a)
	{
		ft_putstr_fd("Error\n", 2);
		exit (0);
	}
	if (ft_veriftri(a))
		return (free_lc(&a), 1);
	size = ft_lstsize(a);
	ft_push_swap(&a, &b, size);
	free_lc(&a);
	exit (0);
}
