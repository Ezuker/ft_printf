/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarolle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 21:25:28 by bcarolle          #+#    #+#             */
/*   Updated: 2024/03/24 20:13:49 by bcarolle         ###   ########.fr       */
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
# include <limits.h>
# include <float.h>
# include <locale.h> //to remove
# define F_DIGIT 6

# include "struct.h"

int ft_printf(const char *s, ...);

void        parse(t_data *data, char **string, va_list args);
void        struct_init(t_data *data);
int         ft_atoi(const char *str);
char        *ft_itoa(intmax_t n, int base, char *s);
size_t      ft_strlen(const char *s);
size_t      ft_wstrlen(const wchar_t *s);
char        *ft_strdup(const char *s);
size_t      ft_wcstombs(char *s, const wchar_t *pwcs, size_t n);
wchar_t     *ft_wcsdup(wchar_t *s);
char        *ft_strjoin(char *s1, char *s2);
char        *ft_ftoa(double n, int afpoint, int base, char *s_base);
char        *ft_lftoa(long double n, int afpoint, int base, char *s_base);
long double  ft_roundf(long double);
double      to_scientific(double x, int *nb_power);
long double to_scientific_long(long double x, int *nb_power);
void        *ft_recalloc(void *ptr, size_t old_size, size_t new_size);
long double ft_pow(double x, int y);
int         binary_power(double x);
int         binary_power_long(long double x);
int         nb_number_after_dot(long double n);
char        *ft_toupper(char* s);
char        *remove_zero(char *src);
char    *ft_strjoin_free(char *s1, char *s2, int which);
char    *ft_substr(char const *s, unsigned int start, size_t len);

t_flags             get_flags(char **cursor);
t_precision_type    get_precision_type(t_data_type type);
t_data_type         get_type(char **cursor);
int                 get_width(char **cursor, va_list args);
t_length            get_length(char **cursor);
char                *ft_strdup(const char *s);
void                converter(t_data **data, char **s, va_list args);

char    *get_decimal(t_data **data, char **s,va_list args);
char    *get_octal(t_data **data, char **s,va_list args);
char    *get_unsigned(t_data **data, char **s,va_list args);
char    *get_hexa(t_data **data, char **s,va_list args);
char    *get_pointer(va_list args);
char    *get_float(t_data **data, va_list args);
void    get_char(t_data **data,va_list args);
void    get_string(t_data **data, va_list args);
char    *get_float(t_data **data, va_list args);
char    *get_scientific(t_data **data, va_list args);
char    *get_shortest_float(t_data **data, va_list args);
char    *get_hexa_floating_point(t_data **data, va_list args);

size_t      writer(t_data *data);
int         precision_write(t_data *data);

#endif