/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_funcs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syolando <syolando@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 21:53:46 by syolando          #+#    #+#             */
/*   Updated: 2022/05/11 22:33:09 by syolando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "stdlib.h"

int	get_len(t_list *a);

int	get_min_list_val(t_list *list)
{
	int		min;
	t_list	*stepper;

	if (!list)
		return (0);
	min = list->val;
	stepper = list;
	while (stepper->nx)
	{
		if (min > stepper->val)
			min = stepper->val;
		stepper = stepper->nx;
	}
	if (min > stepper->val)
		min = stepper->val;
	return (min);
}

int	get_max_list_val(t_list *list)
{
	int		max;
	t_list	*next;

	if (!list)
		return (0);
	next = list;
	max = next->val;
	while (next->nx)
	{
		if (next->val > max)
			max = next->val;
		next = next->nx;
	}
	if (max < next->val)
		max = next->val;
	return (max);
}

void	update_stat(t_stacks *stacks)
{
	stacks->a_len = get_len(stacks->a);
	stacks->b_len = get_len(stacks->b);
	assign_indxs(stacks->a, stacks->a_len);
	assign_indxs(stacks->b, stacks->b_len);
	stacks->a_max = get_max_list_val(stacks->a);
	stacks->a_min = get_min_list_val(stacks->a);
	stacks->b_max = get_max_list_val(stacks->b);
	stacks->b_min = get_min_list_val(stacks->b);
}

t_list	*last(t_list *list)
{
	if (!list)
		return (NULL);
	if (!list->nx)
		return (list);
	while (list->nx != NULL)
		list = list->nx;
	return (list);
}
