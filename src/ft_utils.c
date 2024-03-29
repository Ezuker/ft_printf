/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarolle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 01:08:14 by bcarolle          #+#    #+#             */
/*   Updated: 2024/03/29 02:48:20 by bcarolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strdup(const char *s1)
{
	char	*str;
	size_t	i;

	i = 0;
	str = malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (!str)
		return (NULL);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

int	ft_putchar_fd(int c, int fd)
{
	write(fd, &c, 1);
	return (1);
}

int	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (!s)
	{
		write(fd, "(null)", 6);
		return (6);
	}
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
	return (i);
}

int	ft_putnbr_fd(int n, int fd)
{
	int	modulo;
	int	total;

	total = nb_charac(n, 10);
	if (n < 0)
	{
		write(fd, "-", 1);
		if (n == -2147483648)
		{
			write(fd, "2147483648", 10);
			return (11);
		}
		n = -n;
	}
	if (n > 9)
	{
		modulo = n % 10;
		ft_putnbr_fd(n / 10, fd);
		write_int(modulo, fd);
	}
	else
		write_int(n, fd);
	return (total);
}
