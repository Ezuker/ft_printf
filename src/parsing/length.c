/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   length.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarolle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 14:02:25 by bcarolle          #+#    #+#             */
/*   Updated: 2024/03/21 14:05:00 by bcarolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_length return_length(char **cursor, int length, t_length type)
{
    (*cursor) += length;
    return (type);
}

t_length get_length(char **cursor)
{
    if (**cursor == 'h' && *(*cursor + 1) == 'h')
        return (return_length(cursor, 2, HH));
    if (**cursor == 'h')
        return (return_length(cursor, 1, H));
    if (**cursor == 'l' && *(*cursor + 1) == 'l')
        return (return_length(cursor, 2, LL));
    if (**cursor == 'l')
        return (return_length(cursor, 1, L));
    if (**cursor == 'j')
        return (return_length(cursor, 1, J));
    if (**cursor == 'z')
        return (return_length(cursor, 1, Z));
    if (**cursor == 't')
        return (return_length(cursor, 1, T));
    if (**cursor == 'L')
        return (return_length(cursor, 1, BIG_L));
    return (LENGTH_NONE);
}