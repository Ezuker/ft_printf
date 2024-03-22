/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarolle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 15:11:57 by bcarolle          #+#    #+#             */
/*   Updated: 2024/03/22 21:47:08 by bcarolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char    *get_float(t_data **data, va_list args)
{
    if ((*data)->length_type == LENGTH_NONE)
        return (ft_ftoa(va_arg(args, double), F_DIGIT, 10, "0123456789"));
    if ((*data)->length_type == BIG_L)
        return (ft_lftoa(va_arg(args, long double), F_DIGIT, 10, "0123456789"));
    return (NULL);
}