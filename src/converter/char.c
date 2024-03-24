/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarolle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 16:30:21 by bcarolle          #+#    #+#             */
/*   Updated: 2024/03/24 17:14:00 by bcarolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char    *write_char(int number, t_data **data)
{
    char    *result;

    result = malloc(sizeof(char) * 2);
    if (!result)
        return (NULL);
    if (number == 0)
        (*data)->len++;
    result[0] = number;
    result[1] = '\0';
    return (result);
}

static wchar_t   *write_wide_char(wchar_t number, t_data **data)
{
    wchar_t  *result;

    result = malloc(sizeof(wchar_t) * 2);
    if (!result)
        return (NULL);
    if (number == 0)
        (*data)->len++;
    result[0] = number;
    result[1] = '\0';
    return (result);
}

void    get_char(t_data **data, va_list args)
{
    if ((*data)->length_type == LENGTH_NONE)
        (*data)->string = write_char((char) va_arg(args, int), data);
    else if ((*data)->length_type == L)
        (*data)->w_string = write_wide_char(va_arg(args, wchar_t), data);
    else
        write(2, "Error: Unsupported length type\n", 31);
}