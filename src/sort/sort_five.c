/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: refernan <refernan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/18 09:14:12 by refernan          #+#    #+#             */
/*   Updated: 2026/07/28 19:00:12 by refernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_five(t_env *env)
{
	if (env->size_a <= 3)
	{
		sort_three(env);
		return ;
	}
	while (env->size_a > 3)
		stack_push_smallest_to_b(env);
	sort_three(env);
	while (env->size_b > 0)
		op_pa(env);
}
