/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chrarr_ptr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glaguyon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 11:27:49 by glaguyon          #+#    #+#             */
/*   Updated: 2023/12/21 11:46:05 by glaguyon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

ssize_t	ft_chrarr_ptr(void **arr, void *tofind, size_t len,
		char (*cmp)(void *, void *))
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		if (cmp(arr[i], tofind) == 0)
			return (i);
		i++;
	}
	return (-1);
}
