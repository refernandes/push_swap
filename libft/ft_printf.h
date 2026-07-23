/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: refernan <refernan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/12 20:47:38 by refernan          #+#    #+#             */
/*   Updated: 2026/06/20 12:25:25 by refernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int		ft_printf(const char *format, ...);
int		print_str(char *str);
int		print_char(char c);
int		print_ptr(void *ptr);
int		print_nbr(int c);
int		print_unsigned(unsigned int n);
int		print_hex(unsigned long n, char spec);
int		print_percent(void);

#endif