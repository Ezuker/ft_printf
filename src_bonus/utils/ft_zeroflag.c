/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_zeroflag.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarolle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 04:33:18 by bcarolle          #+#    #+#             */
/*   Updated: 2024/03/29 04:33:21 by bcarolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

char	*zero_flag_hexa(t_data **data, char *s)
{
	char	*new_str;

	new_str = s;
	if ((*data)->width > (int)ft_strlen(s))
	{
		if ((*data)->type == HEXA_FLOATING)
			new_str = ft_strdup("0x");
		else
			new_str = ft_strdup("0X");
		while ((*data)->width > (int)ft_strlen(s))
		{
			new_str = ft_strjoin_free(new_str, "0", 1);
			(*data)->width--;
		}
		new_str = ft_strjoin_free(new_str, s + 2, 1);
		free(s);
	}
	return (new_str);
}
