/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: refernan <refernan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/18 09:14:48 by refernan          #+#    #+#             */
/*   Updated: 2026/07/28 17:41:14 by refernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	get_values(t_env *env, int *top, int *middle, int *bottom)
{
    *top = env->stack_a->value;
    *middle = env->stack_a->next->value;
    *bottom = env->stack_a->prev->value;
}

static void	handle_top_largest(t_env *env, int middle, int bottom)
{
	if (middle < bottom)
		op_ra(env);
	else
	{
		op_sa(env);
		op_rra(env);
	}
}

static void handle_middle_largest(t_env *env)
{
	op_sa(env);
	op_ra(env);
}

void	sort_three(t_env *env)
{
	int	top;
	int	middle;
	int	bottom;

	if (env->size_a == 2 && env->stack_a->value > env->stack_a->next->value)
	{
		op_sa(env);
		return ;
	}
	if (env->size_a != 3)
		return ;

	get_values(env, &top, &middle, &bottom);

	if (top > middle && top > bottom)
		handle_top_largest(env, middle, bottom);
	else if (top > middle && top < bottom)
		op_sa(env);
	else if (top < middle && top > bottom)
		op_rra(env);
	else if (middle > bottom)
		handle_middle_largest(env);
}
