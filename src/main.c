/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarolle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 21:20:50 by bcarolle          #+#    #+#             */
/*   Updated: 2024/03/22 23:55:30 by bcarolle         ###   ########.fr       */
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
            write(1, data->string, ft_strlen(data->string));
            write(1, "\n", 1);
            // write(1, data->w_string, ft_wstrlen(data->w_string));
            // char mbstr[(2 * ft_wstrlen(data->w_string)) + 1]; // allocate enough space for the multibyte string
            // size_t len = ft_wcstombs(mbstr, data->w_string, sizeof(mbstr)); // convert the wide string to a multibyte string
            // if (len != (size_t)-1) // if the conversion was successful
            // {
            //     write(1, mbstr, len); // write the multibyte string
            // }
            break;
        }
        else
            write(1, string, 1);
        string++;
    }
    va_end(args);
    return (0);
}

void    vaargtest(const char *s, ...)
{
    va_list args;
    va_start(args, s);
    int *test = va_arg(args, int *);
    printf("%d\n", *test);
    va_end(args);
    
}

int main()
{
    double  test = FLT_MAX;
    long double  test2 = FLT_MAX;
    printf("%a\n", test);
    printf("%La\n", test2);

    ft_printf("%a\n", test);
    ft_printf("%La\n", test2);

    // long double   test2 = 54484894684.48948948948;
    // setlocale(LC_ALL, "");
    // ft_printf("%ls\n", L"ππ");
    // ft_printf("%a\n", test);
    // ft_printf("%La\n", test2);
    // printf("0x%xp+\n", test4);  
    // printf("%s\n", ft_itoa((intmax_t) test, 16, "0123456789abcdef"));
    // ft_printf("%g %LG\n", test, test2);
}