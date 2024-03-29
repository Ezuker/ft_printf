/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_remove_zero.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarolle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 23:35:42 by bcarolle          #+#    #+#             */
/*   Updated: 2024/03/29 01:26:14 by bcarolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

char	*remove_zero(t_data **data, char *src)
{
	int		i;
	int		j;
	char	*res;

	i = ft_strlen(src) - 1;
	j = -1;
	if ((*data)->flag_type == HASHTAG)
	{
		while (src[i] == '0')
			i--;
	}
	else
	{
		while (src[i] == '0' || src[i] == '.')
			i--;
	}
	res = malloc(sizeof(char) * i + 2);
	while (++j <= i)
		res[j] = src[j];
	res[j] = '\0';
	free(src);
	return (res);
}
