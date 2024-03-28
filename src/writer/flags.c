/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarolle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 01:12:10 by bcarolle          #+#    #+#             */
/*   Updated: 2024/03/28 01:31:28 by bcarolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*zero_flag(t_data **data, char *s)
{
	size_t	len;
	char	*str_cpy;

	len = 0;
	if ((*data)->width < (int)ft_strlen(s))
		return (s);
	if (s && *s == '-' || *s == '+' || *s == ' ')
		str_cpy = ft_substr(s, 1, ft_strlen(s) - 1);
	else
		str_cpy = ft_strdup(s);
	while (len < (*data)->width - (int)ft_strlen(s))
	{
		str_cpy = ft_strjoin_free("0", str_cpy, 2);
		len++;
	}
	if (s && *s == '-' || *s == '+' || *s == ' ')
		str_cpy = ft_strjoin_free(ft_substr(s, 0, 1), str_cpy, 3);
	free(s);
	return (str_cpy);
}
