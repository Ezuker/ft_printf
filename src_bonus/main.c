/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarolle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 21:20:50 by bcarolle          #+#    #+#             */
/*   Updated: 2024/03/29 04:52:47 by bcarolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	ft_free_all(t_data *data)
{
	if (data->string)
		free(data->string);
	if (data->w_string)
		free(data->w_string);
	free(data);
}

void	root(va_list args, char *string, size_t *len)
{
	t_data	*data;

	while (*string)
	{
		if (*string == '%')
		{
			data = malloc(sizeof(t_data));
			if (!data)
				return ;
			struct_init(data);
			if (parse(data, &string, args))
				return ;
			converter(&data, args);
			*len += writer(data);
			ft_free_all(data);
		}
		else
		{
			write(1, string, 1);
			*len += 1;
			string++;
		}
	}
}

int	ft_printf(const char *s, ...)
{
	va_list	args;
	size_t	len;

	len = 0;
	va_start(args, s);
	root(args, (char *)s, &len);
	va_end(args);
	return (len);
}

// int main()
// {
// 	printf("\nprintf %d\n", printf("%016.5a", 46546.456));
// 	printf("\nftprintf %d\n", ft_printf("%016.5a", 46546.456));
// 	return (0);
// }
