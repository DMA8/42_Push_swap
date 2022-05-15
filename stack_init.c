/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syolando <syolando@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 22:18:28 by syolando          #+#    #+#             */
/*   Updated: 2022/05/15 16:21:45 by syolando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

void	nil_init(t_stacks *stacks)
{
	t_list	*stepper;

	stepper = stacks->a;
	while (stepper)
	{
		stepper->score = 0;
		stepper->forward_rr = 0;
		stepper->top_steps = 0;
		stepper = stepper->nx;
	}
}

void	*fill_init_stack(t_stacks *stacks, t_list **stack_a, char **argv)
{
	int	i;
	int	a_max;
	int	a_min;
	int	atoi_res;

	i = 1;
	atoi_res = ft_atoi(argv[0]);
	a_max = atoi_res;
	a_min = atoi_res;
	(*stack_a)->val = ft_atoi(argv[0]);
	while (i < ft_len(argv))
	{
		atoi_res = ft_atoi(argv[i]);
		if (!add_back(stack_a, new(atoi_res)))
			return (NULL);
		if (atoi_res > a_max)
			a_max = atoi_res;
		else if (atoi_res < a_min)
			a_min = atoi_res;
		i++;
	}
	stacks->a_min = a_min;
	stacks->a_max = a_max;
	nil_init(stacks);
	return (stacks);
}

t_stacks	*new_stacks(char **argv)
{
	t_stacks	*new;

	new = (t_stacks *)malloc(sizeof(t_stacks));
	if (!new)
		return (NULL);
	new->a = new_list();
	if (!new->a)
		return (NULL);
	if (!fill_init_stack(new, &new->a, argv))
		return (NULL);
	new->init_len = ft_len(argv);
	new->a_len = ft_len(argv);
	return (new);
}
