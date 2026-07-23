/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_radix.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: refernan <refernan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/18 09:14:22 by refernan          #+#    #+#             */
/*   Updated: 2026/07/18 09:14:22 by refernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_max_bits(int total_size)
{
	int	max_bits;
	int	max_num;

	max_bits = 0;
	max_num = total_size - 1;
	while ((max_num >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}

void	sort_radix(t_env *env)
{
	int	i;
	int	j;
	int	size;
	int	max_bits;

	max_bits = get_max_bits(env->total_size);
	i = 0;
	while (i < max_bits)
	{
		size = env->size_a;
		j = 0;
		while (j < size)
		{
			if (((env->a->index >> i) & 1) == 1)
				op_ra(env);
			else
				op_pb(env);
			j++;
		}
		while (env->size_b > 0)
			op_pa(env);
		i++;
	}
}
