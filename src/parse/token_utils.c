/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: refernan <refernan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/17 19:55:06 by refernan          #+#    #+#             */
/*   Updated: 2026/07/17 19:55:06 by refernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	process_tokens(t_env *env, char **tokens)
{
	int		j;
	int		val;
	t_node	*new_node;

	j = 0;
	while (tokens[j])
	{
		if (!is_valid_number(tokens[j]) || !safe_str_to_int(tokens[j], &val)
			|| is_duplicate(env, val))
		{
			free_tokens(tokens);
			print_error_and_exit(env);
		}
		new_node = create_node(val);
		if (!new_node)
		{
			free_tokens(tokens);
			print_error_and_exit(env);
		}
		append_node(&env->a, new_node);
		env->size_a++;
		env->total_size++;
		j++;
	}
}

void	free_tokens(char **tokens)
{
	int	i;

	if (!tokens)
		return ;
	i = 0;
	while (tokens[i])
	{
		free(tokens[i]);
		i++;
	}
	free(tokens);
}
