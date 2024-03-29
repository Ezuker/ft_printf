/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarolle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 23:13:27 by bcarolle          #+#    #+#             */
/*   Updated: 2024/03/29 02:25:32 by bcarolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	struct_init(t_data *data)
{
	data->flag_type = FLAGS_NONE;
	data->width = 0;
	data->precision.type = PRECISION_NONE;
	data->precision.value = 0;
	data->length_type = LENGTH_NONE;
	data->type = DATA_NONE;
	data->string = NULL;
	data->w_string = NULL;
	data->len = 0;
}
