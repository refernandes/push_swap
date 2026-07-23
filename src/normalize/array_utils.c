/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: refernan <refernan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/17 19:56:57 by refernan          #+#    #+#             */
/*   Updated: 2026/07/17 19:56:58 by refernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*stack_to_array(t_env *env)
{
	int		*arr;
	int		i;
	t_node	*curr;

	if (env->size_a == 0)
		return (NULL);
	arr = (int *)malloc(sizeof(int) * env->size_a);
	if (!arr)
		print_error_and_exit(env);
	curr = env->a;
	i = 0;
	while (i < env->size_a)
	{
		arr[i] = curr->value;
		curr = curr->next;
		i++;
	}
	return (arr);
}
