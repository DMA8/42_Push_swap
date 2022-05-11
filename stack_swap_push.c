#include "push_swap.h"

void s(t_list *list)
{
	int top_value;

	if (!list || !list->next)
		return;
	top_value = list->value;
	list->value = list->next->value;
	list->next->value = top_value;
}

void ss(t_list *list_1, t_list *list_2)
{
	s(list_1);
	s(list_2);
}

void pa(t_stacks *stacks)
{
	t_list	*next_b_init;

	if (!stacks->b)
		return ;
	next_b_init = stacks->b->next;
	stacks->b->next = stacks->a;
	stacks->a = stacks->b;
	stacks->b = next_b_init;
}

void pb(t_stacks *stacks)
{
	t_list	*next_a_init;

	if (!stacks->a)
		return ;
	next_a_init = stacks->a->next;
	stacks->a->next = stacks->b;
	stacks->b = stacks->a;
	stacks->a = next_a_init;
	stacks->b->score = 0;
}
