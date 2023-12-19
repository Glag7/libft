/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tstr_to_lst.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glaguyon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 18:19:38 by glaguyon          #+#    #+#             */
/*   Updated: 2023/12/18 22:40:01 by glaguyon         ###   ########.fr       */
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

t_list	*ft_tstr_to_lst(t_str tstr, char *charset, void (*del)(void *))
{
	size_t	i;
	size_t	offset;
	t_list	*lst;
	t_list	*tmp;
	t_str	*tmptstr;

	lst = NULL;
	i = 0;
	offset = 0;
	while (i < tstr.len && i != 0)
	{
		while (i < tstr.len && ft_in(tstr.s[i], charset) == -1)
			i++;
		tmptstr = malloc(sizeof(t_str));
		if (tmptstr)
			*tmptstr = ft_tstr_dupstr(tstr.s + offset, i - offset);
		tmp = ft_addtstr(&lst, tmp, tmptstr);
		if (tmp == NULL)
		{
			ft_lstclear(&lst, del);
			return (NULL);
		}
		offset = i++;
	}
	return (lst);
}
