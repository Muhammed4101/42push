/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muharsla <muharsla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 12:35:48 by muharsla          #+#    #+#             */
/*   Updated: 2024/12/02 14:05:31 by muharsla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "ft_printf.h"

int	ft_checker(const char a, va_list args)
{
	int		ret;

	ret = 0;
	if ((a == 'd') || (a == 'i'))
		ret = (ft_putnbr(va_arg(args, int)));
	else if (a == 'u')
		ret = (ft_putnbr(va_arg(args, unsigned int)));
	else if (a == 'c')
		ret = (ft_putchar(va_arg(args, int)));
	else if (a == 's')
		ret = (ft_putstr(va_arg(args, char *)));
	else if (a == 'x')
		ret = (ft_hdecimal(va_arg(args, unsigned int), 0));
	else if (a == 'X')
		ret = (ft_hdecimal(va_arg(args, unsigned int), 1));
	else if (a == 'p')
		ret = (ft_adress(va_arg(args, unsigned long int)));
	else if (a == '%')
		ret = (ft_putchar('%'));
	return (ret);
}

int	ft_handle(const char *a, va_list args)
{
	int		i;
	int		len;
	int		ret;

	i = 0;
	len = 0;
	ret = 0;
	while (a[i])
	{
		if (a[i] == '%')
		{
			i++;
			ret = ft_checker(a[i++], args);
			if (ret == -1)
				return (-1);
			len += ret;
		}
		else if (a[i])
		{
			if (ft_putchar(a[i++]) == -1)
				return (-1);
			len++;
		}
	}
	return (len);
}

int	ft_printf(const char *a, ...)
{
	int		len;

	len = 0;
	if (!a)
		return (-1);
	va_list(args);
	va_start(args, a);
	len = ft_handle(a, args);
	va_end(args);
	return (len);
}
