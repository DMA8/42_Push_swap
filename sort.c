#include "push_swap.h"
#include "stdio.h"

// assings indexes and distance to the top (quanity of ra or rra)
void	assign_indxs_a(t_stacks *stacks)
{
	t_list	*stepper;
	int		indx_c;
	int		to_top_c;

	indx_c = 0;
	to_top_c = 1;
	stepper = stacks->a;
	printf("len a before indxing %d\n", stacks->a_len);
	while (stepper->next != NULL)
	{
		stepper->indx = indx_c;
		if (indx_c <= (stacks->a_len / 2))
			stepper->top_steps = indx_c;
		else
		{
			if (stacks->a_len % 2 == 1)
				stepper->top_steps = (indx_c - to_top_c) * -1;
			else
				stepper->top_steps = (indx_c - to_top_c - 1) * -1;
			to_top_c+=2;
		}
		indx_c++;
		stepper = stepper->next;
	}
	stepper->indx = indx_c;
	if (stacks->a_len % 2 == 1)
		stepper->top_steps = (indx_c - to_top_c)* -1;
	else
		stepper->top_steps = (indx_c - to_top_c - 1) * -1;
}

// assings indexes and distance to the top (quanity of rb or rrb)
void	assign_indxs_b(t_stacks *stacks)
{
	t_list	*stepper;
	int		indx_c;
	int		to_top_c;

	indx_c = 0;
	to_top_c = 1;
	stepper = stacks->b;
	printf("len b before indxing %d\n", stacks->b_len);
	if (stacks->b_len == 2)
	{
		stepper->top_steps = 0;
		stepper->indx = 0;

		stepper->next->top_steps = 1;
		stepper->next->indx = 1;

		return ;
	}
	while (stepper->next != NULL)
	{
		stepper->indx = indx_c;
		if (indx_c <= (stacks->b_len / 2))
			stepper->top_steps = indx_c;
		else
		{
			if (stacks->b_len % 2 == 1)
				stepper->top_steps = (indx_c - to_top_c) * -1;
			else
				stepper->top_steps = (indx_c - to_top_c - 1) * -1;
			to_top_c+=2;
		}
		indx_c++;
		stepper = stepper->next;
	}
	stepper->indx = indx_c;
	if (stacks->b_len % 2 == 1)
		stepper->top_steps = (indx_c - to_top_c) * -1;
	else
		stepper->top_steps = (indx_c - to_top_c - 1) * -1;
}

int	min(int a, int b)
{
	if (a > 0 && b > 0)
	{
		if (a >= b)
			return (b);
		return (a);
	} else if (a < 0 && b < 0)
	{
		if (a >= b)
			return (-1 * b);
		return (-1 * a);
	}
	return (a);
}

// counts score by given distance to the top for each node of stacks
void	count_score(t_stacks *stacks)
{
	t_list	*stepper_a;
	t_list	*stepper_b;

	stepper_a = stacks->a;
	stepper_b = stacks->b;
	while (stepper_a->next)
	{
		if (stepper_a->value > stacks->b_max)
			stepper_a->score = stepper_a->top_steps + 1;
		else if (stepper_a->value < stacks->b_min)
			stepper_a->score = stepper_a->top_steps;
		else
		{
			while(stepper_b -> next)
			{
				// есть отрицательные и положительные скор. 
				// если знак одинков - используем двойную прокрутку rr
				// если отрицательное значение - то реверс.
				if (stepper_a->value < stepper_b->value && stepper_a->value > stepper_b->next->value)
				{
					if (stepper_a->top_steps * stepper_b->top_steps > 0) // ВНИМАНИЕ!
					{
						if (stepper_a->top_steps > 0)
							stepper_a->forward_rr = min(stepper_a->top_steps, stepper_b->top_steps);
						else
							stepper_a->reverse_rr = min(stepper_a->top_steps, stepper_b->top_steps);
						// в зависимости, кто дальше удален от топа, тот скор мы и будем добавлять
						// если топ_степс больше в стеке а, то мы из топ_степс а вычитаем совместные шаги
						// скор не изменится, он будет равен большему из топ_степс, но нам нужно сохранить число синз шагов
					}
				}
			}
		}
		stepper_a = stepper_a->next;
	}
	
}

// analysys cheapest operation
int	score(t_stacks *stacks)
{
	assign_indxs_a(stacks);
	assign_indxs_b(stacks);

	print_list(stacks->a);
	printf("next\n");
	print_list(stacks->b);
	count_score(stacks);

	return (9);
}

// sorts stacks more than 5
void	sort_big(t_stacks *stacks)
{
	command_handler(stacks, PB);
	command_handler(stacks, PB);
	if (stacks->b->value > stacks->b->next->value)
		command_handler(stacks, SB);
	printf("stacks b_max %d\n",stacks->b_max);
	printf("stacks b_min %d\n",stacks->b_min);
	score(stacks);

}

// main sort func. it launches sort algos depends on len of given stack
void	sort(t_stacks *stacks)
{
	if (is_sorted_asc(stacks->a))
		return ;
	if (stacks->init_len <= 3)
		sort_3(stacks);
	else if(stacks->init_len == 5)
		sort_5(stacks);
	else
		sort_big(stacks);
}

