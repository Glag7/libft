/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glaguyon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 16:34:26 by glaguyon          #+#    #+#             */
/*   Updated: 2023/11/18 21:30:16 by glaguyon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*src_c;
	char	*dest_c;
	size_t	*src_long;
	size_t	*dest_long;
	size_t	i;

	i = 0;
	src_c = (char *) src;
	dest_c = (char *) dest;
	src_long = (size_t *) src;
	dest_long = (size_t *) dest;
	while (i < n / sizeof(size_t))
	{
		dest_long[i] = src_long[i];
		i++;
	}
	i *= sizeof(size_t);
	while (i < n)
	{
		dest_c[i] = src_c[i];
		i++;
	}
	return (dest);
}

void	ft_freeline(t_list **lst)
{
	t_list	*node;
	t_list	*next;

	node = *lst;
	free(((t_line *)node->content)->s);
	free(node->content);
	next = node->next;
	free(node);
	*lst = next;
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

char	*get_next_line(int fd)
{
	static t_list	*readed[1024] = {NULL};
	t_list			*tmp;
	char			*line;
	ssize_t			len;

	if (!(fd >= 0 && fd <= 1023) || BUFFER_SIZE < 1)
		return (NULL);
	len = 0;
	tmp = readed[fd];
	while (tmp && ((t_line *)tmp->content)->isend == 0)
	{
		len += ((t_line *)tmp->content)->len;
		tmp = tmp->next;
	}
	if (tmp != NULL)
	{
		len += ((t_line *)tmp->content)->len;
		line = ft_lst_to_str(readed, len, fd);
		return (line);
	}
	line = get_next_line_file(readed, fd, len, readed[fd]);
	return (line);
}

char	*get_next_line_file(t_list **readed, int fd, ssize_t len, t_list *tmp)
{
	ssize_t		line_len;
	ssize_t		read_size;
	char		*line;

	line = malloc(BUFFER_SIZE * sizeof(char));
	if (line == NULL)
		return (ft_free1024(readed));
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
