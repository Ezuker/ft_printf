/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarolle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 15:43:46 by bcarolle          #+#    #+#             */
/*   Updated: 2024/03/28 03:14:17 by bcarolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_ftoa(double n, int afpoint, int base, char *s_base)
{
	int		ipart;
	double	fpart;
	char	*res;
	int		i;

	ipart = (int)n;
	fpart = n - (double)ipart;
	res = ft_itoa(ipart, base, s_base);
	res = ft_recalloc(res, ft_strlen(res), ft_strlen(res) + 1);
	i = ft_strlen(res);
	res[i] = '.';
	fpart = fpart * (double)ft_pow(base, afpoint);
	fpart = ft_roundf(fpart);
	res = ft_strjoin_free(res, ft_itoa((int)fpart, base, s_base), 3);
	return (res);
}

char    *ft_lftoa(long double n, int afpoint, int base, char *s_base)
{
    long long int       ipart;
    double              fpart;
    char                *res;
    long long int       i;

    ipart = (long long int)n;
    fpart = n - (long double)ipart;
    res = ft_itoa(ipart, base, s_base);
    res = ft_recalloc(res, ft_strlen(res), ft_strlen(res) + 1);
    i = ft_strlen(res);
    res[i] = '.';
    fpart = fpart * ft_pow(base, afpoint);
    fpart = ft_roundf(fpart);
    res = ft_strjoin_free(res, ft_itoa((long long int)fpart, base, s_base), 2);
    return (res);
}
