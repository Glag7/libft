/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glaguyon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 18:25:24 by glaguyon          #+#    #+#             */
/*   Updated: 2023/11/18 21:28:06 by glaguyon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_lstclear(t_list **lst)
{
	t_list	*node;
	t_list	*next;

	node = *lst;
	while (node)
	{
		next = node->next;
		free(((t_line *)node->content)->s);
		free(node->content);
		free(node);
		node = next;
	}
	*lst = NULL;
}

void	*ft_free1024(t_list **readed)
{
	int	i;

	i = 0;
	while (i < 1024)
	{
		ft_lstclear(readed + i);
		readed[i] = 0;
		i++;
	}
	return (NULL);
}

char	*ft_lst_to_str(t_list **readed, ssize_t len, int fd)
{
	ssize_t	rmed;
	t_list	*node;
	char	*line;

	if (readed[fd] == NULL || len < 1)
		return (NULL);
	line = malloc((len + 1) * sizeof(char));
	if (line == NULL)
		return (ft_free1024(readed));
	node = readed[fd];
	rmed = 0;
	while (node->next && ((t_line *)node->content)->isend == 0)
	{
		ft_memcpy(line + rmed, ((t_line *)node->content)->s,
			((t_line *)node->content)->len);
		rmed += ((t_line *)node->content)->len;
		ft_freeline(&node);
	}
	ft_memcpy(line + rmed, ((t_line *)node->content)->s, len - rmed);
	line[len] = '\0';
	ft_freeline(&node);
	readed[fd] = node;
	return (line);
}

t_list	*ft_lstadd_back(t_list **lst, char *s, ssize_t len, short isend)
{
	t_list	*new;
	t_list	*last;

	new = malloc(sizeof(t_list));
	if (new != NULL)
		new->content = malloc(sizeof(t_line));
	if (new == NULL || new->content == NULL)
	{
		free(new);
		return (NULL);
	}
	((t_line *)new->content)->s = s;
	((t_line *)new->content)->len = len;
	((t_line *)new->content)->isend = isend;
	new->next = NULL;
	last = *lst;
	if (last != NULL)
	{
		while (last-> next != NULL)
			last = last->next;
		last->next = new;
	}
	else
		*lst = new;
	return (new);
}

size_t	ft_str_to_lst(t_list **readed, t_list **lst, char *line, ssize_t len)
{
	ssize_t	i;
	ssize_t	offset;
	ssize_t	lenfl;
	short	isend;
	t_list	*tmp;

	tmp = *lst;
	i = 0;
	offset = 0;
	lenfl = -1 * !(len < 0 || (tmp == NULL && len == 0));
	while (i < len)
	{
		while (i + 1 < len && line[i] != '\n')
			i++;
		isend = (len < BUFFER_SIZE || line[i] == '\n');
		tmp = ft_new_line(tmp, line + offset, i - offset + 1, isend);
		if (tmp == NULL)
			return ((ssize_t) ft_free1024(readed));
		if (!*lst)
			*lst = tmp;
		if (lenfl == -1 && isend)
			lenfl = i + 1;
		offset = i++ + 1;
	}
	return (lenfl);
}
