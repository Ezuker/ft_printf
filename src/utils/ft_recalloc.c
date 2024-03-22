/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarolle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 19:48:23 by bcarolle          #+#    #+#             */
/*   Updated: 2024/03/22 19:49:26 by bcarolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void    ft_memcpy(void *dst, const void *src, size_t n)
{
    size_t  i;

    i = 0;
    while (i < n)
    {
        ((char *)dst)[i] = ((char *)src)[i];
        i++;
    }
}

void    *ft_recalloc(void *ptr, size_t old_size, size_t new_size)
{
    void    *new_ptr;

    new_ptr = malloc(new_size);
    if (!new_ptr)
        return (NULL);
    ft_memcpy(new_ptr, ptr, old_size);
    while (old_size < new_size)
    {
        ((char *)new_ptr)[old_size] = 0;
        old_size++;
    }
    free(ptr);
    return (new_ptr);
}