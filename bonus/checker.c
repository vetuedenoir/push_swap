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


void    make_mouv(t_list **a, t_list **b, char *line)
{
    if (!ft_strncmp("sa", line, 3))
        swap(a, 'a');
    else if (!ft_strncmp("sb", line, 3))
        swap(a, 'b');
    else if (!ft_strncmp("ss", line, 3))
        sswap(a, b);
    else if (!ft_strncmp("ra", line, 3))
        rotate(a, 'a');
    else if (!ft_strncmp("rb", line, 3))
        rotate(b, 'b');
    else if (!ft_strncmp("rr", line, 3))
        rrotate(a, b);
    else if (!ft_strncmp("rra", line, 3))
        reverse_rotate(a, 'a');
    else if (!ft_strncmp("rrb", line, 3))
        reverse_rotate(b, 'b');
    else if (!ft_strncmp("rrr", line, 3))
        rreverse_rrotate(a, b);
    else if (!ft_strncmp("pa", line, 3))
        pushpm(a, b, 'a');
    else if (!ft_strncmp("pb", line, 3))
        pushpm(b, a, 'b');
}

void    read_mouv(t_list **a, t_list **b)
{
    int     fd;
    char    *line;

    fd = open(stdin, O_RDONLY);
    if (fd == -1)
    {
        free_lc(a)
        exit (0);
    }
    while (line!= NULL)
    {
        line = get_next_line(fd);
        make_mouv(&a, &b, line);
        free(line);
    }
    if (*b || !ft_veriftri(a))
        ft_putstr_fd("KO\n" 1);
    else
        ft_putstr_fd("OK\n", 1);
}

int main(int argc, char *argv[])
{
    t_list  *a;
    t_list  *b;

    a = NULL;
    b = NULL;
    if (argc == 1)
        exit (0);
    a = ft_all_check(argv, argc);
    if (!a)
        ft_erreur(&a, &b);
    read_mouv(&a, &b);
    free_lc(&a);
    free_lc(&b);
    return (1);
}