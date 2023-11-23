/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glaguyon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 18:34:26 by glaguyon          #+#    #+#             */
/*   Updated: 2023/11/23 18:39:50 by glaguyon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_sort(int *arr, size_t len);

int	main(void)
{
	int	tab[] = {1, 8, 7, 4, 6, 5, 2, 4, 2};

	for (int i = 0; i < 9; i++)
		printf("[%d],", tab[i]);
	ft_sort(tab, 9);
	printf("\nsortded :\n");
	for (int i = 0; i < 9; i++)
		printf("[%d],", tab[i]);
}
