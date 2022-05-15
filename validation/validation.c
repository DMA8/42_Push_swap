/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syolando <syolando@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 22:22:44 by syolando          #+#    #+#             */
/*   Updated: 2022/05/15 16:57:27 by syolando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../push_swap.h"

int	validate_arg(char *arg)
{
	if (not_numeric(arg) || not_int_limits(arg))
		return (0);
	return (1);
}

void	check_duplicate(char **my_args, int argc)
{
	int	i;
	int	dup_i;
	int	len_args;

	i = 0;
	if (!my_args)
		return ;
	len_args = ft_len(my_args);
	while (my_args[i])
	{
		dup_i = i + 1;
		while (dup_i < len_args)
		{
			if (is_str_equal(my_args[i], my_args[dup_i]))
			{
				free_args(my_args, argc);
				fatal();
			}
			dup_i++;
		}
		i++;
	}
}

void	validate_inputs(int argc, char **argv)
{
	int		i;
	char	**my_args;

	i = 1;
	my_args = argv;
	if (argc == 2)
	{
		my_args = ft_split(argv[1], ' ');
		i = 0;
	}
	while (my_args[i])
	{
		if (!validate_arg(my_args[i]))
		{
			free_args(my_args, argc);
			fatal();
		}
		i++;
	}
	check_duplicate(my_args, argc);
	free_args(my_args, argc);
}
