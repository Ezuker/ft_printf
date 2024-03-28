/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarolle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 15:11:57 by bcarolle          #+#    #+#             */
/*   Updated: 2024/03/28 19:09:58 by bcarolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*get_float(t_data **data, va_list args)
{
	char	*result;

	result = NULL;
	if ((*data)->length_type == LENGTH_NONE)
	{
		if ((*data)->precision.type == PRECISION_NONE)
			result = ft_ftoa(va_arg(args, double), F_DIGIT, 10, "0123456789");
		else
			result = (ft_ftoa(va_arg(args, double),
						(*data)->precision.value, 10, "0123456789"));
		if ((*data)->flag_type == PLUS && result[0] != '-')
			result = ft_strjoin_free("+", result, 2);
		if ((*data)->flag_type == SPACE && result[0] != '-')
			result = ft_strjoin_free(" ", result, 2);
		if ((*data)->flag_type == ZERO)
			result = zero_flag(data, result);
	}
	if ((*data)->length_type == BIG_L)
	{
		if ((*data)->precision.type == PRECISION_NONE)
			result = ft_lftoa(va_arg(args, long double),
					F_DIGIT, 10, "0123456789");
		else
			result = (ft_lftoa(va_arg(args, long double),
						(*data)->precision.value, 10, "0123456789"));
		if ((*data)->flag_type == PLUS && result[0] != '-')
			result = ft_strjoin_free("+", result, 2);
		if ((*data)->flag_type == SPACE && result[0] != '-')
			result = ft_strjoin_free(" ", result, 2);
		if ((*data)->flag_type == ZERO)
			result = zero_flag(data, result);
	}
	return (result);
}
