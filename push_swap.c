/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syolando <syolando@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 21:55:02 by syolando          #+#    #+#             */
/*   Updated: 2022/05/11 22:38:51 by syolando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "push_swap.h"
#include <stdlib.h>

void	print_list(t_list *a)
{
	if (!a)
	{
		printf("can not print empy list!\n");
		return ;
	}
	while (a->nx != NULL)
	{
		printf("val: %d indx: %d top_steps:%d score: %d\n", a->val, a->indx, a->top_steps, a->score);
		a = a->nx;
	}
	printf("val: %d indx: %d top_steps:%d score %d \n", a->val, a->indx, a->top_steps, a->score);
}

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
	sort(stacks);
	exit(0);
}
