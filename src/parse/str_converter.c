/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_converter.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: refernan <refernan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/17 19:54:52 by refernan          #+#    #+#             */
/*   Updated: 2026/07/17 19:54:53 by refernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	safe_str_to_int(const char *s, int *out)
{
	long long	res;
	int			sign;
	int			i;

	res = 0;
	sign = 1;
	i = 0;
	if (s[i] == '-' || s[i] == '+')
	{
		if (s[i] == '-')
			sign = -1;
		i++;
	}
	while (s[i])
	{
		res = res * 10 + (s[i] - '0');
		if (sign == 1 && res > 2147483647)
			return (0);
		if (sign == -1 && (-res) < -2147483648)
			return (0);
		i++;
	}
	*out = (int)(res * sign);
	return (1);
}
