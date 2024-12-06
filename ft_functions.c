/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_functions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muharsla <muharsla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 18:57:01 by muharsla          #+#    #+#             */
/*   Updated: 2024/12/02 14:25:11 by muharsla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_putnbr(long int c)
{
	int		len;
	int		ret;

	len = 0;
	ret = 0;
	if (c < 0)
	{
		if (ft_putchar('-') == -1)
			return (-1);
		c *= -1;
		len++;
	}
	if (c > 9)
	{
		ret = ft_putnbr(c / 10);
		if (ret == -1)
			return (-1);
		len += ret;
	}
	if (ft_putchar((c % 10) + '0') == -1)
		return (-1);
	return (len + 1);
}

int	ft_putstr(char *s)
{
	int		i;

	i = 0;
	if (s == NULL)
		return (ft_putstr("(null)"));
	while (s[i])
	{
		if (ft_putchar(s[i]) == -1)
			return (-1);
		i++;
	}
	return (i);
}

int	ft_hdecimal(unsigned long int n, int p)
{
	char	*y;
	int		ret;
	int		len;

	len = 0;
	ret = 0;
	y = "0123456789abcdef";
	if (p == 1)
		y = "0123456789ABCDEF";
	if (n >= 16)
	{
		ret = ft_hdecimal((n / 16), p);
		if (ret == -1)
			return (-1);
		len += ret;
	}
	if (ft_putchar(y[(n % 16)]) == -1)
		return (-1);
	len++;
	return (len);
}

int	ft_adress(unsigned long int c)
{
	int		len;
	int		ret;

	len = 0;
	ret = 0;
	if (c == 0)
		return (ft_putstr("(nil)"));
	ret = ft_putstr("0x");
	if (ret == -1)
		return (-1);
	len += ret;
	ret = ft_hdecimal(c, 0);
	if (ret == -1)
		return (-1);
	len += ret;
	return (len);
}
