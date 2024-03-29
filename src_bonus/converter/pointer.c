/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pointer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarolle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 14:33:59 by bcarolle          #+#    #+#             */
/*   Updated: 2024/03/29 01:26:14 by bcarolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static int	ft_intlen_pointer(unsigned long long n, int base)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n /= base;
		i++;
	}
	return (i);
}

char	*ft_itoa_pointer(unsigned long long n, int base, char *s)
{
	char	*str;
	int		len;

	len = ft_intlen_pointer(n, base);
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	while (len > 0)
	{
		len--;
		str[len] = s[n % base];
		n /= base;
	}
	return (str);
}

char	*get_pointer(va_list args)
{
	char	*result;
	void	*pointer;
	char	*base;

	pointer = va_arg(args, void *);
	if (!pointer)
		return (ft_strdup("(nil)"));
	base = ft_strdup("0123456789abcdef");
	if (!base)
		return (NULL);
	result = ft_itoa_pointer((unsigned long long)pointer, 16, base);
	result = ft_strjoin_free("0x", result, 2);
	free(base);
	return (result);
}
