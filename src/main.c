/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: refernan <refernan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/15 20:38:03 by refernan          #+#    #+#             */
/*   Updated: 2026/07/17 14:47:13 by refernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	record_initial_disorder(t_env *env);

int	main(int argc, char **argv)
{
	t_env	env;

	if (argc < 2)
		return (0);
	env_init(&env);
	parse_input(&env, argc, argv);
	if (env.size_a == 0)
		env_free_and_exit(&env, 0);
	record_initial_disorder(&env);
	assign_indices(&env);
	if (is_stack_sorted(env.a, env.size_a) == 0)
		sort_router(&env);
	print_benchmark(&env);
	env_free_and_exit(&env, 0);
	return (0);
}

static void	record_initial_disorder(t_env *env)
{
	int		*arr;
	double	disorder_rate;

	arr = stack_to_array(env);
	if (arr)
	{
		disorder_rate = calc_disorder(arr, env->size_a);
		env->initial_disorder = disorder_rate;
		free(arr);
	}
}
