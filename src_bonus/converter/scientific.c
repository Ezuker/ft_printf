/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scientific.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarolle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 15:44:59 by bcarolle          #+#    #+#             */
/*   Updated: 2024/03/29 04:25:15 by bcarolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

double	to_scientific(double x, int *nb_power)
{
	*nb_power = 0;
	while (x > 10)
	{
		x = x / 10;
		*nb_power += 1;
	}
	return (x);
}

long double	to_scientific_long(long double x, int *nb_power)
{
	while (x > 10)
	{
		x = x / 10;
		*nb_power += 1;
	}
	return (x);
}

char	*format_to_s(va_list args, t_data **data, int *nb_pow, char *res)
{
	double	result;

	result = va_arg(args, double);
	result = to_scientific(result, nb_pow);
	if ((*data)->precision.type == PRECISION_NONE)
		res = ft_ftoa(result, F_DIGIT, 10, "0123456789");
	else
		res = ft_ftoa(result, (*data)->precision.value, 10, "0123456789");
	if ((*data)->flag_type == PLUS && res[0] != '-')
		res = ft_strjoin_free("+", res, 2);
	if ((*data)->flag_type == SPACE && res[0] != '-')
		res = ft_strjoin_free(" ", res, 2);
	return (res);
}

char	*format_to_ls(va_list args, t_data **data, int *nb_pow, char *res)
{
	long double	result_long;

	result_long = va_arg(args, long double);
	result_long = to_scientific_long(result_long, nb_pow);
	if ((*data)->precision.type == PRECISION_NONE)
		res = ft_lftoa(result_long, F_DIGIT, 10, "0123456789");
	else
		res = ft_lftoa(result_long,
				(*data)->precision.value, 10, "0123456789");
	if ((*data)->flag_type == PLUS && res[0] != '-')
		res = ft_strjoin_free("+", res, 2);
	if ((*data)->flag_type == SPACE && res[0] != '-')
		res = ft_strjoin_free(" ", res, 2);
	return (res);
}

char	*get_scientific(t_data **data, va_list args)
{
	int			nb_power;
	char		*res;

	nb_power = 0;
	res = NULL;
	if ((*data)->length_type == LENGTH_NONE)
		res = format_to_s(args, data, &nb_power, res);
	if ((*data)->length_type == BIG_L)
		res = format_to_ls(args, data, &nb_power, res);
	if ((*data)->type == SCIENTIFIC_CAPITAL)
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
	if ((*data)->flag_type == ZERO)
		res = zero_flag(data, res);
	return (res);
}
