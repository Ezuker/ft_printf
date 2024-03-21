/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsigned.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarolle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 16:14:20 by bcarolle          #+#    #+#             */
/*   Updated: 2024/03/21 16:36:10 by bcarolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char    *write_unsigned(intmax_t number)
{
    char    *result;
    char    *base;

    base = ft_strdup("0123456789");
    result = ft_itoa(number, 10, base);
    free(base);
    return (result);
}

char    *get_unsigned(t_data **data, char **s,va_list args)
{
    (void)s;

    if ((*data)->length_type == LENGTH_NONE)
        return (write_unsigned((unsigned int)va_arg(args, unsigned int)));
    if ((*data)->length_type == H)
        return (write_unsigned((unsigned short)va_arg(args, unsigned int)));
    if ((*data)->length_type == HH)
        return (write_unsigned((unsigned char)va_arg(args, unsigned int)));
    if ((*data)->length_type == L)
        return (write_unsigned((unsigned long)va_arg(args, unsigned long)));
    if ((*data)->length_type == LL)
        return (write_unsigned((unsigned long long)va_arg(args, unsigned long long)));
    if ((*data)->length_type == J)
        return (write_unsigned(va_arg(args, uintmax_t)));
    if ((*data)->length_type == Z)
        return (write_unsigned(va_arg(args, size_t)));
    if ((*data)->length_type == T)
        return (write_unsigned(va_arg(args, ptrdiff_t)));
    if ((*data)->length_type == BIG_L)
        write(2, "Error: Unsupported length type\n", 31);
    return (NULL);
}