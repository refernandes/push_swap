/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_simple.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: refernan <refernan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/18 09:14:39 by refernan          #+#    #+#             */
/*   Updated: 2026/07/28 15:13:38 by refernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_simple(t_env *env)
{
	while (env->size_a > 0)
		stack_push_smallest_to_b(env);
	while (env->size_b > 0)
		op_pa(env);
}
