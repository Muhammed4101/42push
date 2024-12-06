/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muharsla <muharsla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 12:20:26 by muharsla          #+#    #+#             */
/*   Updated: 2024/12/02 13:43:24 by muharsla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

int	ft_printf(const char *a, ...);
int	ft_putchar(char c);
int	ft_putnbr(long int c);
int	ft_putstr(char *s);
int	ft_hdecimal(unsigned long int n, int p);
int	ft_adress(unsigned long int c);

#endif