/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarolle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 16:41:16 by bcarolle          #+#    #+#             */
/*   Updated: 2024/03/21 18:04:36 by bcarolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char    *write_string(char *string)
{
    return (ft_strdup(string));
}

static wchar_t    *write_wide_string(wchar_t *string)
{
    return (wcsdup(string));
}

void    get_string(t_data **data, va_list args)
{
    if ((*data)->length_type == LENGTH_NONE)
        (*data)->string = write_string((char *) va_arg(args, char *));
    else if ((*data)->length_type == L)
        (*data)->w_string = write_wide_string((wchar_t *)va_arg(args, wchar_t *));
    else
        write(2, "Error: Unsupported length type\n", 31);
}