/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precision_write.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarolle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 20:11:03 by bcarolle          #+#    #+#             */
/*   Updated: 2024/03/28 01:40:46 by bcarolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char *precision_str(t_data **data, char *string)
{
	char *str_cpy;
	char *new_string;
	int len;

	len = 0;
	str_cpy = string;
	new_string = malloc(sizeof(char) * ((*data)->precision.value + 1));
	if (!new_string)
		return (NULL);
	while (*str_cpy && (*data)->precision.value > 0)
	{
		new_string[len] = *str_cpy;
		str_cpy++;
		(*data)->precision.value--;
		len++;
	}
	new_string[len] = '\0';
	return (new_string);
}

wchar_t *precision_wstr(t_data **data, wchar_t *string)
{
    wchar_t *str_cpy;
    wchar_t *new_string;
    int len;

    len = 0;
    str_cpy = string;
    new_string = malloc(sizeof(wchar_t) * ((*data)->precision.value + 1));
    if (!new_string)
        return (NULL);
    while (*str_cpy && (*data)->precision.value > 0)
    {
        new_string[len] = *str_cpy;
        str_cpy++;
        (*data)->precision.value--;
        len++;
    }
    new_string[len] = '\0';
    return (new_string);
}

int ft_str_nb(char *str)
{
    int counter;

    counter = 0;
    while (*str)
    {
        if ((*str <= '9' && *str >= '0') 
            || (*str <= 'f' && *str >= 'a')
            || (*str <= 'F' && *str >= 'A'))
            counter++;
        str++;
    }
    return (counter);
}

char	*precision_int(t_data **data, char *str)
{
	char	*new_str;
	char	*tmp_str;

	if ((*data)->precision.value == 0 && *str == '0')
	{
		free(str);
		return (ft_strdup(""));
	}
	if ((*data)->precision.value <= (int)ft_str_nb(str))
		return (str);
	if (*str == '-' || *str == '+' || *str == ' ')
		tmp_str = ft_substr(str, 1, ft_strlen(str) - 1);
	else
		tmp_str = ft_strdup(str);
	while (ft_str_nb(tmp_str) < (*data)->precision.value)
	{
		new_str = ft_strjoin_free("0", tmp_str, 2);
		tmp_str = new_str;
	}
	if (*str == '-' || *str == '+' || *str == ' ')
		new_str = ft_strjoin_free(ft_substr(str, 0, 1), new_str, 3);
	free(str);
	return (new_str);
}

// int precision_write(t_data *data)
// {
//     int len;

//     len = 0;
//     // if (data->precision.type == STR)
//     //     len += precision_str(data);
//     // if (data->precision.type == INTEGERS)
//     //     len += precision_int(data);
//     return (len);
// }
