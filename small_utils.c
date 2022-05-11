#include "push_swap.h"
#include <stdlib.h>

int		mod_sum(int a, int b)
{
	if (a < 0)
		a *= -1;
	if (b < 0)
		b *= -1;
	return (a + b);
}

void	reset_stats(t_list *l)
{
	l->a_moves_top = 0;
	l->b_moves_top = 0;
	l->forward_rr = 0;
	l->reverse_rr = 0;
}

void	init(t_stacks *stacks, t_list **sa, t_list **sb)
{
	*sa = NULL;
	*sb = NULL;
	*sa = stacks->a;
	*sb = stacks->b;
}
