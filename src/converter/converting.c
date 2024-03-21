/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarolle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 14:17:12 by bcarolle          #+#    #+#             */
/*   Updated: 2024/03/21 14:56:30 by bcarolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void    write_decimal(t_data **data, char **s, long long number)
{
    
}

void    converter(t_data **data, char **s, va_list args)
{
    *data = (*data)->next;
    if ((*data)->type == DECIMAL)
    {
        if ((*data)->length_type == LENGTH_NONE)
            write_decimal(data, s, va_arg(args, int));
        if ((*data)->length_type == H)
            write_decimal(data, s, (short)va_arg(args, int));
        if ((*data)->length_type == HH)
            write_decimal(data, s, (char)va_arg(args, int));
        if ((*data)->length_type == L)
            write_decimal(data, s, va_arg(args, long));
        if ((*data)->length_type == LL)
            write_decimal(data, s, va_arg(args, long long));
        if ((*data)->length_type == J)
            write_decimal(data, s, va_arg(args, intmax_t));
        if ((*data)->length_type == Z)
            write_decimal(data, s, va_arg(args, size_t));
        if ((*data)->length_type == T)
            write_decimal(data, s, va_arg(args, ptrdiff_t));
    }
}