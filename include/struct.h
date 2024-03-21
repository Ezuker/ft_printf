/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarolle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 23:10:44 by bcarolle          #+#    #+#             */
/*   Updated: 2024/03/21 13:48:28 by bcarolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

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
    FLAGS_NONE,
}           t_flags;

typedef enum e_precision_type
{
    STR, //if < strlen its gonna shorter the string
    G_SHORT, //it gonna print x DIGIT
    INTEGERS, //Will print at least x caracters IF X == 0 AND THE VALUE TO PRINT IS 0; PRINT NOTHING
    OTHER, //Number of digit to print AFTER the decimal point
    PRECISION_NONE
}           t_precision_type;

typedef struct s_precision
{
    t_precision_type    type;
    int                 value;
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
    LENGTH_NONE
}           t_length;

typedef enum e_data_type
{
    CHAR,
    STRING,
    POINTER,
    PERCENT,
    DECIMAL,
    UNSIGNED,
    OCTAL,
    HEXADECIMAL,
    HEXADECIMAL_CAPITAL,
    FLOAT,
    SCIENTIFIC,
    SCIENTIFIC_CAPITAL,
    HEXADECIMAL_FLOATING,
    HEXADECIMAL_FLOATING_CAPITAL,
    G,
    G_CAPITAL,
    NOTHING,
    NOT_VALID,
    DATA_NONE
}           t_data_type;

typedef struct s_data
{
    //minimum number to be printed
    //and the value cannot be truncated
    // if width = 0 it means %*
    // else width = value
    int             width;
    t_precision     precision;
    t_flags         flag_type;
    t_length        length_type;
    struct s_data   *next;
    t_data_type     type;
}               t_data;

#endif