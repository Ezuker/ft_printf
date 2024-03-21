/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarolle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 13:57:14 by bcarolle          #+#    #+#             */
/*   Updated: 2024/03/21 13:57:28 by bcarolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int get_width(char **cursor)
{
    int result;

    result = ft_atoi(*cursor);
    while (**cursor > '0' && **cursor < '9')
        (*cursor)++;
    return (result);
}