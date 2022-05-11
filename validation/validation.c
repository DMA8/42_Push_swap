/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syolando <syolando@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 22:22:44 by syolando          #+#    #+#             */
/*   Updated: 2022/05/11 23:55:51 by syolando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "../push_swap.h"

int	validate_arg(char *arg)
{
	if (not_numeric(arg) || not_int_limits(arg))
		return (0);
	return (1);
}

void	validate_inputs(int argc, char **argv)
{
	int		i;
	int		duplicate_search;
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
			fatal();
		duplicate_search = i + 1;
		while (duplicate_search < ft_len(my_args))
		{
			if (is_str_equal(my_args[i], my_args[duplicate_search]))
				fatal();
			duplicate_search++;
		}
		i++;
	}
	free_args(my_args, argc);
}
