/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarolle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 23:04:16 by bcarolle          #+#    #+#             */
/*   Updated: 2024/03/22 23:57:46 by bcarolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

long double  ft_pow(double x, int y)
{
    double  res;

    res = 1;
    while (y > 0)
    {
        res = res * x;
        y--;
    }
    return (res);
}

int binary_power(double x)
{
    int power;

    power = 0;
    while (x > 2)
    {
        x = x / 2;
        power++;
    }
    return (power);
}

int binary_power_long(long double x)
{
    int power;

    power = 0;
    while (x > 16)
    {
        x = x / 2;
        power++;
    }
    return (power);
}