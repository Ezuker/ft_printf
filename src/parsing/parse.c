/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarolle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 23:12:44 by bcarolle          #+#    #+#             */
/*   Updated: 2024/03/20 23:17:27 by bcarolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void    add_data(t_data *data, char *cursor)
{
    t_data  *new_data;

    new_data = malloc(sizeof(t_data));
    data->next = new_data;
}

void    parse(t_data *data, char *string)
{
    char    *cursor;

    cursor = string;
    while (*cursor)
    {
        if (*cursor == '%')
            add_data(data, cursor); //cursor gonna increment though the parsing adddata
        
        cursor++;
    }
}
