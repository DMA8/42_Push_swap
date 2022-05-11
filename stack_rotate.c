#include "push_swap.h"
#include <stdlib.h>

void	ra(t_stacks *stacks)
{
	t_list	*old_first;
	t_list	*last_elem;

	if (!stacks->a || stacks->a_min == stacks->a_max)
		return ;
	old_first = stacks->a;
	stacks->a = stacks->a->next;
	last_elem = stacks->a;
	while (last_elem->next)
		last_elem = last_elem->next;
	last_elem->next = old_first;
	old_first->next = NULL;
	return ;
}

void	rb(t_stacks *stacks)
{
	t_list	*old_first;
	t_list	*last_elem;

	if (!stacks->b || stacks->b_min == stacks->b_max)
		return ;
	old_first = stacks->b;
	stacks->b = stacks->b->next;
	last_elem = stacks->b;
	while (last_elem->next)
		last_elem = last_elem->next;
	last_elem->next = old_first;
	old_first->next = NULL;
}

void	rr(t_stacks *stacks)
{
	ra(stacks);
	rb(stacks);
}
