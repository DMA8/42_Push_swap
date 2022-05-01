#include "push_swap.h"
#include <stdlib.h>
#include <stdio.h>
/*
sa - swap a first 2 elements
sb - swap b
ss - sa and sb

pa - get top b and put it to top a
pb - get top a and put it to top b

ra - first elem goes to the end
rb
rr

rra - reverse rotate. last elem goes to the top
rrb
rrr

also need to delete first elem when pushing
rotate and swaps it is just swaps)
*/

void s(t_list *list)
{
	int top_value;
	// если элементов меньше 2х, то вызодим
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
	t_list	*old_b_top;
	t_list	*old_a_top;

	if (!stacks->b)
		return ;
	old_a_top = (stacks->a);
	old_b_top = (stacks->b);
	(stacks->a) = old_b_top;
	stacks->b = old_b_top->next;
	(stacks->a)->next = old_a_top; 
}

void pb(t_stacks *stacks)
{
	// if b empty - return
	// takes first elem of l2 and put it to the top of l1
	//t_list	*new_a_top;
	t_list	*old_b_top;
	t_list	*old_a_top;

	if (!stacks->a)
		return ;
	old_a_top = (stacks->a);
	old_b_top = (stacks->b);
	(stacks->b) = old_a_top;
	stacks->a = old_a_top->next;
	(stacks->b)->next = old_b_top; 
	// stacks->a = &(*stacks->a)->next;

}

void	rx(t_stacks *stacks, int stack_num)
{
	t_list	*old_first;
	t_list	*last_elem;

	if (stack_num == 1)
	{
		if (!stacks->a)
			return ;
		old_first = stacks->a;
		stacks->a = stacks->a->next;
		last_elem = stacks->a;
		while (last_elem->next != NULL)
			last_elem = last_elem->next;
		last_elem->next = old_first;
		old_first->next = NULL;
		return ;
	}
	if (!stacks->b || stack_num != 2)
		return ;
	old_first = stacks->b;
	stacks->b = stacks->b->next;
	last_elem = stacks->b;
	while (last_elem->next != NULL)
		last_elem = last_elem->next;
	last_elem->next = old_first;
	old_first->next = NULL;
}

void rr(t_stacks *stacks)
{
	rx(stacks, 1);
	rx(stacks, 2);
}

void	rrx(t_stacks *stacks, int stack_num)
{
	t_list	*last;
	t_list	*prev_last;

	if (stack_num == 1)
	{
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
		return ;
	}
	if (!stacks->b || stack_num != 2)
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

void rrr(t_stacks *stacks)
{
	rrx(stacks, 1);
	rrx(stacks, 2);
}

void command_handler(t_stacks *stacks, int cmd)
{
	if (cmd == SA)
		s(stacks->a); // sa
	else if (cmd == SB)
		s(stacks->b); // sb
	else if (cmd == SS)
		ss(stacks->a, stacks->b);
	else if (cmd == PA)
		pa(stacks); // pa
	else if (cmd == PB)
		pb(stacks); // pb
	else if (cmd == 31)
		rx(stacks, 1);
	else if (cmd == 32)
		rx(stacks, 2);
	else if (cmd == 33)
		rr(stacks);
	else if (cmd == 41)
		rrx(stacks, 1);
	else if (cmd == 42)
		rrx(stacks, 2);
	else if (cmd == 43)
		rrr(stacks);
}
