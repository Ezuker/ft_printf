/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarolle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 13:56:46 by bcarolle          #+#    #+#             */
/*   Updated: 2024/03/21 14:34:01 by bcarolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_precision_type    get_precision_type(t_data_type type)
{
    if (type == DECIMAL || type == OCTAL ||
        type == UNSIGNED || type == HEXADECIMAL || type == HEXADECIMAL)
        return (INTEGERS);
    if (type == HEXADECIMAL_FLOATING || type == HEXADECIMAL_FLOATING_CAPITAL
        || type == SCIENTIFIC || type == SCIENTIFIC_CAPITAL || type == FLOAT)
        return (OTHER);
    if (type == STRING)
        return (STR);
    if (type == G_CAPITAL || type == G)
        return (G_SHORT);
    return (PRECISION_NONE);
}

