/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: refernan <refernan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/17 14:47:24 by refernan          #+#    #+#             */
/*   Updated: 2026/07/17 14:47:28 by refernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	env_init(t_env *env)
{
	env->a = NULL;
	env->b = NULL;
	env->size_a = 0;
	env->size_b = 0;
	env->total_size = 0;
	env->flags.bench = 0;
	env->flags.simple = 0;
	env->flags.medium = 0;
	env->flags.complex = 0;
	env->flags.adaptive = 0;
	env->stats_ops = 0;
	env->initial_disorder = 0.0;
	env->strategy_name = "N/A";
	env->strategy_comp = "N/A";
	env->stats_sa = 0;
	env->stats_sb = 0;
	env->stats_ss = 0;
	env->stats_pa = 0;
	env->stats_pb = 0;
	env->stats_ra = 0;
	env->stats_rb = 0;
	env->stats_rr = 0;
	env->stats_rra = 0;
	env->stats_rrb = 0;
	env->stats_rrr = 0;
}
