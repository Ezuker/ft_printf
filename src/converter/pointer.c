/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pointer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarolle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 14:33:59 by bcarolle          #+#    #+#             */
/*   Updated: 2024/03/22 14:37:40 by bcarolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char    *get_pointer(va_list args)
{
    char    *result;
    void    *pointer;
    char    *base;

    pointer = va_arg(args, void *);
    base = ft_strdup("0123456789abcdef");
    result = ft_itoa((unsigned long long)pointer, 16, base);
    free(base);
    return (result);
}