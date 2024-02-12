/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glaguyon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 13:32:13 by glaguyon          #+#    #+#             */
/*   Updated: 2023/11/02 12:39:51 by glaguyon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	char	*ptr;
	size_t	*ptr_long;
	size_t	i;

	i = 0;
	ptr = (char *) s;
	ptr_long = (size_t *) s;
	while (i < n / sizeof(size_t))
	{
		ptr_long[i] = 0;
		i++;
	}
	i *= sizeof(size_t);
	while (i < n)
	{
		ptr[i] = 0;
		i++;
	}
}
