/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_roundf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarolle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 18:14:31 by bcarolle          #+#    #+#             */
/*   Updated: 2024/03/29 02:23:44 by bcarolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

long double	ft_roundf(long double n)
{
	long long int	ipart;
	long double		fpart;

	ipart = (long long int)n;
	fpart = n - (long double)ipart;
	if (fpart >= 0.5)
		return (ipart + 1);
	return (ipart);
}
