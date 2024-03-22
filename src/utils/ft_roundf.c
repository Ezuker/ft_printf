/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_roundf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarolle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 18:14:31 by bcarolle          #+#    #+#             */
/*   Updated: 2024/03/22 18:18:06 by bcarolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

long double  ft_roundf(long double n)
{
    long long int   ipart;
    long double     fpart;

    ipart = (long long int)n;
    fpart = n - (long double)ipart;
    if (fpart >= 0.5)
        return (ipart + 1);
    return (ipart);
}