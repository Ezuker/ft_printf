/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarolle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 13:57:44 by bcarolle          #+#    #+#             */
/*   Updated: 2024/03/21 13:59:54 by bcarolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_flags return_flags(char **cursor, t_flags type)
{
    (*cursor)++;
    return (type);
}

t_flags get_flags(char **cursor)
{
    if (**cursor == '-')
        return (return_flags(cursor, MINUS));
    if (**cursor == '+')
        return (return_flags(cursor, PLUS));
    if (**cursor == ' ')
        return (return_flags(cursor, SPACE));
    if (**cursor == '#')
        return (return_flags(cursor, HASHTAG));
    if (**cursor == '0')
        return (return_flags(cursor, ZERO));
    return (FLAGS_NONE);
}