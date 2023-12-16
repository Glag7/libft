/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glaguyon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 16:34:26 by glaguyon          #+#    #+#             */
/*   Updated: 2023/12/16 18:18:40 by glaguyon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_gnl(int fd)
{
	static t_list	*readed[1024] = {NULL};
	t_list			*tmp;
	char			*line;
	ssize_t			len;

	len = 0;
	tmp = readed[fd];
	while (tmp && ft_isend(tmp->content))
	{
		len += ((t_str *)tmp->content)->len;
		tmp = tmp->next;
	}
	if (tmp != NULL)
	{
		len += ((t_str *)tmp->content)->len;
		line = ft_lsttstr_to_str(readed[fd], len, &ft_tstrfree, &ft_isend);
		if (line == NULL)
			ft_free1024(readed);
		return (line);
	}
	line = get_next_line_file(readed, fd, len, readed[fd]);
	if (line == NULL)
		ft_free1024(readed);
	return (line);
}

char	*get_next_line_file(t_list **readed, int fd, ssize_t len, t_list *tmp)
{
	ssize_t		line_len;
	ssize_t		read_size;
	char		*line;

	line = malloc(BUFFER_SIZE * sizeof(char));
	if (line == NULL)
		return (line);
	read_size = read(fd, line, BUFFER_SIZE);
	line_len = ft_str_to_lst(readed, &tmp, line, read_size);
	while (read_size > 0 && line_len == -1)
	{
		len += BUFFER_SIZE;
		free(line);
		line = malloc(BUFFER_SIZE * sizeof(char));
		if (line == NULL)
			return (ft_free1024(readed));
		read_size = read(fd, line, BUFFER_SIZE);
		line_len = ft_str_to_lst(readed, &tmp, line, read_size);
	}
	len += line_len * (line_len > 0);
	free(line);
	if (read_size < 0)
		ft_lstclear(readed + fd);
	readed[fd] = tmp;
	return (ft_lst_to_str(readed, len, fd));
}

t_list	*ft_new_line(t_list *lst, char *line, ssize_t len, short isend)
{
	char	*new_line;
	t_list	*tmp;

	new_line = malloc((len) * sizeof(char));
	if (new_line == NULL)
		return (NULL);
	ft_memcpy(new_line, line, len);
	tmp = ft_lstadd_back(&lst, new_line, len, isend);
	if (tmp == NULL)
		free(new_line);
	return (tmp);
}

static short	ft_isend(t_str line)
{
	if (line.s[line.len - 1] == '\n')
		return (1);
	return (0);
}

static void	*ft_free1024(t_list **readed)
{
	int	i;

	i = 0;
	while (i < 1024)
	{
		ft_lstclear(readed + i, &ft_tstrfree);
		readed[i] = 0;
		i++;
	}
	return (NULL);
}
