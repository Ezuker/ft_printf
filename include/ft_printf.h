/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarolle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 21:25:28 by bcarolle          #+#    #+#             */
/*   Updated: 2024/03/21 17:30:55 by bcarolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>
# include <stdlib.h>
# include <stddef.h>
# include <stdint.h>
# include <wchar.h>
# include <locale.h> //to remove
# define NB_FLOAT_DIGIT 6

# include "struct.h"

void    parse(t_data *data, char *string);
void    struct_init(t_data *data);
int     ft_atoi(const char *str);
char    *ft_itoa(intmax_t n, int base, char *s);
size_t  ft_strlen(const char *s);
size_t  ft_wstrlen(const wchar_t *s);
char    *ft_strdup(const char *s);
size_t  ft_wcstombs(char *s, const wchar_t *pwcs, size_t n);

t_flags             get_flags(char **cursor);
t_precision_type    get_precision_type(t_data_type type);
t_data_type         get_type(char **cursor);
int                 get_width(char **cursor);
t_length            get_length(char **cursor);
char                *ft_strdup(const char *s);
void                converter(t_data **data, char **s, va_list args);

char    *get_decimal(t_data **data, char **s,va_list args);
char    *get_octal(t_data **data, char **s,va_list args);
char    *get_unsigned(t_data **data, char **s,va_list args);
char    *get_hexa(t_data **data, char **s,va_list args);
void    get_char(t_data **data,va_list args);
void    get_string(t_data **data, va_list args);

#endif