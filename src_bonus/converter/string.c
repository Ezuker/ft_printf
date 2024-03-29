/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarolle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 16:41:16 by bcarolle          #+#    #+#             */
/*   Updated: 2024/03/29 02:30:13 by bcarolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static char	*write_string(t_data **data, char *string)
{
	if (!string)
	{
		if ((*data)->precision.value > 0 && (*data)->precision.value < 6)
			return (ft_strdup(""));
		return (ft_strdup("(null)"));
	}
	if ((*data)->precision.type == STR)
		return (precision_str(data, string));
	return (ft_strdup(string));
}

static wchar_t	*write_wide_string(t_data **data, wchar_t *string)
{
	if (!string)
	{
		if ((*data)->precision.value > 0 && (*data)->precision.value < 6)
			return (ft_wcsdup(L""));
		return (ft_wcsdup(L"(null)"));
	}
	if ((*data)->precision.type == STR)
		return (precision_wstr(data, string));
	return (ft_wcsdup(string));
}

void	get_string(t_data **data, va_list args)
{
	if ((*data)->length_type == LENGTH_NONE)
		(*data)->string = write_string(data, (char *) va_arg(args, char *));
	else if ((*data)->length_type == L)
		(*data)->w_string = write_wide_string(data,
				(wchar_t *)va_arg(args, wchar_t *));
	else
		write(2, "Error: Unsupported length type\n", 31);
}
