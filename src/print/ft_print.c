/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glaguyon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 17:03:19 by glaguyon          #+#    #+#             */
/*   Updated: 2024/04/04 18:03:32 by glaguyon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "ft_print.h"

#include "libft.h"
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

#define BUFFSIZE 1024

static size_t	print_args(t_str buff, t_str s, va_list args, size_t maxlen)
{
	char	*next_spec;

	while (1)
	{
		next_spec = ft_memchr(s.s, '%', s.len);
		if
		buff = addspec(buff, parsespec(s));
	}
	return (buff);
}

size_t	ft_print(int fd, const char restrict *s_, ...)
{
	t_str	buff;
	t_str	s;
	va_list	args;

	buff = (t_str){malloc(BUFFSIZE), 0};
	if (buff.s == NULL)
		return (-1);
	s = (t_str){s_, ft_strlen(s_)};
	va_start(args, s);
	buff = print_args(buff, s, args, BUFFSIZE);
	va_end(args);
	if (buff.len != -1)
	{
		write(fd, buff.s, buff.len);
		free(buff.s);
	}
	return (buff.len);
}
