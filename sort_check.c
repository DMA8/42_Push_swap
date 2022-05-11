#include "push_swap.h"

int		get_len(t_list *a);

int	is_sorted_asc(t_list *a)
{
	int		a_more_b; // если отсортирован, то верх больше низа только 1 раз
	t_list	*start;

	a_more_b = 0;
	if (!a || !a->next)
		return (1);
	start = a;
	while(start->next)
	{
		if (start->value > start->next->value)
			a_more_b++;
		if (a_more_b > 1)
			return (0);
		start = start->next;
	}
	if ((a_more_b == 1 && a->value > start->value) || a_more_b == 0)
		return (1);
	return (0);
}

int	is_sorted_desc(t_list *a)
{
	int		a_less_b; // если отсортирован, то верх больше низа только 1 раз
	t_list	*start;

	a_less_b = 0;
	if (!a->next)
		return (1);
	start = a;
	while(start->next)
	{
		if (start->value < start->next->value)
			a_less_b++;
		if (a_less_b > 1)
			return (0);
		start = start->next;
	}
	if ((a_less_b == 1 && a->value < start->value) || a_less_b == 0)
		return (1);
	return (0);
}
