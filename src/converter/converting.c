/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarolle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 14:17:12 by bcarolle          #+#    #+#             */
/*   Updated: 2024/03/28 02:37:50 by bcarolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	converter(t_data **data, char **s, va_list args)
{
	char	*result;

	result = NULL;
	if ((*data)->type == DECIMAL)
		result = get_decimal(data, s, args);
	if ((*data)->type == HEXADECIMAL || (*data)->type == HEXADECIMAL_CAPITAL)
		result = get_hexa(data, s, args);
	if ((*data)->type == OCTAL)
		result = get_octal(data, s, args);
	if ((*data)->type == UNSIGNED)
		result = get_unsigned(data, s, args);
	if ((*data)->type == PERCENT)
		result = ft_strdup("%");
	if ((*data)->type == POINTER)
		result = get_pointer(args);
	if ((*data)->type == NOTHING)
		result = ft_strdup("");
	if ((*data)->type == SCIENTIFIC || (*data)->type == SCIENTIFIC_CAPITAL)
		result = get_scientific(data, args);
	if ((*data)->type == FLOAT)
		result = get_float(data, args);
	if ((*data)->type == G || (*data)->type == G_CAPITAL)
		result = get_shortest_float(data, args);
	if ((*data)->type == HEXA_FLOATING || (*data)->type == HEXA_FLOATING_CAPITAL)
		result = get_hexa_floating_point(data, args);
	(*data)->string = result;
	if ((*data)->type == STRING)
		get_string(data, args);
	if ((*data)->type == CHAR)
		get_char(data, args);
}
