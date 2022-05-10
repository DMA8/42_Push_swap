#include "push_swap.h"
#include <stdlib.h>
#include <stdio.h>

void	nil_init(t_stacks *stacks)
{
	t_list	*stepper;

	stepper = stacks->a;
	while (stepper)
	{
		stepper->score = 0;
		stepper->forward_rr = 0;
		stepper->top_steps = 0;
		stepper = stepper->next;
	}
	
}

void	fill_init_stack(t_stacks *stacks, t_list **stack_a, int argc, char **argv)
{
	int	i;
	int	a_max;
	int	a_min;
	int	atoi_res;

	i = 1;
	atoi_res = ft_atoi(argv[0]);
	a_max = atoi_res;
	a_min = atoi_res;
	(*stack_a)->value = ft_atoi(argv[0]);
	while (i < argc - 1)
	{
		atoi_res = ft_atoi(argv[i]);
		add_back(stack_a, new(atoi_res));
		if (atoi_res > a_max)
			a_max = atoi_res;
		else if (atoi_res < a_min)
			a_min = atoi_res;
		i++;
	}
	stacks->a_min = a_min;
	stacks->a_max = a_max;
	nil_init(stacks);
}


t_stacks	*new_stacks(int argc, char **argv)
{
	t_stacks	*new;

	new = (t_stacks *)malloc(sizeof(t_stacks));
	if (!new)
		return (NULL);
	new->a = new_list();
	if (!new->a)
		return (NULL);
	fill_init_stack(new, &new->a, argc, argv);
	new->init_len = argc - 1;
	new->a_len = argc - 1;
	return (new);
}