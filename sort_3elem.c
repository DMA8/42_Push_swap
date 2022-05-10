#include "push_swap.h"
#include <stdio.h>

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

void	sort_3_total(t_stacks *stacks)
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

void	sort_5(t_stacks *stacks)
{
	// Добавить проверку на условную отсортированность
	while (stacks->b_len < 2)
	{
		if (stacks->a->value == stacks->a_min || stacks->a->value == stacks->a_max)
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

