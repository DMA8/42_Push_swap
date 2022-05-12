/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_instructions_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syolando <syolando@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 01:22:50 by syolando          #+#    #+#             */
/*   Updated: 2022/05/12 03:03:07 by syolando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include "./gnl/get_next_line.h"

int		eq_str(char *s1, char *s2)
{
	int	s1_len;
	int	s2_len;
	int	i;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	if (s1_len != s2_len)
		return (0);
	i = 0;
	while (s1[i])
	{
		if (s1[i] != s2[i])
			return (0);
		i++;
	}
	return (1);
}

int		decode_cmd(char *cmd)
{
	if (eq_str(cmd, "sa"))
		return (SA);
	else if (eq_str(cmd, "sb"))
		return (SB);
	else if (eq_str(cmd, "ss"))
		return (SS);
	else if (eq_str(cmd, "pa"))
		return (PA);
	else if (eq_str(cmd, "pb"))
		return (PB);
	else if (eq_str(cmd, "ra"))
		return (RA);
	else if (eq_str(cmd, "rb"))
		return (RB);
	else if (eq_str(cmd, "rr"))
		return (RR);
	else if (eq_str(cmd, "rra"))
		return (RRA);
	else if (eq_str(cmd, "rrb"))
		return (RRB);
	else if (eq_str(cmd, "rrr"))
		return (RRR);
	return (0);
}

int		valid_instr(char *s)
{
	int	i;
	
	i = 0;
	i += eq_str(s, "pa") + eq_str(s, "pb");
	i += eq_str(s, "sa") + eq_str(s, "sb") + eq_str(s, "sb");
	i += eq_str(s, "ra") + eq_str(s, "rb") + eq_str(s, "rr");
	i += eq_str(s, "rra") + eq_str(s, "rrb") + eq_str(s, "rrr");
	return (i == 1);
}
char	*trim_str(char *s, char c)
{
	if (s[ft_strlen(s) - 1] == c)
		s[ft_strlen(s) - 1] = 0;
	return s;
}
void	check_instructions(t_stacks *stacks)
{
	char	*instruction;
	
	while ((instruction = get_next_line(0)))
	{
		instruction = trim_str(instruction, '\n');
		if (!valid_instr(instruction))
			fatal();
		command_handler(stacks, decode_cmd(instruction), 1);
	}
	if (is_sorted_asc(stacks->a) && stacks->a_min == stacks->a->val)
		ft_putstr("OK\n");
	else
		ft_putstr("KO\n");
}
