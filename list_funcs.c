#include "push_swap.h"
#include "stdlib.h"
#include <stdio.h>

t_list *new (int value)
{
	t_list *new;

	new = (t_list *)malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->value = value;
	new->next = NULL;
	return (new);
}

t_list *new_list()
{
	t_list *new;

	new = (t_list *)malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->next = NULL;
	return (new);
}

int	get_min_list_val(t_list *list)
{
	int		min;
	t_list	*stepper;

	if (!list)
		return (0);
	min = list->value;
	stepper = list;
	while(stepper->next)
	{
		if (min > stepper->value)
			min = stepper->value;
		stepper = stepper->next;
	}
	if (min > stepper->value)
		min = stepper->value;
	return (min);
}

int	get_max_list_val(t_list *list)
{
	int		max;
	t_list	*next;

	if (!list)
		return (0);
	next = list;
	max = next->value;
	while(next->next)
	{
		if (next->value > max)
			max = next->value;
		next = next->next;
	}
	if (max < next->value)
		max = next->value;
	return (max);
}

int		get_len(t_list *a)
{
	int	len;

	len = 0;
	while (a)
	{
		len++;
		a = a->next;
	}
	return (len);
}

void	update_stat(t_stacks *stacks)
{
	stacks->a_len = get_len(stacks->a);
	stacks->b_len = get_len(stacks->a);
	assign_indxs(stacks->a, stacks->a_len);
	assign_indxs(stacks->b, stacks->b_len);
	stacks->a_max = get_max_list_val(stacks->a);
	stacks->a_min = get_min_list_val(stacks->a);
	stacks->b_max = get_max_list_val(stacks->b);
	stacks->b_min = get_min_list_val(stacks->b);
}

t_list *last(t_list *list)
{
	if (!list)
		return (NULL);
	if (!list->next)
		return list;
	while (list->next != NULL)
		list = list->next;
	return (list);
}

void add_back(t_list **lst, t_list *new)
{
	t_list *last_init;

	if (lst)
	{
		if (*lst)
		{
			last_init = last(*lst);
			last_init->next = new;
		}
		else
			*lst = new;
	}
	else
	{
		lst = &new;
	}
	new->next = NULL;
}

void add_front(t_list **lst, t_list *new)
{
	new->next = *lst;
	lst = &new;
}

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