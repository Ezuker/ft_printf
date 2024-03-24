/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shortest_float.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarolle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 18:37:38 by bcarolle          #+#    #+#             */
/*   Updated: 2024/03/24 21:50:13 by bcarolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char    *get_sscientific(t_data **data, double arg)
{
    int         nb_power;
    char        *res;

    nb_power = 0;
    arg = to_scientific(arg, &nb_power);
    res = ft_ftoa(arg, F_DIGIT - 1, 10, "0123456789");
    if ((*data)->type == G_CAPITAL)
        res = ft_strjoin(res, "E");
    else
        res = ft_strjoin(res, "e");
    if (nb_power < 0)
        res = ft_strjoin(res, "-");
    else
        res = ft_strjoin(res, "+");
    if (nb_power < 10)
        res = ft_strjoin(res, "0");
    res = ft_strjoin(res, ft_itoa(nb_power, 10, "0123456789"));
    return (res);
}

char    *get_sscientific_long(t_data **data, long double arg)
{
    int         nb_power;
    char        *res;

    nb_power = 0;
    arg = to_scientific_long(arg, &nb_power);
    res = ft_lftoa(arg, F_DIGIT - 1, 10, "0123456789");
    if ((*data)->type == G_CAPITAL)
        res = ft_strjoin(res, "E");
    else
        res = ft_strjoin(res, "e");
    if (nb_power < 0)
        res = ft_strjoin(res, "-");
    else
        res = ft_strjoin(res, "+");
    if (nb_power < 10)
        res = ft_strjoin(res, "0");
    res = ft_strjoin(res, ft_itoa(nb_power, 10, "0123456789"));
    return (res);
}

char    *get_shortest_float(t_data **data, va_list args)
{
    char    *result_float;
    char    *result_scientific;
    double  res;
    long double res_long;

    if ((*data)->length_type == LENGTH_NONE)
    {
        res = va_arg(args, double);
        result_float = ft_ftoa(res, 2, 10, "0123456789");
        result_scientific = get_sscientific(data, res);
    }
    if ((*data)->length_type == BIG_L)
    {
        res_long = va_arg(args, long double);
        result_float = ft_lftoa(res_long, 2, 10, "0123456789");
        result_scientific = get_sscientific_long(data, res_long);
    }
    if (ft_strlen(result_float) < ft_strlen(result_scientific))
    {
        free(result_scientific);
        return (remove_zero(result_float));
    }
    else
    {
        free(result_float);
        return (result_scientific);
    }
}