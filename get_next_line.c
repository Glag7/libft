/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glaguyon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 16:34:26 by glaguyon          #+#    #+#             */
/*   Updated: 2023/12/17 14:20:30 by glaguyon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_gnl(int fd, size_t bsize)
{
	static t_list	*readed[1024] = {NULL};
	t_list			*tmp;
	char			*line;
	size_t			len;

	if (fd < 0)
	{
		ft_freegnl(readed, fd);
		return (NULL);
	}
	len = 0;
	tmp = readed[fd];
	while (tmp)
	{
		len += ((t_str *)tmp->content)->len;
		if (tmp->next == NULL || ft_iseol((t_str *)(tmp->content)))
			break ;
		tmp = tmp->next;
	}
	if (!tmp || !ft_iseol((t_str *)(tmp->content)))
		get_next_line_file(readed, &tmp, &len, bsize);
	line = ft_lsttstr_to_str(readed[fd], len, &ft_tstrfree, &ft_iseol);
	if (line == NULL)
		ft_free1024(readed);
	return (line);
}

static char	*get_next_line_file(t_list **readed, t_list **lst, size_t len,
	size_t bsize)
{
	size_t	len;
	ssize_t	read_size;
	t_str	line;
	t_list	*tmp;

	line.s = malloc(bsize * sizeof(char));
	if (line.s == NULL)
		return (line);
	read_size = read(fd, line.s, bsize);
	if (read_size > 0)
	{
		//incrementer len
		tmp = ft_tstr_to_lst(line, "\n", &ft_tstrfree);
		if (tmp == NULL)
		{
			ft_free1024(readed);
			free(line.s);
			return (NULL);
		}
		ft_lstadd_back(lst, tmp);
		*lst = tmp;//blunder puissance max int
		if (ft_iseol(tmp->content))
		{
			line = ft_lsttstr_to_str(readed[fd], len, &ft_tstrfree, &ft_iseol);//problemo
			if (line == NULL)
			{
				ft_free1024(readed);
				return (NULL);
			}
		}
	}


//break si eol

	while (read_size > 0)
	{
		len += BUFFER_SIZE;
		free(line);
		line = malloc(BUFFER_SIZE * sizeof(char));
		if (line == NULL)
			return (ft_free1024(readed));
		read_size = read(fd, line, BUFFER_SIZE);
		line_len = ft_str_to_lst(readed, &tmp, line, read_size);
		if (tmp == NULL || ((t_str *)tmp->content)->s[((t_str *)tmp->content)->len - 1]
		!= '\n')
			break ;//sus
	}
	if (read_size < 0)
		ft_lstclear(readed + fd, &ft_tstrfree);
	readed[fd] = tmp;//blunder
			 //where protection malloc 
	return (ft_lst_to_str(readed, len, fd));
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

static char	*ft_freegnl(t_list **readed, int fd)
{
	if (fd < -1024)
		ft_free1024(readed);
	else
		ft_lstclear(readed - fd - 1, &ft_tstrfree);
	return (NULL);
}
