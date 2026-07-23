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

static void	route_adaptive(t_env *env)
{
	env->strategy_name = "Adaptive";
	if (env->initial_disorder < 0.20)
	{
		env->strategy_comp = "O(n^2)";
		sort_simple(env);
	}
	else if (env->initial_disorder >= 0.50)
	{
		env->strategy_comp = "O(n log n)";
		sort_radix(env);
	}
	else
	{
		env->strategy_comp = "O(n*sqrt(n))";
		sort_chunk(env);
	}
}

void	sort_router(t_env *env)
{
	if (env->flags.simple)
	{
		env->strategy_name = "Simple";
		env->strategy_comp = "O(n^2)";
		sort_simple(env);
	}
	else if (env->flags.medium)
	{
		env->strategy_name = "Medium";
		env->strategy_comp = "O(n*sqrt(n))";
		sort_chunk(env);
	}
	else if (env->flags.complex)
	{
		env->strategy_name = "Complex";
		env->strategy_comp = "O(n log n)";
		sort_radix(env);
	}
	else
		route_adaptive(env);
}
