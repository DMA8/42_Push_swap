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
	// if b empty - return
	// takes first elem of l2 and put it to the top of l1
	int first_value_b;
	t_list *ptr_frst_elem_stack_b;

	if (stacks->b == NULL)
		return;
	ptr_frst_elem_stack_b = *(stacks->b);
	first_value_b = (*stacks->b)->value;
	if ((*stacks->b)->next != NULL)
	{
		stacks->b = &((*stacks->b)->next);
		free(ptr_frst_elem_stack_b);
	}
	else
		free(*(stacks->b));
	add_front(stacks->a, new (first_value_b));
}

void pb(t_stacks *stacks)
{
	// if b empty - return
	// takes first elem of l2 and put it to the top of l1
	//t_list	*new_a_top;
	t_list	*old_b_top;
	t_list	*old_a_top;

	old_a_top = (*stacks->a);
	old_b_top = (*stacks->b);
	*(stacks->b) = old_a_top;
	stacks->a = &old_a_top->next;
	(*stacks->b)->next = old_b_top; 
	// stacks->a = &(*stacks->a)->next;

}

// void	r(t_stacks *stacks, int stack_num)
// {
// 	// get last and first elem and switch it
// 	// int		first_elem_value;
// 	// int		last_elem_value;
// 	// t_list	*last_elem_ptr;
// 	t_list		*init_top;

// 	// first_elem_value = l->value;
// 	// last_elem_ptr = l->next;
// 	// while (last_elem_ptr->next != NULL)
// 	// 	last_elem_value = last_elem_ptr->next;
// 	// last_elem_value = last_elem_ptr->value;
// 	// last_elem_ptr->value = first_elem_value;
// 	// l->value = last_elem_value;
// }

void command_handler(t_stacks *stacks, int cmd)
{
	if (cmd == SA)
		s(*stacks->a); // sa
	else if (cmd == SB)
		s(*stacks->b); // sb
	else if (cmd == SS)
		ss(*stacks->a, *stacks->b);
	else if (cmd == PA)
		pa(stacks); // pa
	else if (cmd == PB)
		pb(stacks); // pb
	// else if (cmd == 31)
	// 	r(stacks, 1);
	// else if (cmd == 32)
	// 	r(stacks, 2);
	// else if (cmd == 33)
	// 	rr(stacks);
	// else if (cmd == 41)
	// 	rr(stacks->a);
	// else if (cmd == 42)
	// 	rr(stacks->b);
	// else if (cmd == 43)
	// 	rrr(stacks->a, stacks->b);
}
