#include "push_swap.h"
#include "stdlib.h"

t_list	*new(int value)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->value = value;
	new->next = NULL;
	return (new);
}

t_list	**new_list()
{
	t_list	**new;

	new = (t_list **)malloc(sizeof(t_list *));
	if (!new)
		return (NULL);
	return (new);
}

t_list	*last(t_list *list)
{
	if (!list)
		return (NULL);
	while (list->next)
		list = list->next;
	return (list);
}

void	add_back(t_list **lst, t_list *new)
{
	t_list *test;

	if (lst)
	{
		if (*lst)
		{
			test = last(*lst);
			test->next = new;
		}
		else
			*lst = new;
	}
}

