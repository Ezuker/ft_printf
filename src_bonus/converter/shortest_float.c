/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shortest_float.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarolle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 18:37:38 by bcarolle          #+#    #+#             */
/*   Updated: 2024/03/29 04:31:15 by bcarolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

char	*get_shortest_float(t_data **data, va_list args)
{
	if ((*data)->length_type == LENGTH_NONE)
		return (flag_g_to_char(args, data));
	if ((*data)->length_type == BIG_L)
		return (flag_lg_to_char(args, data));
	return (NULL);
}
