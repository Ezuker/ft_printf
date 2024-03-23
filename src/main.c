/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarolle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 21:20:50 by bcarolle          #+#    #+#             */
/*   Updated: 2024/03/23 22:46:57 by bcarolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_printf(const char *s, ...)
{
    va_list args;
    char    *string;
    t_data  *data;

    string = (char *)s;
    va_start(args, s);
    while (*string)
    {
        if (*string == '%')
        {
            data = malloc(sizeof(t_data));
            if (!data)
                return (0);
            struct_init(data);
            parse(data, &string, args);
            converter(&data, &string, args);
            writer(data);
            free(data);
        }
        else
        {
            write(1, string, 1);
            string++;
        }
    }
    va_end(args);
    return (0);
}

int main()
{
    int     test = 34;

    printf("%f haha %d\n", (double)test, test);
    ft_printf("%f haha %d\n", (double)test, test);
}