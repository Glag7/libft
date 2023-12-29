/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrti.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glaguyon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 16:57:48 by glaguyon          #+#    #+#             */
/*   Updated: 2023/12/29 18:45:51 by glaguyon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_sqrti(size_t n)
{
	size_t	up;
	size_t	down;
	size_t	mid;

	if (n < 16)
	{
		if (n < 4)
			return (!!n);
		if (n < 9)
			return (2);
		return (3);
	}
	up = n / 4;
	down = 4;
	mid = (up + down) / 2;
	while (up > down)
	{
		if (n / (mid + 1) > mid)
			down = mid;
		else if (n / mid < mid)
			up = mid;
		else
			break;
		mid = (up + down) / 2;
	}
	return (mid);
}
