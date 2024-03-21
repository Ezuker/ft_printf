/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decimal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarolle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 16:02:42 by bcarolle          #+#    #+#             */
/*   Updated: 2024/03/21 16:35:56 by bcarolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char    *write_decimal(intmax_t number)
{
    char    *result;
    char    *base;

    base = ft_strdup("0123456789");
    result = ft_itoa(number, 10, base);
    free(base);
    return (result);
}

char    *get_decimal(t_data **data, char **s,va_list args)
{
    (void)s;
    if ((*data)->length_type == LENGTH_NONE)
        return (write_decimal((int)va_arg(args, int)));
    if ((*data)->length_type == H)
        return (write_decimal((short)va_arg(args, int)));
    if ((*data)->length_type == HH)
        return (write_decimal((char)va_arg(args, int)));
    if ((*data)->length_type == L)
        return (write_decimal((long)va_arg(args, long)));
    if ((*data)->length_type == LL)
        return (write_decimal( (long long)va_arg(args, long long)));
    if ((*data)->length_type == J)
        return (write_decimal(va_arg(args, intmax_t)));
    if ((*data)->length_type == Z)
        return (write_decimal(va_arg(args, size_t)));
    if ((*data)->length_type == T)
        return (write_decimal(va_arg(args, ptrdiff_t)));
    if ((*data)->length_type == BIG_L)
        write(2, "Error: Unsupported length type\n", 31);
    return (NULL);
}