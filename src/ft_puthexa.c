/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarolle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 15:42:30 by bcarolle          #+#    #+#             */
/*   Updated: 2024/03/29 02:43:14 by bcarolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarolle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 22:02:33 by bcarolle          #+#    #+#             */
/*   Updated: 2023/11/08 15:30:14 by bcarolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	write_hexa(int modulo, int xORX)
{
	char	c;
	char	*hexa;

	if (xORX == 0)
		hexa = ft_strdup("0123456789abcdef");
	else
		hexa = ft_strdup("0123456789ABCDEF");
	c = hexa[modulo];
	free(hexa);
	write(1, &c, 1);
}

int	nb_charac(long long int nb, int base)
{
	size_t	i;

	i = 1;
	if (nb < 0)
	{
		nb = -nb;
		i++;
	}
	while (nb >= base)
	{
		nb /= base;
		i++;
	}
	return (i);
}

int	ft_print_hexa(unsigned int n, int xORX)
{
	int	modulo;
	int	total;

	total = nb_charac(n, 16);
	if (n >= 16)
	{
		modulo = n % 16;
		ft_print_hexa(n / 16, xORX);
		write_hexa(modulo, xORX);
	}
	else
		write_hexa(n, xORX);
	return (total);
}
