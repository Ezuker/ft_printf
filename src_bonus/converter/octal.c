/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   octal.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarolle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 16:11:50 by bcarolle          #+#    #+#             */
/*   Updated: 2024/03/29 02:30:57 by bcarolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static char	*write_octal(t_data **data, intmax_t number)
{
	char	*result;
	char	*base;

	base = ft_strdup("01234567");
	if ((*data)->flag_type == HASHTAG && number != 0)
		result = ft_strdup("0");
	else
		result = ft_strdup("");
	result = ft_itoa(number, 8, base);
	free(base);
	return (result);
}

char	*get_octal(t_data **data, va_list args)
{
	if ((*data)->length_type == LENGTH_NONE)
		return (write_octal(data, (unsigned int)va_arg(args, unsigned int)));
	if ((*data)->length_type == H)
		return (write_octal(data, (unsigned short)va_arg(args, unsigned int)));
	if ((*data)->length_type == HH)
		return (write_octal(data, (unsigned char)va_arg(args, unsigned int)));
	if ((*data)->length_type == L)
		return (write_octal(data, (unsigned long)va_arg(args, unsigned long)));
	if ((*data)->length_type == LL)
		return (write_octal(data,
				(unsigned long long)va_arg(args, unsigned long long)));
	if ((*data)->length_type == J)
		return (write_octal(data, va_arg(args, uintmax_t)));
	if ((*data)->length_type == Z)
		return (write_octal(data, va_arg(args, size_t)));
	if ((*data)->length_type == T)
		return (write_octal(data, va_arg(args, ptrdiff_t)));
	if ((*data)->length_type == BIG_L)
		write(2, "Error: Unsupported length type\n", 31);
	return (NULL);
}
