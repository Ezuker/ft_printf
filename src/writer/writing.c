/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   writing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarolle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 21:07:35 by bcarolle          #+#    #+#             */
/*   Updated: 2024/03/28 19:31:15 by bcarolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int write_multiplebyte_character(t_data *data)
{
    char    mbstr[(2 * ft_wstrlen(data->w_string)) + 1];
    size_t  len;

    write(1, data->w_string, ft_wstrlen(data->w_string));
    len = ft_wcstombs(mbstr, data->w_string, sizeof(mbstr));
    if (len != (size_t)-1)
    {
        write(1, mbstr, len);
    }
    return (len);
}

static int  minus_flag(t_data *data)
{
    size_t len;
    size_t  s_len;

    len = 0;
    s_len = ft_strlen(data->string) + data->len;
    if (data->width < (int)s_len)
        return (0);
    while (len < data->width - s_len)
    {
        write(1, " ", 1);
        len++;
    }
    return (len);
}

int	no_flag_width(t_data *data)
{
	size_t len;
	size_t s_len;

	len = 0;
	s_len = ft_strlen(data->string) + data->len;
	if (data->width < (int)s_len)
		return (0);
	while (len < data->width - s_len)
	{
		write(1, " ", 1);
		len++;
	}
	return (len);
}

int no_flag(t_data *data)
{
	size_t len;
	// size_t s_len;

	len = 0;
	len += no_flag_width(data);
	return (len);
}

int hash_flag_float(t_data *data)
{
    int len;

    (void)data;
    len = 0;
    return (len);
}
int hashtag_flag(t_data *data)
{
    int len;

    len = 0;
    len += hash_flag_float(data);
    return (len);
}


size_t writer(t_data *data)
{
	size_t  len;

	len = 0;
	len += data->len;
	if (data->w_string)
		len = write_multiplebyte_character(data);
	else
	{
		if (data->width != 0 && data->flag_type != MINUS)
			len += no_flag(data);
		if (data->len == 1 && ft_strlen(data->string) == 0)
			write(1, "\0", 1);
		else
		{
			write(1, data->string, ft_strlen(data->string));
			len += ft_strlen(data->string);
		}
		if (data->flag_type == MINUS)
			len += minus_flag(data);
	}
	return (len);
}
