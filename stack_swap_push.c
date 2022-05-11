/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_swap_push.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syolando <syolando@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 22:21:04 by syolando          #+#    #+#             */
/*   Updated: 2022/05/11 22:21:42 by syolando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	s(t_list *list)
{
	int	top_value;

	if (!list || !list->nx)
		return ;
	top_value = list->val;
	list->val = list->nx->val;
	list->nx->val = top_value;
}

void	ss(t_list *list_1, t_list *list_2)
{
	s(list_1);
	s(list_2);
}

void	pa(t_stacks *stacks)
{
	t_list	*next_b_init;

	if (!stacks->b)
		return ;
	next_b_init = stacks->b->nx;
	stacks->b->nx = stacks->a;
	stacks->a = stacks->b;
	stacks->b = next_b_init;
}

void	pb(t_stacks *stacks)
{
	t_list	*next_a_init;

	if (!stacks->a)
		return ;
	next_a_init = stacks->a->nx;
	stacks->a->nx = stacks->b;
	stacks->b = stacks->a;
	stacks->a = next_a_init;
	stacks->b->score = 0;
}
