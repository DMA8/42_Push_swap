/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syolando <syolando@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 21:55:02 by syolando          #+#    #+#             */
/*   Updated: 2022/05/15 16:14:23 by syolando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
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
	if (stacks)
		sort(stacks);
	free_args(my_args, argc);
	free_stacks(stacks);
	exit(0);
}
