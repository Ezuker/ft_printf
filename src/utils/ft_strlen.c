/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarolle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 15:20:56 by bcarolle          #+#    #+#             */
/*   Updated: 2024/03/21 17:01:02 by bcarolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t  ft_strlen(const char *s)
{
    size_t  i;

    i = 0;
    while (s[i])
        i++;
    return (i);
}

size_t  ft_wstrlen(const wchar_t *s)
{
    size_t  i;

    i = 0;
    while (s[i])
        i++;
    return (i);
}