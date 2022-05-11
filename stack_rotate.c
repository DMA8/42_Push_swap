/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syolando <syolando@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 22:20:21 by syolando          #+#    #+#             */
/*   Updated: 2022/05/11 22:20:57 by syolando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

void	ra(t_stacks *stacks)
{
	t_list	*old_first;
	t_list	*last_elem;

	if (!stacks->a || stacks->a_min == stacks->a_max)
		return ;
	old_first = stacks->a;
	stacks->a = stacks->a->nx;
	last_elem = stacks->a;
	while (last_elem->nx)
		last_elem = last_elem->nx;
	last_elem->nx = old_first;
	old_first->nx = NULL;
	return ;
}

void	rb(t_stacks *stacks)
{
	t_list	*old_first;
	t_list	*last_elem;

	if (!stacks->b || stacks->b_min == stacks->b_max)
		return ;
	old_first = stacks->b;
	stacks->b = stacks->b->nx;
	last_elem = stacks->b;
	while (last_elem->nx)
		last_elem = last_elem->nx;
	last_elem->nx = old_first;
	old_first->nx = NULL;
}

void	rr(t_stacks *stacks)
{
	ra(stacks);
	rb(stacks);
}
