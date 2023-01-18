/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kscordel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 11:25:00 by kscordel          #+#    #+#             */
/*   Updated: 2023/01/18 17:50:29 by kscordel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_list	*a;
	char	error;

	a = NULL;
	error = 0;
	if (argc == 1)
		exit (0);
	a = ft_all_check(argv, argc);
	if (!a)
		ft_putstr_fd("Error", 2);
	swap(a);
	ft_print_lst(a);
	exit (0);
}
