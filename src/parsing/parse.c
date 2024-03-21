/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarolle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 23:12:44 by bcarolle          #+#    #+#             */
/*   Updated: 2024/03/21 15:15:02 by bcarolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void    add_data(t_data *data, char **cursor)
{
    t_data  *new_data;

    new_data = malloc(sizeof(t_data));
    data->next = new_data;
    new_data->next = NULL;
    new_data->flag_type = get_flags(cursor);
    new_data->width = get_width(cursor);
    if (**cursor == '.')
    {
        (*cursor)++;
        new_data->precision.value = get_width(cursor);
        new_data->precision.type = STR;
    }
    else
        new_data->precision.type = PRECISION_NONE;
    new_data->length_type = get_length(cursor);
    new_data->type = get_type(cursor);
    if (new_data->precision.type == STR)
        new_data->precision.type = get_precision_type(new_data->type);
}

void    parse(t_data *data, char *string)
{
    char    **cursor;

    cursor = &string;
    while (**cursor)
    {
        if (**cursor == '%')
        {
            (*cursor)++;
            add_data(data, cursor); //cursor gonna increment though the parsing adddata
        }
        if (!**cursor)
            break ;
        (*cursor)++;
    }
}
