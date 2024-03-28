/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexa_floating_point.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarolle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 21:24:15 by bcarolle          #+#    #+#             */
/*   Updated: 2024/03/28 02:47:04 by bcarolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_hexa_ftoa(double n, int base, char *s_base)
{
	int			ipart;
	long double	fpart;
	char		*res;
	int			i;

	ipart = (int)n;
	fpart = n - (long double)ipart;
	res = ft_itoa(ipart, base, s_base);
	res = ft_recalloc(res, ft_strlen(res), ft_strlen(res) + 1);
	i = ft_strlen(res);
	res[i] = '.';
	fpart = fpart * (long double)ft_pow(base, nb_number_after_dot(n));
	fpart = ft_roundf(fpart);
	res = ft_strjoin_free(res, ft_itoa((intmax_t)fpart, base, s_base), 2);
	return (res);
}

char	*ft_hexa_lftoa(long double n, int base, char *s_base)
{
	long long int	ipart;
	long double		fpart;
	char			*res;
	int				i;

	ipart = (long long int)n;
	fpart = n - (long double)ipart;
	res = ft_itoa(ipart, base, s_base);
	res = ft_recalloc(res, ft_strlen(res), ft_strlen(res) + 1);
	i = ft_strlen(res);
	res[i] = '.';
	fpart = fpart * (long double)ft_pow(base, nb_number_after_dot(n));
	fpart = ft_roundf(fpart);
	res = ft_strjoin_free(res, ft_itoa((intmax_t)fpart, base, s_base), 2);
	return (res);
}

char	*get_hexa_floating_point(t_data **data, va_list args)
{
	double		result;
	long double	result_l;
	int			nb_power;
	char		*res;

	if ((*data)->length_type == LENGTH_NONE)
	{
		result = va_arg(args, double);
		nb_power = binary_power(result);
		result = result / (double)ft_pow(2, nb_power);
		res = ft_hexa_ftoa(result, 16, "0123456789abcdef");
		res = ft_strjoin("0x", res);
		res = remove_zero(res);
		res = ft_strjoin(res, "p");
	}
	else if ((*data)->length_type == BIG_L)
	{
		result_l = va_arg(args, long double);
		nb_power = binary_power_long(result_l);
		result_l = result_l / ft_pow(2, nb_power);
		res = ft_hexa_lftoa(result_l, 16, "0123456789abcdef");
		res = ft_strjoin("0x", res);
		res = remove_zero(res);
		res = ft_strjoin(res, "p");
	}
	res = ft_strjoin(res, "+");
	if (nb_power < 10)
		res = ft_strjoin(res, "0");
	res = ft_strjoin(res, ft_itoa(nb_power, 10, "0123456789"));
	if ((*data)->type == HEXA_FLOATING_CAPITAL)
		res = ft_toupper(res);
	return (res);
}
