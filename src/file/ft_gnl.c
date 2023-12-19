/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gnl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glaguyon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 16:34:26 by glaguyon          #+#    #+#             */
/*   Updated: 2023/12/19 17:59:49 by glaguyon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
# define BUFFER_SIZE 1024 		//non
char	*ft_gnl(int fd, size_t bsize);	//non

//non
char	*get_next_line(int fd)
{
	if (fd >= 0 && fd < 1024 && BUFFER_SIZE >= 0)
		return (ft_gnl(fd, BUFFER_SIZE));
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

static char	*ft_freegnl(t_list **readed, int fd)
{
	if (fd < -1024)
		ft_free1024(readed);
	else
		ft_lstclear(readed - fd - 1, &ft_tstrfree);
	return (NULL);
}

static size_t	ft_gnl_file(t_list **readed, t_list **lst, int fd,
	size_t bsize)
{
	size_t	len;
	ssize_t	read_size;
	t_str	line;
	t_list	*tmp;
	t_list	*end;

	len = 0;
	end = *lst;
	line.s = malloc(bsize * sizeof(char));
	if (line.s)
		read_size = read(fd, line.s, bsize);
	while (line.s && read_size > 0)
	{
		line.len = read_size;
		len += read_size;
		tmp = ft_tstr_to_lst(line, "\n", &ft_tstrfree);
		if (tmp == NULL)
		{
			free(line.s);
			line.s = 0;
			break ;
		}
		ft_lstadd_back(&end, tmp);
		if (*lst == NULL)
			*lst = tmp;
		end = tmp;
		if (ft_iseol(tmp->content))
		{
			len = len - read_size + ((t_str *)tmp->content)->len;
			break ;
		}
		free(line.s);
		line.s = malloc(bsize * sizeof(char));
		if (line.s)
			read_size = read(fd, line.s, bsize);
	}
	if (line.s == NULL)
	{
		ft_free1024(readed);
		return ((size_t)1 << 63);
	}
	free(line.s);
	return (len);
}

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
		len += ft_gnl_file(readed, &tmp, fd, bsize);
	line = ft_lsttstr_to_str(readed + fd, len, &ft_tstrfree, &ft_iseol);
	if (line == NULL)
		ft_free1024(readed);
	if (!*line)		//pour testeur
	{			//pour testeur
		free(line);	//pour testeur
		return (NULL);	//pour testeur
	}			//pour testeur
	return (line);
}
