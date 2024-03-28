/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shortest_float.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarolle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 18:37:38 by bcarolle          #+#    #+#             */
/*   Updated: 2024/03/28 21:58:02 by bcarolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*get_sscientific(t_data **data, double arg)
{
	int		nb_power;
	char	*res;

	nb_power = 0;
	arg = to_scientific(arg, &nb_power);
	if ((*data)->precision.type == PRECISION_NONE)
		res = ft_ftoa(arg, F_DIGIT, 10, "0123456789");
	else
		res = ft_ftoa(arg, (*data)->precision.value - 1, 10, "0123456789");
	res = remove_zero(data, res);
	if ((*data)->flag_type == PLUS && res[0] != '-')
		res = ft_strjoin_free("+", res, 2);
	if ((*data)->flag_type == SPACE && res[0] != '-')
		res = ft_strjoin_free(" ", res, 2);
	if ((*data)->type == G_CAPITAL)
		res = ft_strjoin_free(res, "E", 1);
	else
		res = ft_strjoin_free(res, "e", 1);
	if (nb_power < 0)
		res = ft_strjoin_free(res, "-", 1);
	else
		res = ft_strjoin_free(res, "+", 1);
	if (nb_power < 10)
		res = ft_strjoin_free(res, "0", 1);
	res = ft_strjoin_free(res, ft_itoa(nb_power, 10, "0123456789"), 3);
	return (res);
}

char	*get_sscientific_long(t_data **data, long double arg)
{
	int		nb_power;
	char	*res;

	nb_power = 0;
	arg = to_scientific_long(arg, &nb_power);
	if ((*data)->precision.type == PRECISION_NONE)
		res = ft_lftoa(arg, F_DIGIT, 10, "0123456789");
	else
		res = ft_lftoa(arg,
				(*data)->precision.value, 10, "0123456789");
	if ((*data)->flag_type == PLUS && res[0] != '-')
		res = ft_strjoin_free("+", res, 2);
	if ((*data)->flag_type == SPACE && res[0] != '-')
		res = ft_strjoin_free(" ", res, 2);
	if ((*data)->type == G_CAPITAL)
		res = ft_strjoin_free(res, "E", 1);
	else
		res = ft_strjoin_free(res, "e", 1);
	if (nb_power < 0)
		res = ft_strjoin_free(res, "-", 1);
	else
		res = ft_strjoin_free(res, "+", 1);
	if (nb_power < 10)
		res = ft_strjoin_free(res, "0", 1);
	res = ft_strjoin_free(res, ft_itoa(nb_power, 10, "0123456789"), 3);
	return (res);
}

int	get_afpoint(t_data **data, long double res)
{
	int			af_point;
	intmax_t	r_part;
	int			size;
	char		*str;

	r_part = (intmax_t)res;
	str = ft_itoa(r_part, 10, "0123456789");
	size = ft_strlen(str);
	free(str);
	if ((*data)->precision.type == PRECISION_NONE)
		af_point = 6 - size;
	else
		af_point = (*data)->precision.value - size;
	return (af_point);
}


char	*get_shortest_float(t_data **data, va_list args)
{
	char		*result_float;
	char		*result_scientific;
	double		res;
	long double	res_long;
	int			af_point;

	if ((*data)->length_type == LENGTH_NONE)
	{
		res = va_arg(args, double);
		af_point = get_afpoint(data, (long double)res);
		result_float = NULL;
		if (af_point >= 0)
		{
			result_float = ft_ftoa(res, af_point, 10, "0123456789");
			result_float = remove_zero(data, result_float);
			if ((*data)->flag_type == ZERO)
				result_float = zero_flag(data, result_float);
			return (result_float);
		}
		else
		{
			if ((*data)->precision.value == 0)
				(*data)->precision.value = 1;
			result_scientific = get_sscientific(data, res);
			if ((*data)->flag_type == ZERO)
				result_scientific = zero_flag(data, result_scientific);
			return (result_scientific);
		}
	}
	if ((*data)->length_type == BIG_L)
	{
		res_long = va_arg(args, long double);
		af_point = get_afpoint(data, res_long);
		result_float = NULL;
		if (af_point >= 0)
		{
			result_float = ft_lftoa(res_long, af_point, 10, "0123456789");
			result_float = remove_zero(data, result_float);
			if ((*data)->flag_type == ZERO)
				result_float = zero_flag(data, result_float);
			return (result_float);
		}
		else
		{
			if ((*data)->precision.value == 0)
				(*data)->precision.value = 1;
			result_scientific = get_sscientific_long(data, res_long);
			if ((*data)->flag_type == ZERO)
				result_scientific = zero_flag(data, result_scientific);
			return (result_scientific);
		}
	}
	return (NULL);
}
