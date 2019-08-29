/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call_exec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrodzin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/27 12:55:46 by agrodzin          #+#    #+#             */
/*   Updated: 2018/12/27 12:55:47 by agrodzin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	call_exec_three(t_args **stack_a, t_args **stack_b, char *choice)
{
	if (!ft_strcmp(choice, "ra"))
	{
		rot_up(stack_a);
	}
	else if (!ft_strcmp(choice, "rb"))
	{
		rot_up(stack_b);
	}
	else if (!ft_strcmp(choice, "pb"))
	{
		push_to(stack_a, stack_b);
	}
	else if (!ft_strcmp(choice, "pa"))
	{
		push_to(stack_b, stack_a);
	}
}

void	call_exec_two(t_args **stack_a, t_args **stack_b, char *choice)
{
	if (!ft_strcmp(choice, "rrr"))
	{
		rot_down(stack_a);
		rot_down(stack_b);
	}
	else if (!ft_strcmp(choice, "rra"))
	{
		rot_down(stack_a);
	}
	else if (!ft_strcmp(choice, "rrb"))
	{
		rot_down(stack_b);
	}
	else if (!ft_strcmp(choice, "rr"))
	{
		rot_up(stack_a);
		rot_up(stack_b);
	}
	else
		call_exec_three(stack_a, stack_b, choice);
}

void	call_exec(t_args **stack_a, t_args **stack_b,
char *choice, int push_check)
{
	if (push_check)
		ft_printf("%s\n", choice);
	if (!ft_strcmp(choice, "ss"))
	{
		ft_num_swap_individual(stack_a);
		ft_num_swap_individual(stack_b);
	}
	else if (!ft_strcmp(choice, "sa"))
	{
		ft_num_swap_individual(stack_a);
	}
	else if (!ft_strcmp(choice, "sb"))
	{
		ft_num_swap_individual(stack_b);
	}
	else
		call_exec_two(stack_a, stack_b, choice);
}
