/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarolle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 15:21:19 by bcarolle          #+#    #+#             */
/*   Updated: 2024/03/21 16:23:22 by bcarolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int  ft_intlen(int n, int base)
{
    int i;

    i = 0;
    if (n < 0)
    {
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

    len = ft_intlen(n, base);
    str = malloc(sizeof(char) * (len + 1));
    if (!str)
        return (NULL);
    str[len] = '\0';
    if (n < 0)
    {
        str[0] = '-';
        n = -n;
    }
    while (len > 1 || (len > 0 && str[0] != '-'))
    {
        len--;
        str[len] = s[n % base];
        n /= base;
    }
    return (str);
}