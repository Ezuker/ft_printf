/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarolle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 22:02:33 by bcarolle          #+#    #+#             */
/*   Updated: 2024/03/29 01:12:06 by bcarolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	write_hexa(int modulo, int fd)
{
	char	c;
	char	*hexa;

	hexa = ft_strdup("0123456789abcdef");
	c = hexa[modulo];
	free(hexa);
	write(fd, &c, 1);
}

static int	nb_carac(unsigned long long nb)
{
	size_t	i;

	i = 1;
	while (nb >= 16)
	{
		nb /= 16;
		i++;
	}
	return (i);
}

static int	print_hexa(unsigned long long n)
{
	int	modulo;
	int	total;

	total = nb_carac(n);
	if (n >= 16)
	{
		modulo = n % 16;
		print_hexa(n / 16);
		write_hexa(modulo, 1);
	}
	else
		write_hexa(n, 1);
	return (total);
}

int	ft_putpointer(void	*ptr)
{
	size_t				i;
	unsigned long long	char_ptr;

	i = 0;
	char_ptr = (unsigned long long)ptr;
	if (char_ptr == 0)
	{
		write(1, "(nil)", 5);
		i += 5;
		return (i);
	}
	write(1, "0x", 2);
	i += 2;
	i += print_hexa(char_ptr);
	return (i);
}
