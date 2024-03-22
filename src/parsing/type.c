/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarolle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 14:00:44 by bcarolle          #+#    #+#             */
/*   Updated: 2024/03/22 21:27:52 by bcarolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_data_type return_type(char **cursor, t_data_type type)
{
    (*cursor) += 1;
    return (type);
}

t_data_type get_type(char **cursor)
{
    if (**cursor == 'd' || **cursor == 'i')
        return (return_type(cursor, DECIMAL));
    if (**cursor == 'u')
        return (return_type(cursor, UNSIGNED));
    if (**cursor == 'o')
        return (return_type(cursor, OCTAL));
    if (**cursor == 'x')
        return (return_type(cursor, HEXADECIMAL));
    if (**cursor == 'X')
        return (return_type(cursor, HEXADECIMAL_CAPITAL));
    if (**cursor == 'f' || **cursor == 'F')
        return (return_type(cursor, FLOAT));
    if (**cursor == 'e')
        return (return_type(cursor, SCIENTIFIC));
    if (**cursor == 'E')
        return (return_type(cursor, SCIENTIFIC_CAPITAL));
    if (**cursor == 'g')
        return (return_type(cursor, G));
    if (**cursor == 'G')
        return (return_type(cursor, G_CAPITAL));
    if (**cursor == 'a')
        return (return_type(cursor, HEXA_FLOATING));
    if (**cursor == 'A')
        return (return_type(cursor, HEXA_FLOATING_CAPITAL));
    if (**cursor == 'c')
        return (return_type(cursor, CHAR));
    if (**cursor == 's')
        return (return_type(cursor, STRING));
    if (**cursor == 'p')
        return (return_type(cursor, POINTER));
    if (**cursor == 'n')
        return (return_type(cursor, NOTHING));
    if (**cursor == '%')
        return (return_type(cursor, PERCENT));
    return (NOT_VALID);
}