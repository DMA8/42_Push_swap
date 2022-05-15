/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_reverse_rotate.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syolando <syolando@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 22:19:14 by syolando          #+#    #+#             */
/*   Updated: 2022/05/12 20:34:02 by syolando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

void	rrb(t_stacks *stacks)
{
	t_list	*last;
	t_list	*prev_last;

	if (!stacks->b || !stacks->b->nx)
		return ;
	last = stacks->b;
	prev_last = stacks->b;
	while (last->nx)
		last = last->nx;
	while (prev_last->nx != last)
		prev_last = prev_last->nx;
	prev_last->nx = NULL;
	last->nx = stacks->b;
	stacks->b = last;
	return ;
}

void	rra(t_stacks *stacks)
{
	t_list	*last;
	t_list	*prev_last;

	if (!stacks->a || !stacks->a->nx)
		return ;
	last = stacks->a;
	prev_last = stacks->a;
	while (last->nx)
		last = last->nx;
	while (prev_last->nx != last)
		prev_last = prev_last->nx;
	prev_last->nx = NULL;
	last->nx = stacks->a;
	stacks->a = last;
}

void	rrr(t_stacks *stacks)
{
	rra(stacks);
	rrb(stacks);
}
