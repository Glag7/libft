/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glaguyon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 14:45:51 by glaguyon          #+#    #+#             */
/*   Updated: 2023/11/05 20:33:46 by glaguyon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*strdup;
	size_t	i;
	size_t	len;

	if (f == NULL || s == NULL)
		return (NULL);
	len = ft_strlen(s);
	strdup = ft_calloc((len + 1), sizeof(char));
	if (strdup == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		strdup[i] = f(i, s[i]);
		i++;
	}
	return (strdup);
}
