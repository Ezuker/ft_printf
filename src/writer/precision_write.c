/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precision_write.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarolle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 20:11:03 by bcarolle          #+#    #+#             */
/*   Updated: 2024/03/24 21:52:38 by bcarolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int precision_str(t_data *data)
{
    int len;
    char *str_cpy;

    len = 0;
    str_cpy = data->string;
    while (*str_cpy && data->precision.value > 0)
    {
        write(1, str_cpy, 1);
        str_cpy++;
        data->precision.value--;
        len++;
    }
    return (len);
}

int ft_str_nb(char *str)
{
    int counter;

    counter = 0;
    while (*str)
    {
        if ((*str <= '9' && *str >= '0') 
            || (*str <= 'f' && *str >= 'a')
            || (*str <= 'F' && *str >= 'A'))
            counter++;
        str++;
    }
    return (counter);
}

int precision_int(t_data *data)
{
    int len;

    len = 0;
    if (data->precision.value > ft_str_nb(data->string))
    {
        while (len < data->precision.value - ft_str_nb(data->string))
        {
            write(1, "0", 1);
            len++;
        }
        write(1, data->string, ft_strlen(data->string));
        len += ft_strlen(data->string);
    }
    else
    {
        write(1, data->string, ft_strlen(data->string));
        len += ft_strlen(data->string);
    }
    return (len);
}

int precision_write(t_data *data)
{
    int len;

    len = 0;
    if (data->precision.type == STR)
        len += precision_str(data);
    if (data->precision.type == INTEGERS)
        len += precision_int(data);
    return (len);
}