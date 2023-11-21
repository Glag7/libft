/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glaguyon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 18:25:36 by glaguyon          #+#    #+#             */
/*   Updated: 2023/11/18 20:10:26 by glaguyon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

# include <unistd.h>
# include <stdlib.h>

typedef struct s_line
{
	ssize_t		len;
	char		*s;
	short		isend;
}	t_line;

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

void	ft_lstclear(t_list **lst);
void	*ft_free1024(t_list **readed);
char	*ft_lst_to_str(t_list **readed, ssize_t len, int fd);
t_list	*ft_lstadd_back(t_list **lst, char *s, ssize_t len, short isend);
size_t	ft_str_to_lst(t_list **readed, t_list **lst, char *line, ssize_t len);

void	*ft_memcpy(void *dest, const void *src, size_t n);
void	ft_freeline(t_list **lst);
t_list	*ft_new_line(t_list *lst, char *line, ssize_t len, short isend);
char	*get_next_line(int fd);
char	*get_next_line_file(t_list **readed, int fd, ssize_t len, t_list *tmp);

#endif
