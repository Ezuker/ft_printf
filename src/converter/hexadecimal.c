/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexadecimal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarolle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 16:16:39 by bcarolle          #+#    #+#             */
/*   Updated: 2024/03/27 20:27:01 by bcarolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char    *write_hexa(t_data **data,intmax_t number)
{
    char    *result;
    char    *base;

    if ((*data)->type == HEXADECIMAL_CAPITAL)
        base = ft_strdup("0123456789ABCDEF");
    else
        base = ft_strdup("0123456789abcdef");
    if ((*data)->flag_type == HASHTAG 
        && (*data)->type == HEXADECIMAL && number != 0)
        result = ft_strdup("0x");
    else if ((*data)->flag_type == HASHTAG 
        && (*data)->type == HEXADECIMAL_CAPITAL && number != 0)
        result = ft_strdup("0X");
    else
        result = ft_strdup("");
    result = ft_strjoin_free(result, ft_itoa(number, 16, base), 3);
    if ((*data)->flag_type == SPACE)
        result = ft_strjoin_free(" ", result, 2);
    free(base);
    if ((*data)->precision.type == INTEGERS)
        return (precision_int(data, result));
    return (result);
}

char    *get_hexa(t_data **data, char **s, va_list args)
{
    (void)s;

    if ((*data)->length_type == LENGTH_NONE)
        return (write_hexa(data, (unsigned int)va_arg(args, unsigned int)));
    if ((*data)->length_type == H)
        return (write_hexa(data, (unsigned short)va_arg(args, unsigned int)));
    if ((*data)->length_type == HH)
        return (write_hexa(data, (unsigned char)va_arg(args, unsigned int)));
    if ((*data)->length_type == L)
        return (write_hexa(data, (unsigned long)va_arg(args, unsigned long)));
    if ((*data)->length_type == LL)
        return (write_hexa(data, (unsigned long long)va_arg(args, unsigned long long)));
    if ((*data)->length_type == J)
        return (write_hexa(data, va_arg(args, uintmax_t)));
    if ((*data)->length_type == Z)
        return (write_hexa(data, va_arg(args, size_t)));
    if ((*data)->length_type == T)
        return (write_hexa(data, va_arg(args, ptrdiff_t)));
    if ((*data)->length_type == BIG_L)
        write(2, "Error: Unsupported length type\n", 31);
    return (NULL);
}