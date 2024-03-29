/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarolle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 23:10:44 by bcarolle          #+#    #+#             */
/*   Updated: 2024/03/29 02:28:04 by bcarolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

//Flags can't be mix only one. cuz Werror format
typedef enum e_flags
{
	MINUS,
	PLUS,
	SPACE,
	HASHTAG,
	ZERO,
	FLAGS_NONE,
}			t_flags;

typedef enum e_precision_type
{
	STR,
	INTEGERS,
	G_SHORT,
	OTHER,
	PRECISION_NONE
}			t_precision_type;

typedef struct s_precision
{
	t_precision_type	type;
	int					value;
}				t_precision;

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
}			t_length;

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
	HEXA_FLOATING,
	HEXA_FLOATING_CAPITAL,
	G,
	G_CAPITAL,
	NOTHING,
	NOT_VALID,
	DATA_NONE
}			t_data_type;

typedef enum e_bool
{
	FALSE,
	TRUE
}			t_bool;

//minimum number to be printed
//and the value cannot be truncated
// if width = 0 it means %*
// else width = value
typedef struct s_data
{
	int				width;
	t_precision		precision;
	t_flags			flag_type;
	t_length		length_type;
	char			*string;
	wchar_t			*w_string;
	size_t			len;
	t_data_type		type;
}				t_data;

#endif
