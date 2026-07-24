/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_validator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: refernan <refernan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/17 19:54:39 by refernan          #+#    #+#             */
/*   Updated: 2026/07/17 19:54:46 by refernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_valid_number(const char *s)
{
	int	i;

	i = 0;
	if (s[i] == '-' || s[i] == '+')
		i++;
	if (s[i] == '\0')
		return (0);
	while (s[i])
	{
		if (ft_isdigit(s[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}

int	is_duplicate(t_env *env, int val)
{
	t_node	*curr;
	int		i;

	if (env->stack_a == NULL || env->size_a == 0)
		return (0);
	curr = env->stack_a;
	i = 0;
	while (i < env->size_a)
	{
		if (curr->value == val)
			return (1);
		curr = curr->next;
		i++;
	}
	return (0);
}
