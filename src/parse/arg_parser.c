/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: refernan <refernan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/17 19:53:10 by refernan          #+#    #+#             */
/*   Updated: 2026/07/17 19:53:10 by refernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	parse_flags(t_env *env, int argc, char **argv);

void	parse_input(t_env *env, int argc, char **argv)
{
	int		i;
	char	**tokens;

	i = parse_flags(env, argc, argv);
	if (i == argc)
		env_free_and_exit(env, 0);
	while (i < argc)
	{
		tokens = ft_split(argv[i], ' ');
		if (!tokens || !tokens[0])
		{
			free_tokens(tokens);
			print_error_and_exit(env);
		}
		process_tokens(env, tokens);
		free_tokens(tokens);
		i++;
	}
}

static int	parse_flags(t_env *env, int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (ft_strncmp(argv[i], "--bench", 8) == 0)
			env->flags.bench = 1;
		else if (ft_strncmp(argv[i], "--simple", 9) == 0)
			env->flags.simple = 1;
		else if (ft_strncmp(argv[i], "--medium", 9) == 0)
			env->flags.medium = 1;
		else if (ft_strncmp(argv[i], "--complex", 10) == 0)
			env->flags.complex = 1;
		else if (ft_strncmp(argv[i], "--adaptive", 11) == 0)
			env->flags.adaptive = 1;
		else
			break ;
		i++;
	}
	return (i);
}
