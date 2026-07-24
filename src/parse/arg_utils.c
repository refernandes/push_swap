/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: refernan <refernan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/17 19:55:06 by refernan          #+#    #+#             */
/*   Updated: 2026/07/17 19:55:06 by refernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	process_arguments(t_env *env, char **args)
{
	int		j;
	int		val;
	t_node	*new_node;

	j = 0;
	while (args[j])
	{
		if (is_valid_number(args[j]) == 0 || safe_str_to_int(args[j], &val) == 0
			|| is_duplicate(env, val))
		{
			free_arguments(args);
			print_error_and_exit(env);
		}
		new_node = create_node(val);
		if (new_node == NULL)
		{
			free_arguments(args);
			print_error_and_exit(env);
		}
		append_node(&env->stack_a, new_node);
		env->size_a++;
		env->total_size++;
		j++;
	}
}

void	free_arguments(char **args)
{
	int	i;

	if (args == NULL)
		return ;
	i = 0;
	while (args[i])
	{
		free(args[i]);
		i++;
	}
	free(args);
}
