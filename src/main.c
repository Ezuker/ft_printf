/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarolle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 21:20:50 by bcarolle          #+#    #+#             */
/*   Updated: 2024/03/21 18:07:40 by bcarolle         ###   ########.fr       */
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
    if (!data)
        return (0);
    struct_init(data);
    parse(data, (char *)s);
    va_start(args, s);
    while (*string)
    {
        if (*string == '%')
        {
            converter(&data, &string, args);
            // write(1, data->w_string, ft_wstrlen(data->w_string));
            char mbstr[(2 * ft_wstrlen(data->w_string)) + 1]; // allocate enough space for the multibyte string
            size_t len = ft_wcstombs(mbstr, data->w_string, sizeof(mbstr)); // convert the wide string to a multibyte string
            if (len != (size_t)-1) // if the conversion was successful
            {
                write(1, mbstr, len); // write the multibyte string
            }
            break;
        }
        else
            write(1, string, 1);
        string++;
    }
    va_end(args);
    return (0);
}

int main()
{
    setlocale(LC_ALL, "");

    printf("%ls\n", L"ππ");
    printf("%c\n", 'a');


    ft_printf("%ls\n", L"ππ");
    // ft_printf("%c\n", 'a');
}