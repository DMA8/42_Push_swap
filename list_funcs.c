#include "push_swap.h"
#include "stdlib.h"

int		get_len(t_list *a);

int		get_min_list_val(t_list *list)
{
	int		min;
	t_list	*stepper;

	if (!list)
		return (0);
	min = list->value;
	stepper = list;
	while(stepper->next)
	{
		if (min > stepper->value)
			min = stepper->value;
		stepper = stepper->next;
	}
	if (min > stepper->value)
		min = stepper->value;
	return (min);
}

int		get_max_list_val(t_list *list)
{
	int		max;
	t_list	*next;

	if (!list)
		return (0);
	next = list;
	max = next->value;
	while(next->next)
	{
		if (next->value > max)
			max = next->value;
		next = next->next;
	}
	if (max < next->value)
		max = next->value;
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
	if (!list->next)
		return list;
	while (list->next != NULL)
		list = list->next;
	return (list);
}
