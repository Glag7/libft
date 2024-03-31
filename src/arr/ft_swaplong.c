/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swaplong.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glaguyon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 17:01:59 by glaguyon          #+#    #+#             */
/*   Updated: 2023/12/28 16:37:01 by glaguyon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

inline void	ft_swaplong(ssize_t *a, ssize_t *b)
{
	ssize_t	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}