/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarolle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 21:20:50 by bcarolle          #+#    #+#             */
/*   Updated: 2024/03/21 14:49:50 by bcarolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_printf(const char *s, ...)
{
    va_list args;
    char    *string;
    t_data  *data;

    string = (char *)s;
    data = malloc(sizeof(t_data));
    struct_init(data);
    parse(data, (char *)s);
    va_start(args, s);
    while (*string)
    {
        if (*string == '%')
            converter(&data, &string, args);
        else
            write(1, string, 1);
        string++;
    }
    va_end(args);
    return (0);
}

int main()
{
    printf("%hhd\n", 356); //will print 5 DIGITS (excluding .)

    ft_printf("%-5.4d", 48);
}