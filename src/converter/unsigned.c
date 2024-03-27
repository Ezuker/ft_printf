/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsigned.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarolle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 16:14:20 by bcarolle          #+#    #+#             */
/*   Updated: 2024/03/27 20:20:05 by bcarolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char    *write_unsigned(t_data **data, intmax_t number)
{
    char    *result;
    char    *base;

    base = ft_strdup("0123456789");
    result = ft_itoa(number, 10, base);
    if ((*data)->flag_type == SPACE)
        result = ft_strjoin_free(" ", result, 2);
    free(base);
    if ((*data)->precision.type == INTEGERS)
        return (precision_int(data, result));
    return (result);
}

char    *get_unsigned(t_data **data, char **s,va_list args)
{
    (void)s;

    if ((*data)->length_type == LENGTH_NONE)
        return (write_unsigned(data, (unsigned int)va_arg(args, unsigned int)));
    if ((*data)->length_type == H)
        return (write_unsigned(data, (unsigned short)va_arg(args, unsigned int)));
    if ((*data)->length_type == HH)
        return (write_unsigned(data, (unsigned char)va_arg(args, unsigned int)));
    if ((*data)->length_type == L)
        return (write_unsigned(data, (unsigned long)va_arg(args, unsigned long)));
    if ((*data)->length_type == LL)
        return (write_unsigned(data, (unsigned long long)va_arg(args, unsigned long long)));
    if ((*data)->length_type == J)
        return (write_unsigned(data, va_arg(args, uintmax_t)));
    if ((*data)->length_type == Z)
        return (write_unsigned(data, va_arg(args, size_t)));
    if ((*data)->length_type == T)
        return (write_unsigned(data, va_arg(args, ptrdiff_t)));
    if ((*data)->length_type == BIG_L)
        write(2, "Error: Unsupported length type\n", 31);
    return (NULL);
}