/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarolle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 15:43:46 by bcarolle          #+#    #+#             */
/*   Updated: 2024/03/29 01:26:14 by bcarolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

char	*add_zero(char *res, int afpoint)
{
	int		i;

	i = 0;
	while (res[i] != '.')
		i++;
	i++;
	if ((int)ft_strlen(res) - i == afpoint)
		return (res);
	while ((int)ft_strlen(res) - i < afpoint)
		res = ft_strjoin_free(res, "0", 1);
	return (res);
}

char	*ft_ftoa(double n, int afpoint, int base, char *s_base)
{
	int			ipart;
	double		fpart;
	char		*res;

	ipart = (int)n;
	fpart = n - (double)ipart;
	res = ft_itoa(ipart, base, s_base);
	res = ft_strjoin_free(res, ".", 1);
	fpart = fpart * ft_pow(base, afpoint);
	fpart = ft_roundf(fpart);
	res = ft_strjoin_free(res, ft_itoa((intmax_t)fpart, base, s_base), 3);
	res = add_zero(res, afpoint);
	return (res);
}

char	*ft_lftoa(long double n, int afpoint, int base, char *s_base)
{
	long long int	ipart;
	double			fpart;
	char			*res;

	ipart = (long long int)n;
	fpart = n - (long double)ipart;
	res = ft_itoa(ipart, base, s_base);
	res = ft_strjoin_free(res, ".", 1);
	fpart = fpart * ft_pow(base, afpoint);
	fpart = ft_roundf(fpart);
	res = ft_strjoin_free(res, ft_itoa((long long int)fpart, base, s_base), 2);
	res = add_zero(res, afpoint);
	return (res);
}
