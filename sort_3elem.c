/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3elem.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syolando <syolando@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 22:07:41 by syolando          #+#    #+#             */
/*   Updated: 2022/05/12 02:52:41 by syolando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	asc_sort(t_stacks *stacks)
{
	stacks->a_moves = get_min_node(stacks->a)->top_steps;
	do_rotate(stacks);
}

void	sort_3(t_stacks *stacks)
{
	if (stacks->a_len == 1)
		return ;
	else if (stacks->a_len == 2)
	{
		if (stacks->a->val == stacks->a_max)
			command_handler(stacks, SA, 0);
		return ;
	}
	else if (stacks->a_len == 3)
	{
		if (stacks->a->val == stacks->a_max)
			command_handler(stacks, RA, 0);
		if (stacks->a->nx->val == stacks->a_max)
			command_handler(stacks, RRA, 0);
		if (stacks->a->val > stacks->a->nx->val)
			command_handler(stacks, SA, 0);
	}
}

void	sort_5(t_stacks *stacks)
{
	int	a_max_init;
	int	a_min_init;

	a_max_init = stacks->a_max;
	a_min_init = stacks->a_min;
	while (stacks->b_len < 2)
	{
		if (stacks->a->val == a_max_init || stacks->a->val == a_min_init)
			command_handler(stacks, PB, 0);
		else
			command_handler(stacks, RA, 0);
	}
	sort_3(stacks);
	command_handler(stacks, PA, 0);
	command_handler(stacks, PA, 0);
	if (stacks->a->val == stacks->a_max)
		command_handler(stacks, RA, 0);
	else
	{
		command_handler(stacks, SA, 0);
		command_handler(stacks, RA, 0);
	}
}
