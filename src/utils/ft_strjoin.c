/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarolle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 15:42:33 by bcarolle          #+#    #+#             */
/*   Updated: 2024/03/22 15:43:03 by bcarolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char    *ft_strjoin(char *s1, char *s2)
{
    char    *res;
    int     i;
    int     j;

    i = 0;
    j = 0;
    res = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
    if (!res)
        return (NULL);
    while (s1[i])
    {
        res[i] = s1[i];
        i++;
    }
    while (s2[j])
    {
        res[i] = s2[j];
        i++;
        j++;
    }
    res[i] = '\0';
    return (res);
}