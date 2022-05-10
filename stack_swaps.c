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

void	rx(t_stacks *stacks, int stack_num)
{
	t_list	*old_first;
	t_list	*last_elem;
	
	if (stack_num == 1)
	{
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
	if (!stacks->b || stacks->b_min == stacks->b_max || stack_num != 2)
		return ;
	old_first = stacks->b;
	stacks->b = stacks->b->next;
	last_elem = stacks->b;
	while (last_elem->next)
		last_elem = last_elem->next;
	last_elem->next = old_first;
	old_first->next = NULL;
	// last_elem = old_first;

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

void	print_cmd(int cmd)
{
	if (cmd == SA)
		printf("%s\n", "sa");
	else if (cmd == SB)
		printf("%s\n", "sb");
	else if (cmd == SS)
		printf("%s\n", "ss");
	else if (cmd == PA)
		printf("%s\n", "pa");
	else if (cmd == PB)
		printf("%s\n", "pb");
	else if (cmd == RA)
		printf("%s\n", "ra");
	else if (cmd == RB)
		printf("%s\n", "rb");
	else if (cmd == RR)
		printf("%s\n", "rr");
	else if (cmd == RRA)
		printf("%s\n", "rra");
	else if (cmd == RRB)
		printf("%s\n", "rrb");
	else if (cmd == RRR)
		printf("%s\n", "rrr");
}

void	command_handler(t_stacks *stacks, int cmd)
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
	else if (cmd == RA)
		rx(stacks, 1);
	else if (cmd == RB)
		rx(stacks, 2);
	else if (cmd == RR)
		rr(stacks);
	else if (cmd == RRA)
		rrx(stacks, 1);
	else if (cmd == RRB)
		rrx(stacks, 2);
	else if (cmd == RRR)
		rrr(stacks);
	update_stat(stacks);
	print_cmd(cmd);
}
