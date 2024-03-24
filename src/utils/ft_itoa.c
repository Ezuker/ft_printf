/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarolle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 15:21:19 by bcarolle          #+#    #+#             */
/*   Updated: 2024/03/24 15:07:27 by bcarolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int  ft_intlen(intmax_t n, int base)
{
    intmax_t i;

    i = 0;
    if (n == 0)
        return (1);
    if (n < 0)
    {
        if (n == LONG_MIN)
            return (20);
        n = -n;
        i++;
    }
    while (n > 0)
    {
        n /= base;
        i++;
    }
    return (i);
}

char    *ft_itoa(intmax_t n, int base, char *s)
{
    char    *str;
    int     len;
    t_bool  is_negative;

    is_negative = FALSE;
    len = ft_intlen(n, base);
    str = malloc(sizeof(char) * (len + 1));
    if (!str)
        return (NULL);
    str[len] = '\0';
    if (n < 0)
    {
        str[0] = '-';
        n = -n;
        is_negative = TRUE;
    }
    while ((len > 0 && !is_negative) || (len > 1 && is_negative))
    {
        len--;
        str[len] = s[n % base];
        n /= base;
    }
    return (str);
}