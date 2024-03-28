/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decimal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarolle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 16:02:42 by bcarolle          #+#    #+#             */
/*   Updated: 2024/03/28 01:58:57 by bcarolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*write_decimal(t_data **data, intmax_t number)
{
	char	*result;
	char	*base;

	base = ft_strdup("0123456789");
	result = ft_itoa(number, 10, base);
	if ((*data)->flag_type == PLUS && number >= 0)
		result = ft_strjoin_free("+", result, 2);
	if ((*data)->flag_type == SPACE && number >= 0)
		result = ft_strjoin_free(" ", result, 2);
	if ((*data)->precision.type == INTEGERS)
		result = precision_int(data, result);
	if ((*data)->flag_type == ZERO && (*data)->precision.type != INTEGERS)
		result = zero_flag(data, result);
	free(base);
	return (result);
}

char	*get_decimal(t_data **data, char **s, va_list args)
{
	(void)s;
	if ((*data)->length_type == LENGTH_NONE)
		return (write_decimal(data, (int)va_arg(args, int)));
	if ((*data)->length_type == H)
		return (write_decimal(data, (short)va_arg(args, int)));
	if ((*data)->length_type == HH)
		return (write_decimal(data, (char)va_arg(args, int)));
	if ((*data)->length_type == L)
		return (write_decimal(data, (long)va_arg(args, long)));
	if ((*data)->length_type == LL)
		return (write_decimal(data, (long long)va_arg(args, long long)));
	if ((*data)->length_type == J)
		return (write_decimal(data, va_arg(args, intmax_t)));
	if ((*data)->length_type == Z)
		return (write_decimal(data, va_arg(args, size_t)));
	if ((*data)->length_type == T)
		return (write_decimal(data, va_arg(args, ptrdiff_t)));
	if ((*data)->length_type == BIG_L)
		write(2, "Error: Unsupported length type\n", 31);
	return (NULL);
}
