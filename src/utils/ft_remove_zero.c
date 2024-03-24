/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_remove_zero.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarolle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 23:35:42 by bcarolle          #+#    #+#             */
/*   Updated: 2024/03/23 23:31:32 by bcarolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char    *remove_zero(char *src)
{
    int     i;
    int     j;
    char    *res;

    i = ft_strlen(src) - 1;
    j = -1;
    while (src[i] == '0')
        i--;
    res = malloc(sizeof(char) * i + 2);
    while (++j <= i)
        res[j] = src[j];
    res[j] = '\0';
    free(src);
    return (res);
}