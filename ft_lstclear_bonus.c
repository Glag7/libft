/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glaguyon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 23:42:31 by glaguyon          #+#    #+#             */
/*   Updated: 2023/11/06 01:22:24 by glaguyon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_lstclear_nonull(t_list *lst, void (*del)(void*))
{
	if (lst != NULL)
	{
		ft_lstclear_nonull(lst->next, del);
		ft_lstdelone(lst, del);
	}
}

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	if (del == NULL || lst == NULL)
		return ;
	ft_lstclear_nonull(*lst, del);
	*lst = NULL;
}
