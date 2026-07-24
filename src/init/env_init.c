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
	ft_bzero(env, sizeof(t_env));
	env->strategy_name = "N/A";
	env->strategy_comp = "N/A";
}
