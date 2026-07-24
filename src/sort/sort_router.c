/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_router.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: refernan <refernan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/18 09:14:31 by refernan          #+#    #+#             */
/*   Updated: 2026/07/18 09:14:31 by refernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	route_small(t_env *env)
{
	env->strategy_name = "Hardcoded";
	env->strategy_comp = "O(1)";
	if (env->total_size <= 3)
		sort_three(env);
	else
		sort_five(env);
}

static void	route_adaptive(t_env *env)
{
	if (env->initial_disorder < 15.0)
	{
		env->strategy_name = "Simple";
		env->strategy_comp = "O(n^2)";
		sort_simple(env);
	}
	else if (env->initial_disorder > 85.0)
	{
		env->strategy_name = "Radix";
		env->strategy_comp = "O(n*k)";
		sort_radix(env);
	}
	else
	{
		env->strategy_name = "Chunk";
		env->strategy_comp = "O(n*sqrt(n))";
		sort_chunk(env);
	}
}

void	sort_router(t_env *env)
{
	if (env->total_size <= 5)
		route_small(env);
	else if (env->flags.simple)
	{
		env->strategy_name = "Simple";
		env->strategy_comp = "O(n^2)";
		sort_simple(env);
	}
	else if (env->flags.complex)
	{
		env->strategy_name = "Radix";
		env->strategy_comp = "O(n*k)";
		sort_radix(env);
	}
	else if (env->flags.medium)
	{
		env->strategy_name = "Chunk";
		env->strategy_comp = "O(n*sqrt(n))";
		sort_chunk(env);
	}
	else
		route_adaptive(env);
}
