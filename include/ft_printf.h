/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarolle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 14:25:20 by bcarolle          #+#    #+#             */
/*   Updated: 2024/03/29 02:14:19 by bcarolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

int				ft_printf(const char *str, ...);
int				ft_putpointer(void	*ptr);
unsigned int	ft_putnbr_u(unsigned int n);
int				ft_print_hexa(unsigned int n, int xORX);
int				ft_ppercent(void);
char			*ft_strdup(const char *s1);
int				nb_charac(long long int nb, int base);
int				ft_strlen(const char *s);
void			write_int(int modulo, int fd);
int				ft_putnbr_fd(int n, int fd);
int				ft_putstr_fd(char *s, int fd);
int				ft_putchar_fd(int c, int fd);
#endif
