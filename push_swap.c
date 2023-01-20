/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kscordel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 11:25:00 by kscordel          #+#    #+#             */
/*   Updated: 2023/01/20 18:26:25 by kscordel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_list	*a;
	t_list	*b;
	char	error;

	a = NULL;
	b = NULL;
	error = 0;
	if (argc == 1)
		exit (0);
	a = ft_all_check(argv, argc);
	if (!a)
		ft_putstr_fd("Error", 2);
	pushpm(&b, &a);
	print_pile_ab(a, b);
	pushpm(&b, &a);
	print_pile_ab(a, b);
	pushpm(&b, &a);
	print_pile_ab(a, b);
	pushpm(&b, &a);
	print_pile_ab(a, b);
	rrotate(&a, &b);
	print_pile_ab(a, b);
	sswap(a, b);
	print_pile_ab(a, b);
	rreverse_rrotate(&a, &b);
	print_pile_ab(a, b);
	exit (0);
}
