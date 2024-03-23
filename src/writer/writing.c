/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   writing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarolle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 21:07:35 by bcarolle          #+#    #+#             */
/*   Updated: 2024/03/23 21:25:07 by bcarolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int write_multiplebyte_character(t_data *data)
{
    char    mbstr[(2 * ft_wstrlen(data->w_string)) + 1];
    size_t  len;

    write(1, data->w_string, ft_wstrlen(data->w_string));
    len = ft_wcstombs(mbstr, data->w_string, sizeof(mbstr));
    if (len != (size_t)-1)
    {
        write(1, mbstr, len);
    }
    return (len);
}

int writer(t_data *data)
{
    size_t  len;

    len = 0;
    if (data->w_string)
        len = write_multiplebyte_character(data);
    else
    {
        if (data->flag_type == PLUS && data->string[0] != '-')
        {
            write(1, "+", 1);
            len++;
        }
        write(1, data->string, ft_strlen(data->string));
        len += ft_strlen(data->string);
    }
    return (len);
}