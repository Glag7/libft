/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sortint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glaguyon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 18:09:28 by glaguyon          #+#    #+#             */
/*   Updated: 2023/11/23 18:43:24 by glaguyon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_sort(int *arr, size_t len)
{
	int		pivot;
	int		bignum;
	int		*bigger;
	size_t	i;

	bigger = NULL;
	pivot = arr[len / 2];
	while (i < len)
	{
		if (arr[i] > pivot)
		{
			bigger = arr + i;
			bignum = *bigger;//opti
		}
		else if (arr[i] != pivot && bigger)
			ft_swapint(bigger, arr + i);
		i++;
	}
}

void	ft_sortint(int *arr, short un, short rev, size_t len)
{
	/*if (rev)
		ft_sortrev();
	else*/
		ft_sort(arr, len);
clang arr/ft_sortint.c arr/ft_swapint.c main.c -I ../hdr/}
