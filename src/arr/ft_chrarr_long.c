/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chrarr_long.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glaguyon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 11:19:57 by glaguyon          #+#    #+#             */
/*   Updated: 2023/12/21 11:29:25 by glaguyon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

ssize_t	ft_chrarr_long(ssize_t *arr, ssize_t tofind, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		if (arr[i] == tofind)
			return (i);
		i++;
	}
	return (-1);
}
