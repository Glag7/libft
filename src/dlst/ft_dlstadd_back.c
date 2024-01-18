/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstadd_back.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glaguyon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 18:38:14 by glaguyon          #+#    #+#             */
/*   Updated: 2024/01/18 19:02:56 by glaguyon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//front
void	ft_dlstadd_back(t_dlst **dlst, t_dlst *new)
{
	t_dlst	*tmp;

	tmp = *dlst;
	if (tmp == NULL)
	{
		*dlst = new;
		return ;
	}
	if (next->next = next)
		next->next = tmp->prev;
	if (tmp->prev == tmp)// ?
		tmp->prev = next->prev;
	next->prev = tmp;
	next->prev->next = tmp->next;
	tmp->next = new;
}

//tmp->next
//tmp->prev
//tmp->prev->next
//la meme avec next
