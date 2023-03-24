/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kscordel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 14:34:24 by kscordel          #+#    #+#             */
/*   Updated: 2023/03/04 14:34:38 by kscordel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	putstr_color(char *color, char *s)
{
	ft_putstr_fd(color, 1);
	ft_putstr_fd(s, 1);
	ft_putstr_fd(RESET, 1);
}

void	make_mouv(t_list **a, t_list **b, char *line)
{
	if (!ft_strncmp("sa\n", line, 3))
		swap(a);
	else if (!ft_strncmp("sb\n", line, 3))
		swap(a);
	else if (!ft_strncmp("ss\n", line, 3))
		sswap(a, b);
	else if (!ft_strncmp("ra\n", line, 3))
		rotate(a);
	else if (!ft_strncmp("rb\n", line, 3))
		rotate(b);
	else if (!ft_strncmp("rr\n", line, 3))
		rrotate(a, b);
	else if (!ft_strncmp("rra\n", line, 3))
		reverse_rotate(a);
	else if (!ft_strncmp("rrb\n", line, 3))
		reverse_rotate(b);
	else if (!ft_strncmp("rrr\n", line, 3))
		rreverse_rrotate(a, b);
	else if (!ft_strncmp("pa\n", line, 3))
		pushpm(a, b);
	else if (!ft_strncmp("pb\n", line, 3))
		pushpm(b, a);
	else
		ft_erreur(a, b, line);
}

void	read_mouv(t_list **a, t_list **b)
{
	char	*line;

	while (1)
	{
		line = get_next_line(0);
		if (!line)
			break ;
		make_mouv(a, b, line);
		free(line);
	}
	if (!ft_veriftri(*a))
		putstr_color(RED, "KO\n");
	else
		putstr_color(GREEN, "OK\n");
}

int	main(int argc, char *argv[])
{
	t_list	*a;
	t_list	*b;

	a = NULL;
	b = NULL;
	if (argc == 1)
		exit (0);
	a = ft_all_check(argv, argc);
	if (!a)
		ft_erreur(&a, &b, NULL);
	read_mouv(&a, &b);
	free_lc(&a);
	free_lc(&b);
	return (1);
}
