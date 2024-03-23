/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarolle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 23:12:44 by bcarolle          #+#    #+#             */
/*   Updated: 2024/03/23 22:42:36 by bcarolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void    add_data(t_data *data, char **cursor, va_list args)
{
    data->flag_type = get_flags(cursor);
    data->width = get_width(cursor, args);
    if (**cursor == '.')
    {
        (*cursor)++;
        data->precision.value = get_width(cursor, args);
        data->precision.type = STR;
    }
    else
        data->precision.type = PRECISION_NONE;
    data->length_type = get_length(cursor);
    data->type = get_type(cursor);
    if (data->precision.type == STR)
        data->precision.type = get_precision_type(data->type);
}

void    parse(t_data *data, char **string, va_list args)
{
    char    **cursor;

    cursor = string;
    while (**cursor)
    {
        if (**cursor == '%')
        {
            (*cursor)++;
            add_data(data, cursor, args); //cursor gonna increment though the parsing adddata
            string = cursor;
            break ;
        }
        if (!**cursor)
            break ;
        (*cursor)++;
    }
}
