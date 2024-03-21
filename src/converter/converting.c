/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarolle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 14:17:12 by bcarolle          #+#    #+#             */
/*   Updated: 2024/03/21 16:59:00 by bcarolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void    converter(t_data **data, char **s, va_list args)
{
    char    *result;

    *data = (*data)->next;
    if ((*data)->type == DECIMAL)
        result = get_decimal(data, s, args);
    if ((*data)->type == STRING)
        get_string(data, args);
    if ((*data)->type == CHAR)
        get_char(data, args);
    if ((*data)->type == POINTER)
        result = va_arg(args, void *);
    if ((*data)->type == HEXADECIMAL || (*data)->type == HEXADECIMAL_CAPITAL)
        result = get_hexa(data, s, args);
    if ((*data)->type == OCTAL)
        result = get_octal(data, s, args);
    if ((*data)->type == UNSIGNED)
        result = get_unsigned(data, s, args);
    (*data)->string = result;
}