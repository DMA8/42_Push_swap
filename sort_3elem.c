#include "push_swap.h"
#include <stdio.h>

t_list	*get_min_node(t_list *a);
void	do_rotate(t_stacks *stacks);

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
		if (stacks->a->value == stacks->a_max)
			command_handler(stacks, SA);
		return ;
	}
	else if (stacks->a_len == 3)
	{
		if (stacks->a->value == stacks->a_max)
			command_handler(stacks, RA);
		if (stacks->a->next->value == stacks->a_max)
			command_handler(stacks, RRA);
		if (stacks->a->value > stacks->a->next->value)
			command_handler(stacks, SA);
	}
}

// Добавить проверку на условную отсортированность
void	sort_5(t_stacks *stacks)
{
	int	a_max_init;
	int	a_min_init;

	a_max_init = stacks->a_max;
	a_min_init = stacks->a_min;
	while (stacks->b_len < 2)
	{
		if (stacks->a->value == a_max_init || stacks->a->value == a_min_init)
			command_handler(stacks, PB);
		else
			command_handler(stacks, RA);
	}
	sort_3(stacks);
	command_handler(stacks, PA);
	command_handler(stacks, PA);
	if (stacks->a->value == stacks->a_max)
		command_handler(stacks, RA);
	else
	{
		command_handler(stacks, SA);
		command_handler(stacks, RA);
	}
}
