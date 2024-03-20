/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarolle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 21:20:50 by bcarolle          #+#    #+#             */
/*   Updated: 2024/03/20 23:15:10 by bcarolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_printf(const char *s, ...)
{
    va_list args;
    t_data  *data;

    data = malloc(sizeof(t_data));
    struct_init(data);
    parse(data, (char *)s);
    va_start(args, s);
    
    va_end(args);
    return (0);
}

int main()
{
    printf("%.5g\n", 3.4253); //will print 5 DIGITS (excluding .)
    printf("%.5G\n", 3.42443); // in uppercase

    printf("%.6f\n", 10.564652146);
    printf("%.4X\n", 5465544);
}