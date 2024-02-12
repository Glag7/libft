/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glaguyon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 14:31:30 by glaguyon          #+#    #+#             */
/*   Updated: 2023/10/31 18:07:19 by glaguyon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	ft_atoi_unsigned(const char *nptr)
{
	char			c;
	unsigned int	num;

	num = 0;
	c = *nptr;
	while (c >= '0' && c <= '9')
	{
		num = num * 10 + c - '0';
		nptr++;
		c = *nptr;
	}
	return (num);
}

int	ft_atoi(const char *nptr)
{
	unsigned int	num;
	int				neg;
	char			c;

	c = *nptr;
	neg = 0;
	while (c == ' ' || (c >= 9 && c <= 13))
	{
		nptr++;
		c = *nptr;
	}
	if (c == '+')
		nptr++;
	else if (c == '-')
	{
		neg = 1;
		nptr++;
	}
	num = ft_atoi_unsigned(nptr);
	if (neg)
		return (-num);
	return (num);
}
