/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarolle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 21:20:50 by bcarolle          #+#    #+#             */
/*   Updated: 2024/03/20 22:31:45 by bcarolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int main()
{
    char *s = "test";
    printf("%p\n", s); //Shorter the string if precision < strlen(s)
    printf("%.5s\n", s); //do nothing special

    printf("%.5g\n", 3.4253); //will print 5 DIGITS (excluding .)
    printf("%.5G\n", 3.42443); // in uppercase

    printf("%.6f\n", 10.564652146);
    printf("%.4X\n", 5465544);

}