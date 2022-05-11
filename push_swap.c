/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syolando <syolando@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 21:55:02 by syolando          #+#    #+#             */
/*   Updated: 2022/05/11 23:47:17 by syolando         ###   ########.fr       */
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

void	free_args(char **inp)
{
	int	i;

	i = 0;
	while (inp[i])
	{
		free(inp[i]);
		i++;
	}
	free(inp);
}

void	free_list(t_list *list)
{
	t_list	*next;

	while (list)
	{
		next = list->nx;
		free(list);
		list = next;
	}
}

void	free_stacks(t_stacks *stacks)
{
	free_list(stacks->a);
	free_list(stacks->b);
	free(stacks);
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
	if (argc == 2)
		free_args(my_args);
	free_stacks(stacks);
	exit(0);
}
