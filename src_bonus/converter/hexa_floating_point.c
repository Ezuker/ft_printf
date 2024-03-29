/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexa_floating_point.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarolle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 21:24:15 by bcarolle          #+#    #+#             */
/*   Updated: 2024/03/29 04:51:27 by bcarolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

char	*ft_hexa_ftoa(double n, int afpoint, int base, char *s_base)
{
	int			ipart;
	long double	fpart;
	char		*res;

	ipart = (int)n;
	fpart = n - (long double)ipart;
	res = ft_itoa(ipart, base, s_base);
	res = ft_strjoin_free(res, ".", 1);
	fpart = fpart * (long double)ft_pow(base, afpoint);
	fpart = ft_roundf(fpart);
	res = ft_strjoin_free(res, ft_itoa((intmax_t)fpart, base, s_base), 3);
	return (res);
}

char	*ft_hexa_lftoa(long double n, int afpoint, int base, char *s_base)
{
	long long int	ipart;
	long double		fpart;
	char			*res;

	ipart = (long long int)n;
	fpart = n - (long double)ipart;
	res = ft_itoa(ipart, base, s_base);
	res = ft_strjoin_free(res, ".", 1);
	fpart = fpart * (long double)ft_pow(base, afpoint);
	fpart = ft_roundf(fpart);
	res = ft_strjoin_free(res, ft_itoa((intmax_t)fpart, base, s_base), 3);
	return (res);
}

char	*hexa(va_list args, t_data **data, int *nb_power)
{
	double		result;
	char		*res;

	result = va_arg(args, double);
	*nb_power = binary_power(result);
	result = result / (double)ft_pow(2, *nb_power);
	if ((*data)->precision.type == PRECISION_NONE)
		res = ft_hexa_ftoa(result, nb_number_after_dot(result),
				16, "0123456789abcdef");
	else
		res = ft_hexa_ftoa(result, (*data)->precision.value,
				16, "0123456789abcdef");
	if ((*data)->flag_type == PLUS && result > 0)
		res = ft_strjoin_free("+", res, 2);
	if ((*data)->flag_type == SPACE && result > 0)
		res = ft_strjoin_free(" ", res, 2);
	res = remove_zero(data, res);
	res = ft_strjoin_free(res, "p", 1);
	res = ft_strjoin_free("0x", res, 2);
	return (res);
}

char	*long_hexa(va_list args, t_data **data, int *nb_power)
{
	long double	result;
	char		*res;

	result = va_arg(args, long double);
	*nb_power = binary_power(result);
	result = result / ft_pow(2, *nb_power);
	if ((*data)->precision.type == PRECISION_NONE)
		res = ft_hexa_lftoa(result, nb_number_after_dot(result),
				16, "0123456789abcdef");
	else
		res = ft_hexa_lftoa(result, (*data)->precision.value,
				16, "0123456789abcdef");
	if ((*data)->flag_type == PLUS && result > 0)
		res = ft_strjoin_free("+", res, 2);
	if ((*data)->flag_type == SPACE && result > 0)
		res = ft_strjoin_free(" ", res, 2);
	res = remove_zero(data, res);
	res = ft_strjoin_free(res, "p", 1);
	res = ft_strjoin_free("0x", res, 2);
	return (res);
}

char	*get_hexa_floating_point(t_data **data, va_list args)
{
	int			nb_power;
	char		*res;

	res = NULL;
	nb_power = 0;
	if ((*data)->length_type == LENGTH_NONE)
		res = hexa(args, data, &nb_power);
	else if ((*data)->length_type == BIG_L)
		res = long_hexa(args, data, &nb_power);
	res = ft_strjoin_free(res, "+", 1);
	res = ft_strjoin_free(res, ft_itoa(nb_power, 10, "0123456789"), 3);
	if ((*data)->type == HEXA_FLOATING_CAPITAL)
		res = ft_toupper(res);
	if ((*data)->flag_type == ZERO)
		res = zero_flag_hexa(data, res);
	return (res);
}
