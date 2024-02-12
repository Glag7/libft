/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glaguyon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 00:05:06 by glaguyon          #+#    #+#             */
/*   Updated: 2023/11/06 01:21:54 by glaguyon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*ft_lstmap_nonull(t_list *lst, void *(*f)(void *),
	void (*del)(void *))
{
	t_list	*newlst;
	t_list	*newnode;
	t_list	*next;

	next = lst->next;
	if (next != NULL)
	{
		newlst = ft_lstmap_nonull(next, f, del);
		if (newlst == NULL)
			return (NULL);
		newnode = ft_lstnew(f(lst->content));
		if (newnode == NULL)
		{
			ft_lstclear(&newlst, del);
			return (NULL);
		}
		ft_lstadd_front(&newlst, newnode);
	}
	else
	{
		newlst = ft_lstnew(f(lst->content));
		if (newlst == NULL)
			return (NULL);
	}
	return (newlst);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlst;

	if (f == NULL || del == NULL || lst == NULL)
		return (NULL);
	newlst = ft_lstmap_nonull(lst, f, del);
	return (newlst);
}
