/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nb_floating_digit.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarolle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 23:10:31 by bcarolle          #+#    #+#             */
/*   Updated: 2024/03/28 22:07:40 by bcarolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	nb_number_after_dot(long double n)
{
	int		i;
	double	index;

	i = 0;
	while (n - (int)n != 0 && i < 13)
	{
		index = 10.0;
		while (index >= 1.0)
		{
			if (n > index)
			{
				n = n - index;
				break ;
			}
			index -= 1.0;
		}
		n = n * 10.0;
		i++;
	}
	return (i);
}
