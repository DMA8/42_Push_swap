/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_checker_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syolando <syolando@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 01:18:38 by syolando          #+#    #+#             */
/*   Updated: 2022/05/12 02:04:16 by syolando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include "push_swap_bonus.h"
#include <stdlib.h>

int	main(int argc, char **argv)
{
	t_stacks	*stacks;
	char		**my_args;

	if (argc == 1)
		return (0);
	validate_inputs(argc, argv);
	if (argc == 2)
	{
		my_args = ft_split(argv[1], ' ');
		stacks = new_stacks(my_args);
	}
	else
		stacks = new_stacks(&argv[1]);
	check_instructions(stacks);
	free_args(my_args, argc);
	free_stacks(stacks);
	exit(0);
}