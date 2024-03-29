/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wcstombs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarolle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 17:30:35 by bcarolle          #+#    #+#             */
/*   Updated: 2024/03/29 02:25:09 by bcarolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

wchar_t	*ft_wcsdup(wchar_t *s)
{
	wchar_t	*str;
	int		i;

	i = 0;
	str = (wchar_t *)malloc(sizeof(wchar_t) * (ft_wstrlen(s) + 1));
	if (!str)
		return (NULL);
	while (s[i])
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

/*convert wchar_t * to char * */
size_t	ft_wcstombs(char *s, const wchar_t *pwcs, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (i < n && pwcs[i] != L'\0')
	{
		if (pwcs[i] < 128)
		{
			s[j++] = pwcs[i];
		}
		else if (pwcs[i] < 2048)
		{
			s[j++] = 0xC0 | (pwcs[i] >> 6);
			s[j++] = 0x80 | (pwcs[i] & 0x3F);
		}
		i++;
	}
	if (j < n)
		s[j] = '\0';
	return (j);
}
