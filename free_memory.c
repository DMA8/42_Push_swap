/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_memory.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syolando <syolando@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 02:10:57 by syolando          #+#    #+#             */
/*   Updated: 2022/05/12 02:12:09 by syolando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

void	free_args(char **inp, int argc)
{
	int	i;

	if (argc != 2)
		return ;
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
