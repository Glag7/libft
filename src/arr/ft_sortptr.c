/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sortptr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glaguyon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 17:31:21 by glaguyon          #+#    #+#             */
/*   Updated: 2023/12/22 21:45:40 by glaguyon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_part(void **arr, size_t len, char (*cmp)(void *, void *))
{
	size_t	i;
	size_t	j;
	void	*mid;

	i = 0;
	j = len - 1;
	mid = arr[(len - 1) / 2];
	while (i <= j)
	{
		while (cmp(mid, arr[i]))
			i++;
		while (cmp(arr[j], mid))
			j--;
		if (i <= j)
		{
			ft_swapptr(arr + i, arr + j);
			i++;
			j--;
		}
	}
	return (j + 1);
}

static void	ft_sortptr_rec(void **arr, size_t len,
	char (*cmp)(void *, void*))
{
	size_t	tmp;

	if (len > 3)
	{
		tmp = ft_part(arr, len, cmp);
		ft_sortptr_rec(arr, tmp, cmp);
		ft_sortptr_rec(arr + tmp, len - tmp, cmp);
	}
	if (len == 3 && cmp(arr[0], arr[2]))
		ft_swapptr(arr, arr + 2);
	if (len == 3 && cmp(arr[1], arr[2]))
		ft_swapptr(arr + 1, arr + 2);
	if ((len == 2 || len == 3) && cmp(arr[0], arr[1]))
		ft_swapptr(arr, arr + 1);
}

static size_t	ft_part_i(void **arr, size_t len, char (*cmp)(void *, void *))
{
	size_t	i;
	size_t	j;
	void	*mid;

	i = 0;
	j = len - 1;
	mid = arr[(len - 1) / 2];
	while (i <= j)
	{
		while (!cmp(mid, arr[i]))
			i++;
		while (!cmp(arr[j], mid))
			j--;
		if (i <= j)
		{
			ft_swapptr(arr + i, arr + j);
			i++;
			j--;
		}
	}
	return (j + 1);
}

static void	ft_sortptr_rec_i(void **arr, size_t len,
	char (*cmp)(void *, void*))
{
	size_t	tmp;

	if (len > 3)
	{
		tmp = ft_part_i(arr, len, cmp);
		ft_sortptr_rec_i(arr, tmp, cmp);
		ft_sortptr_rec_i(arr + tmp, len - tmp, cmp);
	}
	if (len == 3 && !cmp(arr[0], arr[2]))
		ft_swapptr(arr, arr + 2);
	if (len == 3 && !cmp(arr[1], arr[2]))
		ft_swapptr(arr + 1, arr + 2);
	if ((len == 2 || len == 3) && !cmp(arr[0], arr[1]))
		ft_swapptr(arr, arr + 1);
}

void	ft_sortptr(void **arr, size_t len, char rev,
		char (*cmp)(void *, void *))
{
	if (rev)
		ft_sortptr_rec(arr, len, cmp);
	else
		ft_sortptr_rec_i(arr, len, cmp);
}
