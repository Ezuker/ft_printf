/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarolle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 13:57:14 by bcarolle          #+#    #+#             */
/*   Updated: 2024/03/23 21:15:45 by bcarolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int get_width(char **cursor, va_list args)
{
    int result;

    if (**cursor == '*')
    {
        result = (int)va_arg(args, int);
        (*cursor)++;
    }
    else
    {
        result = ft_atoi(*cursor);
        while (**cursor > '0' && **cursor < '9')
            (*cursor)++;
    }
    return (result);
}