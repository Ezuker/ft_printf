/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   writing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarolle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 21:07:35 by bcarolle          #+#    #+#             */
/*   Updated: 2024/03/27 19:18:28 by bcarolle         ###   ########.fr       */
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

static int zero_flag(t_data *data)
{
    size_t len;
    size_t  s_len;
    char    *str_cpy;

    len = 0;
    if (data->string && data->string[0] == '-')
    {
        write(1, "-", 1);
        len++;
        str_cpy = data->string;
        data->string = ft_substr(str_cpy, 1, ft_strlen(str_cpy) - 1);
        free(str_cpy);
    }
    s_len = ft_strlen(data->string) + data->len;
    if (data->width < (int)s_len)
        return (len);
    while (len < data->width - s_len)
    {
        write(1, "0", 1);
        len++;
    }
    return (len);
}

static int  minus_flag(t_data *data)
{
    size_t len;
    size_t  s_len;

    len = 0;
    s_len = ft_strlen(data->string) + data->len;
    if (data->width < (int)s_len)
        return (0);
    while (len < data->width - s_len)
    {
        write(1, " ", 1);
        len++;
    }
    return (len);
}

int no_flag_width(t_data *data)
{
    size_t len;
    size_t s_len;

    len = 0;
    s_len = ft_strlen(data->string) + data->len;
    if (data->width < (int)s_len)
        return (0);
    while (len < data->width - s_len)
    {
        write(1, " ", 1);
        len++;
    }
    return (len);
}

int no_flag_precision(t_data *data)
{
    size_t len;

    len = 0;
    if (data->precision.type == INTEGERS)
        len += zero_flag(data);
    return (len);
}
int no_flag(t_data *data)
{
    size_t len;
    // size_t s_len;

    len = 0;
    len += no_flag_width(data);
    // len += no_flag_precision(data);
    return (len);
}

static int space_flag(t_data *data)
{
    size_t len;

    len = 0;
    len += no_flag(data);
    return (len);
}

int hash_flag_float(t_data *data)
{
    int len;

    (void)data;
    len = 0;
    return (len);
}
int hashtag_flag(t_data *data)
{
    int len;

    len = 0;
    len += hash_flag_float(data);
    return (len);
}


size_t writer(t_data *data)
{
    size_t  len;

    len = 0;
    len += data->len;
    if (data->w_string)
        len = write_multiplebyte_character(data);
    else
    {
        if (data->flag_type == SPACE)
            len += space_flag(data);
        if (data->flag_type == ZERO)
            len += zero_flag(data);
        if (data->flag_type == FLAGS_NONE)
            len += no_flag(data);
        if (data->len == 1 && ft_strlen(data->string) == 0)
            write(1, "\0", 1);
        // else if (data->precision.type != PRECISION_NONE)
        //     len += precision_write(data);
        else 
        {
            write(1, data->string, ft_strlen(data->string));
            len += ft_strlen(data->string);
        }
        if (data->flag_type == MINUS)
            len += minus_flag(data);
    }
    return (len);
}