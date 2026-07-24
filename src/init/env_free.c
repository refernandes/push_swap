/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_free.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: refernan <refernan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/17 15:46:13 by refernan          #+#    #+#             */
/*   Updated: 2026/07/17 15:46:14 by refernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_error_and_exit(t_env *env)
{
	ft_putstr_fd("Error\n", 2);
	env_free_and_exit(env, 1);
}

static void	free_list(t_node *head, int size)
{
	t_node	*curr;
	t_node	*next;
	int		i;

	if (head == NULL || size == 0)
		return ;
	curr = head;
	i = 0;
	while (i < size)
	{
		next = curr->next;
		free(curr);
		curr = next;
		i++;
	}
}

void	env_free_and_exit(t_env *env, int code)
{
	if (env)
	{
		free_list(env->a, env->size_a);
		free_list(env->b, env->size_b);
	}
	exit(code);
}
