/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scientific.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarolle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 15:44:59 by bcarolle          #+#    #+#             */
/*   Updated: 2024/03/23 23:30:42 by bcarolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

double  to_scientific(double x, int *nb_power)
{
    while (x > 10)
    {
        x = x / 10;
        *nb_power += 1;
    }
    return (x);
}

long double to_scientific_long(long double x, int *nb_power)
{
    while (x > 10)
    {
        x = x / 10;
        *nb_power += 1;
    }
    return (x);
}

char    *get_scientific(t_data **data, va_list args)
{
    double      result;
    long double result_long;
    int         nb_power;
    char        *res;

    nb_power = 0;
    res = NULL;
    if ((*data)->length_type == LENGTH_NONE)
    {
        result = va_arg(args, double);
        result = to_scientific(result, &nb_power);
        res = ft_ftoa(result, F_DIGIT, 10, "0123456789");
    }
    if ((*data)->length_type == BIG_L)
    {
        result_long = va_arg(args, long double);
        result_long = to_scientific_long(result_long, &nb_power);
        res = ft_lftoa(result_long, F_DIGIT, 10, "0123456789");
    }
    if ((*data)->type == SCIENTIFIC_CAPITAL)
        res = ft_strjoin(res, "E");
    else
        res = ft_strjoin(res, "e");
    if (nb_power < 0)
        res = ft_strjoin(res, "-");
    else
        res = ft_strjoin(res, "+");
    if (nb_power < 10)
        res = ft_strjoin(res, "0");
    res = ft_strjoin_free(res, ft_itoa(nb_power, 10, "0123456789"), 2);
    return (res);
}