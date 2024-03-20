/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarolle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 21:25:28 by bcarolle          #+#    #+#             */
/*   Updated: 2024/03/20 22:34:07 by bcarolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdio.h>
# define NB_FLOAT_DIGIT 6

//Flags can't be mix only one. cuz Werror format
typedef enum e_flags
{
    MINUS, //Works with width subspecifier
    PLUS, //Works only with numbers
    SPACE, //put space
    //Works with o, x, X
    //Works with a, A, e, E, f, F, g, G
    HASHTAG,
    ZERO, //Leaves 0 pads
    NONE
}           t_flags;

typedef enum e_precision_type
{
    STRING, //if < strlen its gonna shorter the string
    G, //it gonna print x DIGIT
    INTEGERS, //Will print at least x caracters IF X == 0 AND THE VALUE TO PRINT IS 0; PRINT NOTHING
    OTHER, //Number of digit to print AFTER the decimal point
    NONE
}           t_precision_type;

typedef struct s_precision
{
    t_precision_type    type;
    size_t              value;
}               t_precision;

typedef enum e_length
{
    HH,
    H,
    L,
    LL,
    J,
    Z,
    T,
    BIG_L,
    NONE
}           t_length;

typedef struct s_data
{
    //minimum number to be printed
    //and the value cannot be truncated
    // if width = 0 it means %*
    // else width = value
    size_t  width;
    t_precision precision;
    t_flags flag_type;
    t_length    length_type;
}               t_data;

#endif