#include "push_swap.h"

void	assign_indxs(t_list *stepper, int stack_len)
{
	int		indx_c;
	int		to_top_c;

	indx_c = 0;
	to_top_c = 1;
	while (stepper)
	{
		stepper->indx = indx_c;
		if (indx_c <= (stack_len / 2))
			stepper->top_steps = indx_c;
		else
		{
			if (stack_len % 2 == 1)
				stepper->top_steps = (indx_c - to_top_c) * -1;
			else
				stepper->top_steps = (indx_c - to_top_c - 1) * -1;
			to_top_c+=2;
		}
		stepper->pos_raw = indx_c;
		indx_c++;
		stepper = stepper->next;
	}
}

void	sort_big(t_stacks *stacks)
{

}



void	sort(t_stacks *stacks)
{
	if (is_sorted_asc(stacks->a) && stacks->a_min == stacks->a->value)
		return ;
	if (stacks->init_len <= 3)
		sort_3(stacks);
	else if(stacks->init_len <= 5)
		sort_5(stacks);
	else
		sort_big(stacks);
}
