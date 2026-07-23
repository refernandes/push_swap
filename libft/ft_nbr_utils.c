/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbr_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: refernan <refernan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/13 12:42:40 by refernan          #+#    #+#             */
/*   Updated: 2026/06/20 12:48:11 by refernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_nbr(int n)
{
	int	count;

	count = 0;
	if (n == -2147483648)
		return (print_str("-2147483648"));
	if (n < 0)
	{
		count += print_char('-');
		n = -n;
	}
	if (n >= 10)
		count += print_nbr(n / 10);
	count += print_char((n % 10) + '0');
	return (count);
}

int	print_unsigned(unsigned int n)
{
	int	count;

	count = 0;
	if (n >= 10)
		count += print_unsigned(n / 10);
	count += print_char((n % 10) + '0');
	return (count);
}

int	print_hex(unsigned long n, char spec)
{
	int		count;
	char	*base;

	if (spec == 'x' || spec == 'p')
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	count = 0;
	if (n >= 16)
		count += print_hex(n / 16, spec);
	count += print_char(base[n % 16]);
	return (count);
}

int	print_ptr(void *ptr)
{
	unsigned long	n;
	int				count;

	if (ptr == NULL)
		return (print_str("(nil)"));
	n = (unsigned long)ptr;
	count = print_str("0x");
	count += print_hex(n, 'p');
	return (count);
}
