/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kscordel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 17:33:55 by kscordel          #+#    #+#             */
/*   Updated: 2023/01/14 17:30:39 by kscordel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ft_testreturn(const char *s, char f)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] == '\n')
			return (i + 1);
		i++;
	}
	if (f)
		return (i);
	return (0);
}

char	*ft_read_file(char *stash, int mark, int fd)
{
	char	*buf;
	int		index;
	int		readed;
	int		total;

	total = ft_length(&stash[mark]) + mark;
	readed = 0;
	index = 0;
	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	while (!index)
	{
		readed = read(fd, buf, BUFFER_SIZE);
		if (!readed || readed == -1)
			break ;
		buf[readed] = '\0';
		index = ft_testreturn(buf, 0);
		total += readed;
		stash = ft_add_buf(stash, buf, total);
	}
	free(buf);
	return (stash);
}

char	*get_next_line(int fd)
{
	static t_backup		backup[1024];
	char				*line;
	int					index;
	int					t;

	if (fd < 0 || fd > 1024)
		return (NULL);
	index = 0;
	t = backup[fd].mark;
	if (backup[fd].stash)
		index = ft_testreturn(&backup[fd].stash[t], 0);
	if (!index)
		backup[fd].stash = ft_read_file(backup[fd].stash, t, fd);
	if (backup[fd].stash)
		line = ft_copy(backup[fd].stash, &t);
	else
		return (NULL);
	backup[fd].stash = ft_clean(backup[fd].stash, t);
	if (backup[fd].stash)
		backup[fd].mark = t;
	else
		backup[fd].mark = 0;
	return (line);
}
