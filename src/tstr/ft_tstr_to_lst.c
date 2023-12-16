/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tstr_to_lst.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glaguyon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 18:19:38 by glaguyon          #+#    #+#             */
/*   Updated: 2023/12/16 20:06:56 by glaguyon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*ft_addtstr(t_list **lst, t_list *tmp, t_str *tstr)
{
	t_list	*node;

	node = malloc(sizeof(t_list));
	if (tstr->s == NULL || node == NULL)
	{
		free(tstr->s);
		free(node);
		return (NULL);
	}
	node->next = NULL;
	node->content = tstr;
	if (*lst == NULL)
		*lst = node;
	else
		tmp->next = node;
	return (node);
}

t_list	*ft_tstr_to_lst(t_str tstr, short (*sep)(char), void (*del)(void *))
{
	size_t	i;
	size_t	offset;
	t_list	*lst;
	t_list	*tmp;
	t_str	*tmptstr;

	lst = NULL;
	i = 0;
	offset = 0;
	while (i < tstr.len)
	{
		while (i < tstr.len && !sep(tstr.s[i]))
			i++;
		tmptstr = malloc(sizeof(t_str));
		if (tmptstr)
			*tmptstr = ft_tstr_dupstr(tstr.s + offset, i - offset + 1);
		tmp = ft_addtstr(&lst, tmp, tmptstr);
		if (tmp == NULL)
		{
			ft_lstclear(&lst, del);
			return (NULL);
		}
		i++;
		offset = i;
	}
	return (lst);
}
