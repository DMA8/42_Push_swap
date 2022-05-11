#include "push_swap.h"
#include <stdlib.h>

void	rrb(t_stacks *stacks)
{
	t_list	*last;
	t_list	*prev_last;

	if (!stacks->b)
		return ;
	last = stacks->b;
	prev_last = stacks->b;
	while (last->next)
		last = last->next;
	while (prev_last->next != last)
		prev_last = prev_last -> next;
	prev_last->next = NULL;
	last->next = stacks->b;
	stacks->b = last;
	return ;
}

void	rra(t_stacks *stacks)
{
	t_list	*last;
	t_list	*prev_last;
	
	if (!stacks->a)
			return ;
	last = stacks->a;
	prev_last = stacks->a;
	while (last->next)
		last = last->next;
	while (prev_last->next != last)
		prev_last = prev_last -> next;
	prev_last->next = NULL;
	last->next = stacks->a;
	stacks->a = last;
}

void 	rrr(t_stacks *stacks)
{
	rra(stacks);
	rrb(stacks);
}
