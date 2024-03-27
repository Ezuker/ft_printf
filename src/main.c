/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarolle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 21:20:50 by bcarolle          #+#    #+#             */
/*   Updated: 2024/03/27 20:36:48 by bcarolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void    ft_free_all(t_data *data)
{
    if (data->string)
        free(data->string);
    if (data->w_string)
        free(data->w_string);
    free(data);
}

size_t root(va_list args, char *string)
{
    t_data  *data;
    size_t  len;

    len = 0;
    while (*string)
    {
        if (*string == '%')
        {
            data = malloc(sizeof(t_data));
            if (!data)
                return (0);
            struct_init(data);
            if (parse(data, &string, args))
                return (0);
            converter(&data, &string, args);
            len += writer(data);
            ft_free_all(data);
        }
        else
        {
            write(1, string, 1);
            len++;
            string++;
        }
    }
    return (len);
}

int ft_printf(const char *s, ...)
{
    va_list args;
    size_t  len;

    va_start(args, s);
    len = root(args, (char *)s);
    va_end(args);
    return (len);
}

int main()
{
    printf("printf: %d\n", printf("%-ci%-cp%4cs%-11cx", 'a', 'b', 'c', 'd'));
    printf("ft_printf: %d\n", ft_printf("%-ci%-cp%4cs%-11cx", 'a', 'b', 'c', 'd'));
}